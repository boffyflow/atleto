import pandas as pd
import jdutil as jd
import sqlite3

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
    return datet.isoformat()

def main():

    conn = sqlite3.connect("atleto_data.atl")
    conn.create_function('jdate', 1, jdate)
    conn.create_aggregate('avehr', 2, aveHR)
    runs = pd.read_sql_query("SELECT jdate(day),SUM(dist),SUM(hr),AVEHR(hr,dist),run_id\
                                FROM run_splits\
                                INNER JOIN runs\
                                ON runs.id=run_splits.run_id\
                                GROUP BY run_splits.run_id", conn)
    print(runs.tail())

    print('testing: ' + julian2date(2458084))


if __name__ == '__main__':
    main()    