import datetime as dt
import atleto as atl
import configparser

config = configparser.ConfigParser()

config.read('reports/main.cfg')

sd = dt.datetime.strptime( config['Default']['startdate'], '%Y-%m-%d')
ed = dt.datetime.strptime( config['Default']['enddate'], '%Y-%m-%d')

a = atl.atleto( config['Default']['file'], sd, ed)

#days = a.aggregate( config['Default']['aggregate'])
#print( days)

runs = a.runs()

atl.plotEasyPace( runs)
