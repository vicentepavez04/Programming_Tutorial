import pandas as pd
import math
import os
import dash
from dash import dcc, html
from dash.dependencies import Output, Input
import plotly.express as px
import dash_bootstrap_components as dbc
from datetime import date
from datetime import datetime as dt

def figure_layout_A(fig):
    fig.update_layout({
        'plot_bgcolor': 'rgba(0, 0, 0, 0)',
        'paper_bgcolor': 'rgba(0, 0, 0, 0)',
        'font_family':"Times New Roman",
        'font_color':"white",
        'title_font_family':"Times New Roman",
        'title_font_color':"white",
        'legend_title_font_color':"white",
        'title_font_family':"Times New Roman"
                })
    return fig


def load_data_frame(folder):
    fecha = []
    month = []
    year = []
    lat = []
    lon = []

    for x, file in enumerate(os.listdir(folder)):
        filename = os.path.join(folder, file)
        if x == 0:
            df = pd.read_csv(filename)
        else:
            df1 = pd.read_csv(filename)
            df = df.append(df1, ignore_index=True)

    for ind in df.index:
        fecha_ = str(df['Fecha y Hora'][ind]).split(" ")[0]
        month_ = str(fecha_.split("-")[1]) 
        year_ = str(fecha_.split("-")[0]) 
        fecha.append(fecha_)
        month.append(int(month_))
        year.append(int(year_))



        if type(df["Motivo Descarte"][ind]) != type(""):
            if math.isnan(df["Motivo Descarte"][ind]):
                df["Motivo Descarte"][ind] = "nan"

        
        df['Sucursal'][ind] = "L"+str(df['Sucursal'][ind]) 

##############################################
        # Ejemplo de longitudes
        # Ñuñoa Latitud: -33.4583, Longitud: -70.6 33
        if df['Sucursal'][ind] == "L3":
            lat.append(-33.4583)
            lon.append(-70.633)
            
        elif df['Sucursal'][ind] == "L95":
            lat.append(-33.45)
            lon.append(-70.6333)
        else:
            lat.append(-33.5833 )
            lon.append(-70.55)       
    df["Fecha"] = fecha
    df["date"] = pd.to_datetime(fecha)
    
    

    df["lat"] = lat
    df["lon"] = lon
#######################################

    df["Month"] = month
    df["Year"] = year
    df['sucursal_month_count'] = df.groupby(['Sucursal', 'Month'])['Sucursal'].transform('count')
    df['sucursal_date_count'] = df.groupby(['Sucursal', 'date'])['Sucursal'].transform('count')


    

    #print(df)
    return df


df = load_data_frame(folder="./data")


###################################### initializing dash app ######################################
app = dash.Dash(__name__,external_stylesheets=[dbc.themes.DARKLY])  
app.title = 'Deepview-Walmart' 



###################################### APP LAYOUT ######################################


