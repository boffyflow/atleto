import atleto_data as atl
import datetime as dt
import argparse
from oauth2client.service_account import ServiceAccountCredentials
import gspread
from gspread_dataframe import set_with_dataframe


def parse_args():

    parser = argparse.ArgumentParser(description='Python Atleto')

    parser.add_argument('-i','--input',default='../website/atleto/data/atleto_data.atl',required=False,help='Name of the text file containing the 3D points in XYZ (required)')
    parser.add_argument('-s','--startdate',default='1900-01-01',required=False,help='Start date formatted as YYYY-MM-DD (default is 1900-01-01')
    parser.add_argument('-e','--enddate',default='2100-01-01',required=False,help='End date formatted as YYYY-MM-DD (default is 2100-01-01')

    return parser.parse_args()


def write2sheet( df, worksheet):


    # quthorize the Google API
    scope = [
         'https://www.googleapis.com/auth/drive',
         'https://www.googleapis.com/auth/drive.file'
         ]
        
    file_name = 'client_key.json'
    creds = ServiceAccountCredentials.from_json_keyfile_name( file_name, scope)
    client = gspread.authorize( creds)

    spreadsheet = client.open( 'atleto_data')

    ws = spreadsheet.worksheet( worksheet)

#    df = df.fillna('')
    print( df)
#    ws.update( 'A2:A', df['Weight'].tolist())
    set_with_dataframe( ws, df)
#    d2g.upload( df, spreadsheet_key, worksheet, start_cell='A2', credentials=credentials,
#        clean=False, col_names=False, row_names=True) #, df_size=True)


def main():
    args = parse_args()

    sd = dt.datetime.strptime( args.startdate, '%Y-%m-%d')
    ed = dt.datetime.strptime( args.enddate, '%Y-%m-%d')

    print( 'start date:', sd)
    print( '  end date:', ed)

    a = atl.atleto( args.input, sd, ed)

    print( 'Writing Days...')
    days = a.aggregate()
    write2sheet( days, 'Days')

    print( 'Writing Weeks...')
    weeks = a.aggregate( 'W')
    write2sheet( weeks, 'Weeks')

    print( 'Writing Months...')
    months = a.aggregate( 'M')
    write2sheet( months, 'Months')

    print( 'Writing Years...')
    years = a.aggregate( 'A')
    write2sheet( years, 'Years')

    print( 'Writing Runs...')
    df = a.runs( sd, ed)
    write2sheet( df, 'Runs')

    print( '...cmpleted')

if __name__ == "__main__":
    main()