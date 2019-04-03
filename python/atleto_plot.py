import pandas as pd
import numpy as np
import jdutil as jd
import datetime as dt
import matplotlib.pyplot as plt
import matplotlib.dates as dates

def plotEasyPace( df, minHR=130, maxHR=140):
   
    df['Pace'] = pd.to_datetime( df['Pace'], format='%M:%S')

    # filter out by distance and heartrate
    df = df[(df['Distance'] <= 10.0) &
            (df['Distance'] >= 5.0) &
            (round(df['Heartrate']) <= maxHR) &
            (round(df['Heartrate']) >= minHR)]

    print( 'Min HR:', minHR)
    print( 'Max HR:', maxHR)

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
    plt.scatter( x, y, s=20)

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

def plotDistPace( df):

    df['Pace'] = pd.to_datetime( df['Pace'], format='%M:%S')

    # Initialize Figure and Axes object
    # Get current size
    fig_size = plt.rcParams["figure.figsize"]

    # Set figure dimensions (0 = width, 1 = height)
    fig_size[0] = 9
    fig_size[1] = 9
    plt.rcParams["figure.figsize"] = fig_size

    fig, ax = plt.subplots( 4, 1, sharex=True)

    x = dates.date2num( df['Date'])
    y1 = df['Distance']
    y2 = dates.date2num( df['Pace'])
    y3 = df['Weight']
    y4 = df['Heartrate']

    ax[0].xaxis.set_major_formatter( dates.DateFormatter( '%Y-%m-%d'))
    ax[0].format_xdata = dates.DateFormatter( '%Y-%m-%d')

    ax[0].bar( x, y1)
    ax[0].set( ylabel='Distance [km]', title='Distance')
    ax[0].grid()

    ax[1].plot( x, y2, color='g')
    ax[1].yaxis.set_major_formatter( dates.DateFormatter( '%M:%S'))
    ax[1].format_ydata = dates.DateFormatter( '%M:%S') 
    ax[1].set( ylabel='Pace [min/km]', title='Pace')
    ax[1].grid()

    ax[2].plot( x, y3)
    ax[2].set( ylabel='Weight [kg]', title='Weight')
    ax[2].grid()

    ax[3].plot( x, y4, color='r')
    ax[3].set( ylabel='Heartrate [bpm]', title='Heartrate')
    ax[3].grid()

    plt.show()
