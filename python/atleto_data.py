import pandas as pd
import numpy as np
import jdutil as jd
import atleto_util as au
import datetime as dt
import sqlite3
import matplotlib.pyplot as plt
import matplotlib.dates as dates


class atleto:
    def __init__(self, fname, sdate, edate):

        self.filename = fname
        self.sdate = sdate
        self.edate = edate
        self.days = self.days()

    def physicals( self):

        sjulian = jd.datetime_to_jd( self.sdate)
        ejulian = jd.datetime_to_jd( self.edate)
        
        conn = sqlite3.connect( self.filename)

        querystring = 'SELECT day,weight AS Weight, bodyfat AS Bodyfat FROM Physicals WHERE day<=%s AND day >=%s' % (ejulian,sjulian)

        df = pd.read_sql_query( querystring, conn)

        for index, row in df.iterrows():
            df.at[index, 'Date'] = au.jdate( df.at[index,'day'])

        df = df.drop( columns=['day'])
        df['Date'] = pd.to_datetime( df['Date'])
        df['Weight'] = df['Weight'] * 0.001
        df['Bodyfat'] = df['Bodyfat'] * 0.1
        df[['Weight','Bodyfat']] = df[['Weight','Bodyfat']].replace( 0.0, np.nan)

        df = df.round( {'Weight':1, 'Bodyfat':1})

        return df

    def runs( self):

        sjulian = jd.datetime_to_jd( self.sdate)
        ejulian = jd.datetime_to_jd( self.edate)

        conn = sqlite3.connect( self.filename)

        conn.create_function('jdate', 1, au.jdate)
        conn.create_aggregate('avehr', 2, au.aveHR)

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

        druns = self.druns()

        runs = pd.merge_ordered( druns, df, on='RunID')
        runs = runs.drop( columns=['TxHR'])
        runs = runs.set_index( 'RunID')

        return runs

    def druns( self):

        sjulian = jd.datetime_to_jd( self.sdate)
        ejulian = jd.datetime_to_jd( self.edate)

        conn = sqlite3.connect( self.filename)

        conn.create_function('jdate', 1, au.jdate)
        conn.create_aggregate('avehr', 2, au.aveHR)

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
               
        df[['Time','Distance','Heartrate']] = df[['Time','Distance','Heartrate']].replace( 0, np.nan)
        df['Date'] = pd.to_datetime( df['Date'])
        df['Distance'] = df.apply( lambda row: row.Distance * 0.001, axis = 1)   
        df['Pace'] = df.apply( lambda row: au.pace( row.Time, row.Distance), axis = 1)
        df['TxHR'] = df.apply( lambda row: row.Time * row.Heartrate, axis = 1)         
        df['TxHR'] = df['TxHR'].replace( 0.0, np.nan)
        
        df = df.round( {'Distance':1, 'Time':0, 'Heartrate':0})

        return df

    def days( self):
        
        phys = self.physicals()
        runs = self.druns()

        groupedruns = runs.groupby('Date').agg( {'Distance':'sum','Time':'sum','TxHR':'sum'}).reset_index()
        groupedruns['Pace'] = groupedruns.apply( lambda row: au.pace( row.Time, row.Distance), axis = 1)
        groupedruns['Heartrate'] = groupedruns.apply( lambda row: row.TxHR / row.Time, axis = 1)
        groupedruns['Heartrate'] = groupedruns['Heartrate'].replace( 0, np.nan)
        groupedruns = groupedruns.round( { 'Heartrate':0})
        groupedruns = groupedruns.drop( columns=['TxHR'])

        df = pd.merge_ordered( phys, groupedruns, on='Date')
        #df = df.set_index( 'Date')

        return df

    def aggregate( self, agg='days'):

        days = self.days

        if agg == 'days' or agg == 'd':
            return days

        df = pd.DataFrame()

        df['Weight'] = days.Weight.resample( agg).mean()
        df['MinWeight'] = days.Weight.resample( agg).min()
        df['MaxWeight'] = days.Weight.resample( agg).max()
        df['Bodyfat'] = days.Bodyfat.resample( agg).mean()
        df['Distance'] = days.Distance.resample( agg).sum()
        df['Time'] = days.Time.resample( agg).sum()        
        df['Heartrate'] = days.Heartrate.resample( agg).mean()
        df['MaxHeartrate'] = days.Heartrate.resample( agg).max()
        cols = ['Time','Distance','Heartrate','MaxHeartrate']
        df[cols] = df[cols].replace( 0.0, np.nan)
        
        df['Pace'] = df.apply( lambda row: pace( row.Time, row.Distance), axis = 1)
        df = df.round( {'Weight':1,'MinWeight':1,'MaxWeight':1, 'Bodyfat':1,
                        'Distance':1, 'Time':0, 'Heartrate':0,'MaxHeartrate':1})

        return df

    def races( self):

        races = self.runs()

        # filter out by distance and heartrate
        return races[(races['RunType'] == 'race')]

    def cur_vdot( self, day):
        
        # find the 3 closest races based on input date


        return 99

