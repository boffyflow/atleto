import datetime as dt
import atleto as atl
import configparser

config = configparser.ConfigParser()

config.read('reports/main.cfg')

sd = dt.datetime.strptime( config['Default']['startdate'], '%Y-%m-%d')
ed = dt.datetime.strptime( config['Default']['enddate'], '%Y-%m-%d')

a = atl.atleto( config['Default']['file'], sd, ed)

#df = a.aggregate( config['Default']['aggregate'])
#print( df)

#atl.plotDistPace( df)

#runs = a.runs()

#atl.plotEasyPace( runs)

print( 'VDOT:', round( atl.vdot( 10000, 2323), 1))
print( 'VDOT time:', round( atl.vdotTime( 50, 10000)))
print( 'LT pace:', round( atl.LTpace( 47.6)))
print( 'RRSS:', round( atl.rrss( 4016, 89)))
