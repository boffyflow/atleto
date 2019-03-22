import atleto as atl
import datetime as dt
import argparse
from df2gspread import df2gspread as d2g
from oauth2client.service_account import ServiceAccountCredentials
import gspread


def parse_args():

    parser = argparse.ArgumentParser(description='Simple Sphere Fitting')

    parser.add_argument('-i','--input',default='../website/atleto/data/atleto_data.atl',required=False,help='Name of the text file containing the 3D points in XYZ (required)')
    parser.add_argument('-s','--startdate',default='1900-01-01',required=False,help='Start date formatted as YYYY-MM-DD (default is 1900-01-01')
    parser.add_argument('-e','--enddate',default='today',required=False,help='End date formatted as YYYY-MM-DD (default is today')

    return parser.parse_args()


def write2sheet( df, worksheet):

    scope = ['https://spreadsheets.google.com/feeds']
    credentials = ServiceAccountCredentials.from_json_keyfile_name('./Jupyter-27d0cada520a.json', scope)
    gc = gspread.authorize(credentials)
    spreadsheet_key = '1p9s_2skvkIx1xJ0Ui7AbVW_aUMkb7ThLRehj1fyC-yg'

    d2g.upload( df, spreadsheet_key, worksheet, credentials=credentials, col_names=True, row_names=True)


def main():
    args = parse_args()

    if args.enddate == 'today':
        args.enddate = dt.datetime.today().strftime('%Y-%m-%d')

    sd = dt.datetime.strptime( args.startdate, '%Y-%m-%d')
    ed = dt.datetime.strptime( args.enddate, '%Y-%m-%d')

    a = atl.atleto( args.input, sd, ed)

    days = a.aggregate()
    weeks = a.aggregate( 'W')
    months = a.aggregate( 'M')
    years = a.aggregate( 'A')

    print( days)

    write2sheet( days, 'Days')
   # print( weeks)
    write2sheet( weeks, 'Weeks')
   # print( months)
    write2sheet( months, 'Months')
   # print( years)
    write2sheet( years, 'Years')


if __name__ == "__main__":
    main()