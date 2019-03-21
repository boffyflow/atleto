import atleto as atl
import datetime as dt
import argparse


def parse_args():

    parser = argparse.ArgumentParser(description='Simple Sphere Fitting')

    parser.add_argument('-i','--input',default='../website/atleto/data/atleto_data.atl',required=False,help='Name of the text file containing the 3D points in XYZ (required)')
    parser.add_argument('-s','--startdate',default='1900-01-01',required=False,help='Start date formatted as YYYY-MM-DD (default is 1900-01-01')
    parser.add_argument('-e','--enddate',default='today',required=False,help='End date formatted as YYYYMMDD (default is today')

    return parser.parse_args()

def main():
    args = parse_args()

    a = atl.atleto( args.input)

    if args.enddate == 'today':
        args.enddate = dt.datetime.today().strftime('%Y-%m-%d')

    days = a.days( dt.datetime.strptime( args.startdate, '%Y-%m-%d'), dt.datetime.strptime( args.enddate, '%Y-%m-%d'))
    weeks = a.weeks( dt.datetime.strptime( args.startdate, '%Y-%m-%d'), dt.datetime.strptime( args.enddate, '%Y-%m-%d'))
    months = a.months( dt.datetime.strptime( args.startdate, '%Y-%m-%d'), dt.datetime.strptime( args.enddate, '%Y-%m-%d'))
    years = a.years( dt.datetime.strptime( args.startdate, '%Y-%m-%d'), dt.datetime.strptime( args.enddate, '%Y-%m-%d'))

    print( weeks)
    print( months)
    print( years)


if __name__ == "__main__":
    main()