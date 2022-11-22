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
            print(len(df))

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
print(df)

###################################### initializing dash app ######################################
app = dash.Dash()   



###################################### APP LAYOUT ######################################


app.layout = html.Div([

    html.H1("Alarms", style={'text-align': 'center'}),
    dcc.Dropdown(id='dpdn1', multi=False, options=[{'label':x, 'value':x} for x in sorted(df['Fecha'].unique())]),
    html.Br(),
    dcc.Graph(id='fig3', figure={}),
    html.Br(),
    dcc.Graph(id='fig1', figure={}),
    html.Br(),
    dcc.Graph(id='fig2', figure={})

])
#, style={ 'background-color': 'white', 'color':'black'}

###################################### THE CALLBACK ######################################
@app.callback(
    Output('fig1', 'figure'),
    Output('fig2', 'figure'),
    Output('fig3', 'figure'),
    Input('dpdn1', 'value')
)
def update_graph(fechas):
    fig3 = px.histogram(df, x="Sucursal", barmode='group', color = "Fecha", title = "Conteo de alertas por Sucursal")
    dff = df[df['Fecha']== fechas]
    fig1 = px.histogram(dff, x="Sucursal", barmode='group', color = "Tipo de Alerta", title = "Tipo de Alerta por Sucursal")
    fig2 = px.histogram(dff, x="Sucursal", barmode='group', color = "Motivo Descarte", title = "Motivo de Descarte por Sucursal")


    return fig1, fig2, fig3


if __name__ == '__main__': 
    app.run_server(port=8000)
    