from flask import Flask, redirect, url_for, render_template, request, session, flash

app = Flask(__name__)

# Secret key for sessions
app.secret_key = "awsd"

@app.route("/")
def home():
    return render_template("index.html")

@app.route('/login', methods = ["POST", "GET"])
def login():
    if request.method == "POST":
        user =  request.form["nm"]
        session["user"] = user
        return redirect(url_for("user", usr=user))
    else:
        if "user" in session:
            user = session["user"] 
            return redirect(url_for("user", usr=user))
        return render_template("login.html")

@app.route('/<usr>')
def user(usr):
    if "user" in session:
        return render_template("logged.html", user_name=usr)
    else:
        redirect(url_for("login"))
        
        
@app.route('/logout')
def logout():
    session.pop("user", None)
    return redirect(url_for("login"))


if __name__ == "__main__":
    app.run(debug=True)