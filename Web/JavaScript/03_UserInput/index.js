
let username = "john";
let count=0;

function printText(){
    username = document.getElementById("myText").value;
    document.getElementById("myLabel").innerHTML = "Thanks " + username;
}
function addition(){
    count +=1;
    document.getElementById("numberResult").innerHTML = count;
}
function subtraction(){
    count -=1;
    document.getElementById("numberResult").innerHTML = count;
}


// Enter your name
document.getElementById("myButton").onclick = function(){
    printText();
}

document.getElementById("+").onclick = function(){
    addition();
}
document.getElementById("-").onclick = function(){
    subtraction();
}
    
