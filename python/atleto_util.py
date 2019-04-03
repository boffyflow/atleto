import numpy as np
import jdutil as jd
import datetime as dt
import math

class aveHR:
    def __init__( self):
        self.t = 0
        self.hr = 0

    def step( self, hr, t):
        if hr > 0 and t > 0:
            self.hr += hr * t
            self.t += t

    def finalize(self):
        if self.t == 0 or self.hr == 0:
            return np.nan
        
        return self.hr / self.t

def jdate( day):
    datet = jd.jd_to_datetime(day)
    return datet.strftime( '%Y-%m-%d')

def pace( t, dist):
    
    if math.isnan( t) or math.isnan( dist) or t == 0 or dist == 0:
        return np.nan

    secs = t / dist
    mins = int( math.floor( secs / 60))
    secs = secs - mins * 60
    if round(secs) > 59:
        secs = 0
        mins = mins + 1    

    timet = dt.time( 0, mins, int( round(secs)))
    return timet.strftime( '%M:%S')

# equation is based on Tom Fangrows algorithm (http://www.tomfangrow.com/jsvdot.html)

def vdot( dist, t):
    tt = t / 60.0      # convert seconds to minutes

    c = -4.6 + 0.182258 * dist / tt + 0.000104 * dist * dist / tt / tt                 # c(t) or Oxygen Cost
    i = 0.8 + 0.1894393 * math.exp( -0.012778 * tt) + 0.2989558 * math.exp( -0.1932605 * tt)     # i(t) or % VO2 Max

    return c / i


# equation is based on Tom Fangrows algorithm (http://www.tomfangrow.com/jsvdot.html)

def vdotTime( vdot, distance):

    t = distance * 0.004           # start with a reasonable guess (t is in minutes!)
    n = 0

    while True:						# start of iteration loop
        c = -4.6 + 0.182258 * distance / t + 0.000104 * distance * distance / t / t		# c(t) or Oxygen Cost
        i = 0.8 + 0.1894393 * math.exp( -0.012778*t) + 0.2989558 * math.exp( -0.1932605 * t)		# i(t) or Intensity
                    
        e = math.fabs( c - i * vdot)				# distance between curves
        dc = -0.182258 * distance / t / t - 2.0 *.000104 * distance * distance / t / t / t     # dc(t)/dt or slope of c(t) curve
        di = -0.012778 * 0.1894393 * math.exp( -0.012778*t) - 0.1932605 * 0.2989558 * math.exp( -0.1932605 * t)	#di(t)/dt or slope of i(t) curve
                      
        dt = ( c - i * vdot) / ( dc - di * vdot)		# predicted correction
        t -= dt						                    # new t value to try
        n += 1					                        # times through loop
    
        if n >= 10 or e <= 0.1:
            break

    return t * 60.0            # convert t to seconds

"""
LT Pace based on VDOT computes the LT pace for given VDOT for a duration of 60min
"""
def LTpace( vdot):

    dist1 = 2000        # LT distance for 1h is between 2 and 30 km....
    dist2 = 30000

    while True:
        dist = 0.5 * ( dist1 + dist2)
        t = vdotTime( vdot, dist)

        if t < 3601 and t > 3599:
            break

        if t < 3600:
            dist1 = dist
        else:
            dist2 = dist

    return t / ( dist * 0.001)   # in seconds


"""
rrss = (t/360000) * (( p/60 - 2/3) * p)^2

with    t = duration of lap/run in seconds
        p = pace ratio between LT pace / actual pace in percent
        LT pace is computed from average of last 3 VDOTs at 60min
"""
def rrss( t, p):
    return ( t / 360000.0) * pow( ( ( p / 60.0 - 2.0/3.0) * p), 2)