import pandas as pd
import numpy as np
import jdutil as jd
import datetime as dt
import sqlite3
import math
import matplotlib.pyplot as plt
import matplotlib.dates as dates

class aveHR:
    def __init__( self):
        self.t = 0
        self.hr = 0

    def step( self, hr, t):
        self.hr += hr * t
        self.t += t

    def finalize(self):
        return self.hr / self.t


def jdate( day):
    datet = jd.jd_to_datetime(day)
    return datet.strftime( '%Y-%m-%d')


def pace( t, dist):
    
    if math.isnan( t) or math.isnan( dist):
        return "0"

    secs = t / dist
    mins = int( math.floor( secs / 60))
    secs = secs - mins * 60
    if round(secs) > 59:
        secs = 0
        mins = mins + 1    

    timet = dt.time( 0, mins, int( round(secs)))
    return timet.strftime( '%M:%S')

class atleto:
    def __init__(self, fname):
        self.filename = fname
    
    def physicals( self, sdate, edate):
        sjulian = jd.datetime_to_jd( sdate)
        ejulian = jd.datetime_to_jd( edate)
        
        conn = sqlite3.connect( self.filename)

        querystring = 'SELECT day,weight AS Weight, bodyfat AS Bodyfat FROM Physicals WHERE day<=%s AND day >=%s' % (ejulian,sjulian)

        df = pd.read_sql_query( querystring, conn)

        for index, row in df.iterrows():
            df.at[index, 'Date'] = jdate( df.at[index,'day'])

        df = df.drop( columns=['day'])
        df['Date'] = pd.to_datetime( df['Date'])
        df['Weight'] = df['Weight'] * 0.001
        df['Bodyfat'] = df['Bodyfat'] * 0.1

        print( 'from julian date - from:', sjulian, 'to:', ejulian)
        print( 'from calendar date - from:',jd.jd_to_date( sjulian, '%Y-%m-%d'), 'to:', jd.jd_to_date( ejulian, '%Y-%m-%d'))

        return df

    def runs( self, sdate, edate):
        sjulian = jd.datetime_to_jd( sdate)
        ejulian = jd.datetime_to_jd( edate)

        conn = sqlite3.connect( self.filename)

        conn.create_function('jdate', 1, jdate)
        conn.create_function('pace', 2, pace)
        conn.create_aggregate('avehr', 2, aveHR)

        sqlite3.enable_callback_tracebacks(True) 

        querystring = 'SELECT jdate(day) AS Date,SUM(dist) AS Distance,\
                                        SUM(t) AS Time,\
                                        AVEHR(hr,t) AS Heartrate\
                                        FROM run_splits\
                                        INNER JOIN runs\
                                        ON runs.id=run_splits.run_id\
                                        WHERE day<=%s AND day>=%s\
                                        GROUP BY run_splits.run_id\
                                        ORDER BY day ASC' % (ejulian,sjulian)

        df = pd.read_sql_query( querystring, conn)
        
        df['Date'] = pd.to_datetime( df['Date'])
        df['Distance'] = df.apply( lambda row: row.Distance * 0.001, axis = 1)
        df['Pace'] = df.apply( lambda row: pace( row.Time, row.Distance), axis = 1)
        
        df = df.round({'Heartrate':0})

        return df

    def days( self, sdate, edate):
        
        phys = self.physicals( sdate, edate)
        runs = self.runs( sdate, edate)

        df = pd.merge_ordered( phys, runs, on='Date', how='left')
        df = df.set_index( 'Date')

        return df

    def weeks( self, sdate, edate):

        days = self.days( sdate, edate)

        weeks = pd.DataFrame()

        weeks['Weight'] = days.Weight.resample('W').mean()
        weeks['MinWeight'] = days.Weight.resample('W').min()
        weeks['MaxWeight'] = days.Weight.resample('W').max()
        weeks['Bodyfat'] = days.Bodyfat.resample('W').mean()
        weeks['Distance'] = days.Distance.resample('W').sum()
        weeks['Time'] = days.Time.resample('W').sum()
        weeks['Heartrate'] = days.Heartrate.resample('W').mean()
        weeks['Pace'] = weeks.apply( lambda row: pace( row.Time, row.Distance), axis = 1)
        weeks = weeks.round( {'Weight':1, 'Bodyfat':1, 'Distance':1, 'Time':0, 'Heartrate':0})

        return weeks
    
    def months( self, sdate, edate):

        days = self.days( sdate, edate)

        months = pd.DataFrame()

        months['Weight'] = days.Weight.resample('M').mean()
        months['Bodyfat'] = days.Bodyfat.resample('M').mean()
        months['Distance'] = days.Distance.resample('M').sum()
        months['Time'] = days.Time.resample('M').sum()
        months['Heartrate'] = days.Heartrate.resample('M').mean()
        months['Pace'] = months.apply( lambda row: pace( row.Time, row.Distance), axis = 1)
        months = months.round( {'Weight':1, 'Bodyfat':1, 'Distance':1, 'Time':0, 'Heartrate':0})

        return months

    def years( self, sdate, edate):

        days = self.days( sdate, edate)

        years = pd.DataFrame()

        years['Weight'] = days.Weight.resample('A').mean()
        years['Bodyfat'] = days.Bodyfat.resample('A').mean()
        years['Distance'] = days.Distance.resample('A').sum()
        years['Time'] = days.Time.resample('A').sum()
        years['Heartrate'] = days.Heartrate.resample('A').mean()
        years['Pace'] = years.apply( lambda row: pace( row.Time, row.Distance), axis = 1)
        years = years.round( {'Weight':1, 'Bodyfat':1, 'Distance':1, 'Time':0, 'Heartrate':0})

        return years


def plotEasyPace( df):
   
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
