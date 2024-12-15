import dash
import dash_bootstrap_components as dbc


app = dash.Dash(__name__)

app.layout = dbc.Container()

if __name__ == "__main__":
    app.run()