app.layout = html.Div(style = {
        'background-image': 'url("/assets/dark.webp")',
        'background-repeat': 'no-repeat',
        'background-position': 'center',
        'height': '100%',
        'background-size': 'cover',
        'padding-top': '50px',
        'padding-right': '30px',
        'padding-bottom': '50px',
        'padding-left': '30px',
        },children=[
    dbc.Row([dbc.Col(
            html.Img(
            src = 'assets/logo_deepview2.png',
            alt='image',
            style={
                'height' : 'auto',
                'width' : '222px',
                'display': 'block',
                'margin-left': '0',
                'margin-right': 'auto',
                'margin-top': '0'
            })
        ,width=3),
        dbc.Col()
        ,
        dbc.Col(
            html.Img(
            src = 'assets/logo_walmart.png',
            alt='image',
            style={
                'height' : 'auto',
                'width' : '222px',
                'display': 'block',
                'margin-left': 'auto',
                'margin-right': '0',
                'margin-top': '10px'
            }),
        width=3) 
        ], className='titulo'),
    ##
    ##  Title and logos
    ##
    dbc.Row([
         html.H1("Resumen Alarmas", 
            style={
                'text-align': 'center',
                'vertical-align': 'middle',
                }) 
    ], className='titulo'),


    ##
    ##  Content and graphs
    ##
    html.Br(),
    html.Br(),
    html.Br(),

    dbc.Row([dcc.DatePickerRange(
            id='my-date-picker-range',  # ID to be used for callback
            calendar_orientation='horizontal',  # vertical or horizontal
            day_size=39,  # size of calendar image. Default is 39
            end_date_placeholder_text="Return",  # text that appears when no end date chosen
            with_portal=False,  # if True calendar will open in a full screen overlay portal
            first_day_of_week=1,  # Display of calendar when open (0 = Sunday)
            reopen_calendar_on_clear=True,
            is_RTL=False,  # True or False for direction of calendar
            clearable=True,  # whether or not the user can clear the dropdown
            number_of_months_shown=1,  # number of months shown when calendar is open
            min_date_allowed=dt(2020, 1, 1),  # minimum date allowed on the DatePickerRange component
            max_date_allowed=dt.today().strftime('%Y-%m-%d'),  # maximum date allowed on the DatePickerRange component
            #initial_visible_month=dt.today().strftime('%Y-%m-%d'),  # the month initially presented when the user opens the calendar
            start_date=dt.today().strftime('%Y-%m-%d'),
            end_date=dt.today().strftime('%Y-%m-%d'),
            #display_format='MMM Do, YYYY',  # how selected dates are displayed in the DatePickerRange component.
            month_format='MMMM, YYYY',  # how calendar headers are displayed when the calendar is opened.
            minimum_nights=0,  # minimum number of days between start and end date
            persistence=True,
            persisted_props=['start_date'],
            persistence_type='session',  # session, local, or memory. Default is 'local'
            updatemode='singledate'  # singledate or bothdates. Determines when callback is triggered
            ),
            dcc.Graph(id='fig1', figure={})
            ]),

    html.Br(),

    dbc.Row([
            html.H4("Seleccionar fecha:", style={'text-align': 'left'}),
            
            dcc.Dropdown(id='dpdn1', multi=False, value=max(sorted(df['Fecha'].unique())),options=[{'label':x, 'value':x} for x in sorted(df['Fecha'].unique())], style={'width': '50%'}), 
            dcc.Graph(id='fig2', figure={}),
            dcc.Graph(id='fig3', figure={})
            ]),
    html.Br(),

    dbc.Row([
            html.H4("Seleccionar Año:", style={'text-align': 'left'}),
            dcc.Dropdown(id='dpdn2', multi=False, value = max(sorted(df['Year'].unique())), options=[{'label':x, 'value':x} for x in sorted(df['Year'].unique())], style={'width': '50%'}),
            dbc.Row([dbc.Col(dcc.Graph(id='fig4', figure={})), dbc.Col(dcc.Graph(id='fig5', figure={}))], className="row_noshadow")
    ]),
    
    html.Br(),

    dbc.Row([
            dcc.Graph(id='fig6', figure={})
    ]),

    html.Br(),

    dbc.Row([
            html.H4("Seleccionar Mes:", style={'text-align': 'left'}),
            dcc.Dropdown(id='dpdn3', multi=False, value = max(sorted(df['Month'].unique())), options=[{'label':x, 'value':x} for x in sorted(df['Month'].unique())], style={'width': '50%'}),
            dcc.Graph(id='fig7', figure={})
    ])


])






#, style={ 'background-color': 'white', 'color':'black'}

###################################### THE CALLBACK ######################################
# Figure 1 Conteo de alertas por Sucursal
@app.callback(
    Output('fig1', 'figure'),
    Input('my-date-picker-range', 'start_date'),
    Input('my-date-picker-range', 'end_date'))

def update_graph(start_date, end_date):
    df = load_data_frame(folder="./data")
    mask = (df['date'] > start_date) & (df['date'] <= end_date)
    dff = df.loc[mask]
    fig1 = px.histogram(dff, x="Sucursal", barmode='group', color = "Fecha", title = "Conteo de alertas por Sucursal")
    fig1 = figure_layout_A(fig1)

    return fig1


