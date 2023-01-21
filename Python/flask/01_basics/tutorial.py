from flask import Flask, redirect, url_for

app = Flask(__name__)

@app.route("/")
def home():
    return "First Tutorial <p>from</p> <h1> Vicente Pavez </h1>"


# pass <name> to the function user
@app.route("/<name>")
def user(name):
    return f" <h1> hello {name} :) <h1>"


#how to redirect /admin to user with name Admin
@app.route("/admin")
def admin():
    return redirect(url_for("user", name="Admin "))


if __name__ == "__main__":
    app.run()