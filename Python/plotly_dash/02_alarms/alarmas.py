import pandas as pd
import math
import os
import dash
from dash import dcc, html
from dash.dependencies import Output, Input
import plotly.express as px
import dash_bootstrap_components as dbc


def load_data_frame(folder):
    fecha = []
    for x, file in enumerate(os.listdir(folder)):
        filename = os.path.join(folder, file)
        if x == 0:
            df = pd.read_csv(filename)
        else:
            df1 = pd.read_csv(filename)
            df = df.append(df1, ignore_index=True)

    for ind in df.index:
        fecha_ = str(df['Fecha y Hora'][ind]).split(" ")[0]
        fecha.append(fecha_)
        if type(df["Motivo Descarte"][ind]) != type(""):
            if math.isnan(df["Motivo Descarte"][ind]):
                df["Motivo Descarte"][ind] = "nan"
        
        df['Sucursal'][ind] = "L"+str(df['Sucursal'][ind])        

    df["Fecha"] = fecha

    return df


df = load_data_frame(folder="./data")


###################################### initializing dash app ######################################
app = dash.Dash(external_stylesheets=[dbc.themes.DARKLY])  
app.title = 'Walmart' 



###################################### APP LAYOUT ######################################


app.layout = dbc.Container(children=[
    dbc.Row([html.H1("Alarms", style={'text-align': 'center'})]),
    html.Br(),
    #dbc.Row([html.H1("Seleccionar Mes:", style={'text-align': 'center'})]),
    dbc.Row([dcc.Graph(id='fig1', figure={})]),
    html.Br(),
    dbc.Row([html.H4("Seleccionar fecha:", style={'text-align': 'left'})]),
    dbc.Row([dcc.Dropdown(id='dpdn1', multi=False, options=[{'label':x, 'value':x} for x in sorted(df['Fecha'].unique())], style ={'color': "black",'backgroundColor': "rgba(10, 10, 10, 0.1)", 'font_color':"white"}
            )] , style ={'color': "white"}),
    html.Br(),
    dbc.Row([dcc.Graph(id='fig2', figure={})]),
    html.Br(),
    dbc.Row([dcc.Graph(id='fig3', figure={})])

])
#, style={ 'background-color': 'white', 'color':'black'}

###################################### THE CALLBACK ######################################
# Figure 1
@app.callback(
    Output('fig1', 'figure'),
    Input('dpdn1', 'value')
)
def update_graph(fechas):
    df = load_data_frame(folder="./data")
    fig = px.histogram(df, x="Sucursal", barmode='group', color = "Fecha", title = "Conteo de alertas por Sucursal")


    # style
    fig.update_layout({
                'plot_bgcolor': 'rgba(0, 0, 0, 0)',
                'paper_bgcolor': 'rgba(0, 0, 0, 0)'
                })

    fig.update_layout(
    font_family="Times New Roman",
    font_color="white",
    title_font_family="Times New Roman",
    title_font_color="white",
    legend_title_font_color="white"
    )
    fig.update_xaxes(title_font_family="Times New Roman")

    return fig

# Figure 2
@app.callback(
    Output('fig2', 'figure'),
    Input('dpdn1', 'value')
)
def update_graph(fechas):
    df = load_data_frame(folder="./data")
    dff = df[df['Fecha']== fechas]
    fig = px.histogram(dff, x="Sucursal", barmode='group', color = "Tipo de Alerta", title = "Tipo de Alerta por Sucursal")

    # style
    fig.update_layout({
                'plot_bgcolor': 'rgba(0, 0, 0, 0)',
                'paper_bgcolor': 'rgba(0, 0, 0, 0)'
                })

    fig.update_layout(
    font_family="Times New Roman",
    font_color="white",
    title_font_family="Times New Roman",
    title_font_color="white",
    legend_title_font_color="white"
    )
    fig.update_xaxes(title_font_family="Times New Roman")
    
    return fig

# figure 3
@app.callback(
    Output('fig3', 'figure'),
    Input('dpdn1', 'value')
)
def update_graph(fechas):
    df = load_data_frame(folder="./data")
    dff = df[df['Fecha']== fechas]
    fig = px.histogram(dff, x="Sucursal", barmode='group', color = "Motivo Descarte", title = "Motivo de Descarte por Sucursal")

    # style
    fig.update_layout({
                'plot_bgcolor': 'rgba(0, 0, 0, 0)',
                'paper_bgcolor': 'rgba(0, 0, 0, 0)'
                })

    fig.update_layout(
    font_family="Times New Roman",
    font_color="white",
    title_font_family="Times New Roman",
    title_font_color="white",
    legend_title_font_color="white"
    )
    fig.update_xaxes(title_font_family="Times New Roman")

    return fig

@app.callback(
    Output('dpdn1', 'options'),
    Input('dpdn1', 'value')
)
def update_graph(fechas):
    df = load_data_frame(folder="./data")
    return [{'label':x, 'value':x} for x in sorted(df['Fecha'].unique())]

if __name__ == '__main__': 
    app.run_server(port=8000)
    