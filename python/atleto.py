import pandas as pd
import jdutil as jd
from datetime import time
import sqlite3
import math

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
    
    timet = time( 0, mins, round(secs))
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

        return pd.read_sql_query("SELECT jdate(day) AS Date,SUM(dist) AS Distance,\
                                        SUM(t) AS Time,PACE(SUM(t),SUM(dist)) AS Pace,\
                                        AVEHR(hr,dist) AS Heartrate\
                                        FROM run_splits\
                                        INNER JOIN runs\
                                        ON runs.id=run_splits.run_id\
                                        GROUP BY run_splits.run_id\
                                        ORDER BY day ASC", conn)
