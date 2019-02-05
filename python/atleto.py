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
        self.tdist = 0
        self.hr = 0

    def step(self, hr, dist):
        self.hr += hr * dist
        self.tdist += dist

    def finalize(self):
        return self.hr / self.tdist

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
        
    def runs(self):
        conn = sqlite3.connect( self.filename)

        conn.create_function('jdate', 1, jdate)
        conn.create_function('pace', 2, pace)
        conn.create_aggregate('avehr', 2, aveHR)

        sqlite3.enable_callback_tracebacks(True) 

        df = pd.read_sql_query("SELECT jdate(day) AS Date,SUM(dist) AS Distance,\
                                        SUM(t) AS Time,PACE(SUM(t),SUM(dist)) AS Pace,\
                                        AVEHR(hr,dist) AS Heartrate\
                                        FROM run_splits\
                                        INNER JOIN runs\
                                        ON runs.id=run_splits.run_id\
                                        GROUP BY run_splits.run_id\
                                        ORDER BY day ASC", conn)
        
        df['Date'] = pd.to_datetime( df['Date'])
        df['Pace'] = pd.to_datetime( df['Pace'], format='%M:%S')
        
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
    
    print(y)
        
    t1 = np.amin(df['Pace'])
    print(type(t1))
    
    print(np.amin(df['Pace']))
    print(np.amax(df['Pace']))
    
    plt.ylabel('Pace')
    plt.scatter(x, y, s=20)

    # set axis ticks and labels
    ax.xaxis.set_major_formatter( dates.DateFormatter('%Y-%m-%d'))
    ax.format_xdata = dates.DateFormatter('%Y-%m-%d')
    ax.yaxis.set_major_formatter( dates.DateFormatter('%M:%S'))
    ax.format_ydata = dates.DateFormatter('%M:%S')
    
    tdelta = dates.date2num( dt.datetime(0,0,0,0,0,10))
    print('td:',tdelta)
    tdelta = 0
    ax.set_ylim( np.amin(y) - tdelta, np.amax(y) + tdelta)
    
    # trendline
    z = np.polyfit(x, y, 1)
    p = np.poly1d(z)
    plt.plot(x,p(x),"r--")

    # show plot
    plt.show()
