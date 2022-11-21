import dash
from dash import html
from dash import dcc
import plotly.graph_objects as go
import plotly.express as px
import pandas as pd
from dash.dependencies import Input, Output

### Example data
df = pd.read_csv("bees.csv")

###################################### initializing dash app ######################################
app = dash.Dash()   

###################################### APP LAYOUT ######################################
#### Defining the HTML component

app.layout = html.Div([

    html.H1("Web application example with Bees database", style={'text-align': 'center'}),
    dcc.Dropdown(
        id="select_year",
        options=[
            {"label": "2015", "value": 2015},
            {"label": "2016", "value": 2016},
            {"label": "2017", "value": 2017},
            {"label": "2018", "value": 2018},],
        multi=False,
        value=2015,
        style={'width':"40%"}
    ),
    html.Div(id='output_container', children=[]),
    html.Br(),
    dcc.Graph(id='bee_graph', figure={})

])


###################################### THE CALLBACK ######################################
#### Connect Plotly graphs with Dash Components

@app.callback(
    [
        Output(component_id='output_container', component_property='children'),
        Output(component_id='bee_graph', component_property='figure')
    ],
    [
        Input(component_id='select_year', component_property='value')
    ]
)

def update_graph(option_selected):
    container = "The year chosen was: {}".format(option_selected)
    dff = df.copy()
    dff = dff[dff["Year"] == option_selected]
    dff = dff[dff["Affected by"] == "Varroa_mites"]

    #Plotly Express
    fig = px.choropleth(
        data_frame=dff,
        locationmode='USA-states',
        locations='state_code',
        scope="usa",
        color='Pct of Colonies Impacted',
        hover_data=['State', 'Pct of Colonies Impacted'],
        color_continuous_scale=px.colors.sequential.YlOrRd,
        labels={'Pct of Colonies Impacted': '% of Bee Colonies'},
        template='plotly_dark'
    )

    # #Plotly Graph Objects (GO)
    # fig = go.Figure(
    #     data=[go.Choropleth(
    #         locationmode='USA-states',
    #         locations=dff['state_code'],
    #         z=dff["Pct of Colonies Impacted"].astype(float),
    #         colorscale='Reds',
    #     )]
    # )
    
    # fig.update_layout(
    #     title_text="Bees Affected by Mites in the USA",
    #     title_xanchor="center",
    #     title_font=dict(size=24),
    #     title_x=0.5,
    #     geo=dict(scope='usa'),
    # )

    return container, fig

# The function input is equal to Input callback (in this case just 1),
# The return (container and figure) is equal and in order with Ouput Callback (children and figure)



if __name__ == '__main__': 
    app.run_server(port=8000)