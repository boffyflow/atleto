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
    sec = t / (dist * 0.001)
    min = math.floor( sec / 60)
    sec = sec - min * 60
    if round(sec) > 59:
        sec = 0
        min = min + 1    
    
    timet = time( 0, min, round(sec))
    return timet.strftime( '%M:%S')

def main():

    conn = sqlite3.connect("atleto_data.atl")
    conn.create_function('jdate', 1, jdate)
    conn.create_function('pace', 2, pace)
    conn.create_aggregate('avehr', 2, aveHR)

    sqlite3.enable_callback_tracebacks(True) 

    runs = pd.read_sql_query("SELECT jdate(day) AS Date,SUM(dist) AS Distance,\
                                SUM(t) AS Time,PACE(SUM(t),SUM(dist)) AS Pace,\
                                AVEHR(hr,dist) AS Heartrate,run_id AS id\
                                FROM run_splits\
                                INNER JOIN runs\
                                ON runs.id=run_splits.run_id\
                                GROUP BY run_splits.run_id\
                                ORDER BY day ASC", conn)
    print(runs.tail())

if __name__ == '__main__':
    main()    