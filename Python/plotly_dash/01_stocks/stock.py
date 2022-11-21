import dash
from dash import dcc, html
from dash.dependencies import Output, Input
import plotly.express as px
import dash_bootstrap_components as dbc
import pandas as pd
import pandas_datareader.data as web
import datetime

df = pd.read_csv("mystocks.csv")

###################################### initializing dash app ######################################
app = dash.Dash()   



###################################### APP LAYOUT ######################################




###################################### THE CALLBACK ######################################


if __name__ == '__main__': 
    app.run_server(port=8000)

#https://www.youtube.com/watch?v=0mfIK8zxUds