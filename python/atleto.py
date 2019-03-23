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
    def __init__(self, fname, sdate, edate):

        self.filename = fname
        self.days = self.days( sdate, edate)

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

        df = df.round( {'Weight':1, 'Bodyfat':1})

        return df

    def runs( self, sdate, edate):

        sjulian = jd.datetime_to_jd( sdate)
        ejulian = jd.datetime_to_jd( edate)

        conn = sqlite3.connect( self.filename)

        conn.create_function('jdate', 1, jdate)
        conn.create_aggregate('avehr', 2, aveHR)

        sqlite3.enable_callback_tracebacks(True) 

        querystring = 'SELECT runs.id as RunID,runs.starttime as StartTime,\
                        locations.name as Location,\
                        run_types.name AS RunType,surfaces.name AS Surface,\
                        shoes.name AS Shoe,shoes.brand AS Brand\
                        FROM runs\
                        INNER JOIN locations\
                            ON locations.id=runs.location_id\
                        INNER JOIN run_types\
                            ON run_types.id=runs.runtype_id\
                        INNER JOIN surfaces\
                            ON surfaces.id=runs.surface_id\
                        INNER JOIN shoes\
                            ON shoes.id=runs.shoe_id\
                        WHERE day<=%s AND day>=%s\
                        ORDER BY day ASC' % (ejulian, sjulian)

        df = pd.read_sql_query( querystring, conn)

        druns = self.druns( sdate, edate)

        runs = pd.merge_ordered( druns, df, on='RunID')
        runs = runs.drop( columns=['TxHR'])
        runs = runs.set_index( 'RunID')

        return runs

    def druns( self, sdate, edate):

        sjulian = jd.datetime_to_jd( sdate)
        ejulian = jd.datetime_to_jd( edate)

        conn = sqlite3.connect( self.filename)

        conn.create_function('jdate', 1, jdate)
        conn.create_aggregate('avehr', 2, aveHR)

        sqlite3.enable_callback_tracebacks(True) 

        querystring = 'SELECT runs.id AS RunID,jdate(day) AS Date,SUM(dist) AS Distance,\
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
        df['TxHR'] = df.apply( lambda row: row.Time * row.Heartrate, axis = 1)
        df.loc[:,'Heartrate'].replace( 0.0, np.nan, inplace=True)
        
        df = df.round( {'Distance':1, 'Time':0, 'Heartrate':0})

        return df


    def days( self, sdate, edate):
        
        phys = self.physicals( sdate, edate)
        runs = self.druns( sdate, edate)

        groupedruns = runs.groupby('Date').agg( {'Distance':'sum','Time':'sum','TxHR':'sum'}).reset_index()
        groupedruns['Pace'] = groupedruns.apply( lambda row: pace( row.Time, row.Distance), axis = 1)
        groupedruns['Heartrate'] = groupedruns.apply( lambda row: row.TxHR / row.Time, axis = 1)
        groupedruns = groupedruns.round( { 'Heartrate':0})
        groupedruns = groupedruns.drop( columns=['TxHR'])

        df = pd.merge_ordered( phys, groupedruns, on='Date')
        df = df.set_index( 'Date')

        return df

    def aggregate( self, agg='days'):

        days = self.days

        if agg == 'days':
            return days

        df = pd.DataFrame()

        df['Weight'] = days.Weight.resample( agg).mean()
        df['MinWeight'] = days.Weight.resample( agg).min()
        df['MaxWeight'] = days.Weight.resample( agg).max()
        df['Bodyfat'] = days.Bodyfat.resample( agg).mean()
        df['Distance'] = days.Distance.resample( agg).sum()
        df['Time'] = days.Time.resample( agg).sum()
        df['Heartrate'] = days.Heartrate.resample( agg).mean()
        df['MinHeartrate'] = days.Heartrate.resample( agg).min()
        df['MaxHeartrate'] = days.Heartrate.resample( agg).max()
        df['Pace'] = df.apply( lambda row: pace( row.Time, row.Distance), axis = 1)
        df = df.round( {'Weight':1,'MinWeight':1,'MaxWeight':1, 'Bodyfat':1,
                        'Distance':1, 'Time':0, 'Heartrate':0,'MinHeartrate':0,'MaxHeartrate':1})

        return df      


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
