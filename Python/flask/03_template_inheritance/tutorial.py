from flask import Flask, redirect, url_for, render_template

app = Flask(__name__)


# index.html has examples of python code written inside of a HTML code


# pass <name> directly to the front end (index.html)
@app.route("/")
def home():
    return render_template("index.html")

@app.route("/new")
def user():
    return render_template("new.html")

if __name__ == "__main__":
    app.run(debug=True)