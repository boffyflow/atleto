import pandas as pd
import numpy as np
import jdutil as jd
import datetime as dt
import sqlite3
import math
import matplotlib.pyplot as plt
import matplotlib.dates as dates

class aveHR:
    def __init__(self):
        self.t = 0
        self.hr = 0

    def step(self, hr, t):
        self.hr += hr * t
        self.t += t

    def finalize(self):
        return self.hr / self.t

def jdate(day):
    datet = jd.jd_to_datetime(day)
    return datet.strftime( '%Y-%m-%d')

def pace(t, dist):
    secs = t / (dist * 0.001)
    mins = math.floor( secs / 60)
    secs = secs - mins * 60
    if round(secs) > 59:
        secs = 0
        mins = mins + 1    
    
    timet = dt.time( 0, mins, round(secs))
    return timet.strftime( '%M:%S')

class atleto:
    def __init__(self, fname):
        self.filename = fname
    
    def days( self, sdate, edate):

        sjulian = jd.datetime_to_jd( sdate)
        ejulian = jd.datetime_to_jd( edate)
        
        conn = sqlite3.connect( self.filename)

        querystring = 'SELECT day,weight AS Weight, bodyfat AS Bodyfat FROM Physicals WHERE day<=%s AND day >=%s' % (ejulian,sjulian)

        df = pd.read_sql_query( querystring, conn)

        for index, row in df.iterrows():
            df.at[index, 'Date'] = jdate( df.at[index,'day'])
        df = df.drop( columns=['day'])
        df = df.set_index( 'Date')
        df['Weight'] = df['Weight'] * 0.001
        df['Bodyfat'] = df['Bodyfat'] * 0.1

        print( 'from julian date - from:', sjulian, 'to:', ejulian)
        print( 'from calendar date - from:',jd.jd_to_date( sjulian, '%Y-%m-%d'), 'to:', jd.jd_to_date( ejulian, '%Y-%m-%d'))

        return df

    def weeks():
        return
    
    def months():
        return

    def years():
        return

    def runs(self):
        conn = sqlite3.connect( self.filename)

        conn.create_function('jdate', 1, jdate)
        conn.create_function('pace', 2, pace)
        conn.create_aggregate('avehr', 2, aveHR)

        sqlite3.enable_callback_tracebacks(True) 

        df = pd.read_sql_query("SELECT jdate(day) AS Date,SUM(dist) AS Distance,\
                                        SUM(t) AS Time,PACE(SUM(t),SUM(dist)) AS Pace,\
                                        AVEHR(hr,t) AS Heartrate\
                                        FROM run_splits\
                                        INNER JOIN runs\
                                        ON runs.id=run_splits.run_id\
                                        GROUP BY run_splits.run_id\
                                        ORDER BY day ASC", conn)
        
        df['Date'] = pd.to_datetime( df['Date'])
        df['Pace'] = pd.to_datetime( df['Pace'], format='%M:%S')
        df = df.round({'Heartrate':0})
        
        return df
    
def plotEasyPace(df):
   
    # Initialize Figure and Axes object
    # Get current size
    fig_size = plt.rcParams["figure.figsize"]

    # Set figure dimensions (0 = width, 1 = height)
    fig_size[0] = 9
    fig_size[1] = 6
    plt.rcParams["figure.figsize"] = fig_size

    fig, ax = plt.subplots()
    
    # Scatter plot
    x = dates.date2num( df['Date'])
    y = dates.date2num( df['Pace'])
                 
    plt.ylabel('Pace (min/km)')
    plt.scatter(x, y, s=20)

    # set axis ticks and labels
    ax.xaxis.set_major_formatter( dates.DateFormatter('%Y-%m-%d'))
    ax.format_xdata = dates.DateFormatter('%Y-%m-%d')
    ax.yaxis.set_major_formatter( dates.DateFormatter('%M:%S'))
    ax.format_ydata = dates.DateFormatter('%M:%S')   

    # set limits for pace axis
    bottom = dates.date2num( df['Pace'].min() - pd.Timedelta(seconds=5))
    top = dates.date2num( df['Pace'].max() + pd.Timedelta(seconds=5))
    ax.set_ylim( bottom, top)
    
    # trendline
    z = np.polyfit(x, y, 1)
    p = np.poly1d(z)
    plt.plot(x,p(x),"r--")

    # show plot
    plt.show()
