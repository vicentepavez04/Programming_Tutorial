from flask import Flask, redirect, url_for, render_template

app = Flask(__name__)


# index.html has examples of python code written inside of a HTML code


# pass <name> directly to the front end (index.html)
@app.route("/")
def home():
    return render_template("index.html", content= "")

@app.route("/<name>")
def user(name):
    return render_template("index.html", content= name, content2 = "tutorial2")

if __name__ == "__main__":
    app.run()