# Figure 2 Tipo de Alerta por Sucursal
@app.callback(
    Output('fig2', 'figure'),
    Input('dpdn1', 'value')
)
def update_graph(fechas):
    df = load_data_frame(folder="./data")
    dff = df[df['Fecha']== fechas]
    fig = px.histogram(dff, x="Sucursal", barmode='group', color = "Tipo de Alerta", title = "Tipo de Alerta por Sucursal")

    # style
    fig = figure_layout_A(fig)
    
    return fig

# figure 3 Motivo de Descarte por Sucursal
@app.callback(
    Output('fig3', 'figure'),
    Input('dpdn1', 'value')
)
def update_graph(fechas):
    df = load_data_frame(folder="./data")
    dff = df[df['Fecha']== fechas]
    fig = px.histogram(dff, x="Sucursal", barmode='group', color = "Motivo Descarte", title = "Motivo de Descarte por Sucursal")

    # style
    fig = figure_layout_A(fig)

    return fig

# figure 4 Merma Anual por Sucursal"
@app.callback(
    Output('fig4', 'figure'),
    Input('dpdn2', 'value')
)
def update_graph(Year):
    df = load_data_frame(folder="./data")
    dff = df[df['Year']== Year]
    fig = px.pie(dff, values='Merma', names='Sucursal', title = "Merma Anual por Sucursal")
    # style
    fig = figure_layout_A(fig)

    return fig

# figure 5 Merma Mensual por Sucursal
@app.callback(
    Output('fig5', 'figure'),
    Input('dpdn2', 'value')
)
def update_graph(Year):
    df = load_data_frame(folder="./data")
    dff = df[df['Year']== Year]
    fig = px.bar(dff, x="date", y="Merma", color="Sucursal", title="Merma Mensual por Sucursal")
    
    
    # style
    fig = figure_layout_A(fig)

    return fig

# figure 6  line chats with slider
@app.callback(
    Output('fig6', 'figure'),
    Input('dpdn2', 'value')
)
def update_graph(Year):
    df = load_data_frame(folder="./data")
    fig = px.line(df, x='date', y='sucursal_date_count', color="Sucursal")
    
    # style
    fig = figure_layout_A(fig)
    fig.update_xaxes(rangeslider_visible=True)

    return fig


# figure 7 MapBox
@app.callback(
    Output('fig7', 'figure'),
    Input('dpdn3', 'value')
)
def update_graph(Month):
    df = load_data_frame(folder="./data")
    dff = df[df['Month']== Month]


    fig = px.scatter_mapbox(dff, 
                            lon='lon',
                            lat='lat', 
                            zoom=11,
                            color="sucursal_month_count",
                            size = "sucursal_month_count",
                            hover_name="Sucursal",
                            width=1500,
                            height= 1000,
                            # color_continuous_scale=px.colors.cyclical.IceFire,
                            # color_continuous_scale= "temps",
                            title = "Numero de Alertas mensual por Sucursal",
                            size_max=15)

    fig.update_layout(mapbox_style="carto-darkmatter")
    #fig.update_layout(mapbox_style="open-street-map")


    """
    Identifier of base map style, some of which require a Mapbox API token to be set using plotly.express.set_mapbox_access_token(). 
    Allowed values which do not require a Mapbox API token are 'open-street-map', 'white-bg', 'carto-positron', 'carto-darkmatter', 'stamen- terrain', 'stamen-toner', 'stamen-watercolor'. 
    Allowed values which do require a Mapbox API token are 'basic', 'streets', 'outdoors', 'light', 'dark', 'satellite', 'satellite- streets'.


    color = https://plotly.com/python/builtin-colorscales/
    
    """
    
    # style
    fig = figure_layout_A(fig)

    return fig







# Actualizacion de los datos cuando cambia el Dropdown
@app.callback(
    Output('dpdn1', 'options'),
    Input('dpdn1', 'value')
)
def update_graph(fechas):
    df = load_data_frame(folder="./data")
    return [{'label':x, 'value':x} for x in sorted(df['Fecha'].unique())]

@app.callback(
    Output('dpdn2', 'options'),
    Input('dpdn2', 'value')
)
def update_graph(fechas):
    df = load_data_frame(folder="./data")
    return [{'label':x, 'value':x} for x in sorted(df['Year'].unique())]



if __name__ == '__main__': 
    app.run_server(port=8000)
    