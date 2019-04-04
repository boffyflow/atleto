import datetime as dt
import atleto_data as ad
import atleto_util as au
import configparser

config = configparser.ConfigParser()

config.read('reports/main.cfg')

sd = dt.datetime.strptime( config['Default']['startdate'], '%Y-%m-%d')
ed = dt.datetime.strptime( config['Default']['enddate'], '%Y-%m-%d')

a = ad.atleto( config['Default']['file'], sd, ed)

#df = a.aggregate( config['Default']['aggregate'])
#print( df)

#atl.plotDistPace( df)

#runs = a.runs()

#atl.plotEasyPace( runs)

print( 'VDOT:', round( au.vdot( 10000, 2323), 1))
print( 'VDOT time:', round( au.vdotTime( 50, 10000)))
print( 'LT pace:', round( au.LTpace( 47.6)))
print( 'RRSS:', round( au.rrss( 4016, 89)))
print( 'current', a.cur_vdot( dt.datetime.today()))
#print( a.races() )
