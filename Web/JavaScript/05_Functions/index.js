

// Functions
// functions have access to globals variables 

function matrixPrinter(r, c){

    let matrixText = "";
    for(let i=0;i<r;i++){
        for(let j=0;j<c;j++){
            matrixText += "$";
        }
        matrixText += "<br>";
    }
    return matrixText;
}



document.getElementById("printMatrix").onclick = function(){
    console.log("1");
    let rows = document.getElementById("rows").value;
    let columns = document.getElementById("columns").value;

    document.getElementById("matrix").innerHTML = matrixPrinter(rows, columns);
    
}


/*

CALCULATOR

*/


document.getElementById("9").onclick = function(){
    operation = document.getElementById("9").innerHTML;
    calculator(operation);
}
document.getElementById("8").onclick = function(){
    operation = document.getElementById("8").innerHTML;
    calculator(operation);
}

document.getElementById("7").onclick = function(){
    operation = document.getElementById("7").innerHTML;
    calculator(operation);
}

document.getElementById("6").onclick = function(){
    operation = document.getElementById("6").innerHTML;
    calculator(operation);
}

document.getElementById("5").onclick = function(){
    operation = document.getElementById("5").innerHTML;
    calculator(operation);
}

document.getElementById("4").onclick = function(){
    operation = document.getElementById("4").innerHTML;
    calculator(operation);
}
document.getElementById("3").onclick = function(){
    operation = document.getElementById("3").innerHTML;
    calculator(operation);
}
document.getElementById("2").onclick = function(){
    operation = document.getElementById("2").innerHTML;
    calculator(operation);
}
document.getElementById("1").onclick = function(){
    operation = document.getElementById("1").innerHTML;
    calculator(operation);
}
document.getElementById("0").onclick = function(){
    operation = document.getElementById("0").innerHTML;
    calculator(operation);
}
document.getElementById("=").onclick = function(){
    operation = String(document.getElementById("=").innerHTML);
    
    calculator(operation);
}
document.getElementById("+").onclick = function(){
    operation = String(document.getElementById("+").innerHTML);
    calculator(operation);
}
document.getElementById("-").onclick = function(){
    operation = String(document.getElementById("-").innerHTML);
    calculator(operation);
}
document.getElementById("*").onclick = function(){
    operation = String(document.getElementById("*").innerHTML);
    calculator(operation);
}

let result = 0;
var oper2 = "";
var oper3 = ["","",""];

function calculator(oper){

    if(oper == "=" || oper=="+" || oper == "-" || oper=="*"){

        
        document.getElementById("result").innerHTML = oper

        if(oper == "="){
            window.oper3[2] = oper2;
            switch (window.oper3[1]) {

                case "+":
                    result = Number(window.oper3[0]) + Number(window.oper3[2]);
                    console.log(result)
                    document.getElementById("result").innerHTML = result;
                    window.oper3[1] = ""
                    break;
                case "-":
                    result = Number(window.oper3[0]) - Number(window.oper3[2]);
                    console.log(result)
                    document.getElementById("result").innerHTML = result;
                    window.oper3[1] = ""
                    
                    break;
                case "*":
                    result = Number(window.oper3[0]) * Number(window.oper3[2]);
                    console.log(result)
                    document.getElementById("result").innerHTML = result;
                    window.oper3[1] = ""
                    
                    break;

                default:
                    result = 0;
                    break;
            }
            
        }else{
            window.oper3[0] = oper2;
            window.oper3[1] = oper;
        }

        window.oper2 = "";

    }else{
        window.oper2 = oper2.concat(String(oper));  //making it global
        document.getElementById("result").innerHTML = oper2;
        

    }
    

}




/*
Compact alternative for traditional functions 
Arrow function expression =>
*/ 

const greeting = (username) => {
    console.log(`hello ${username}`);

}

greeting("Vincent")

const percent = (x, y) => {
    return x/y * 100;
}
console.log(percent(50,200));

let grades = [100,50,60,80,40,12];

grades.sort((x, y) => {return y - x} );
grades.forEach((element) =>{console.log(element)})



// Nested Functions 
let userName = "Xavier";
let userInbox = 0;

/*
Inner functions are hidden outside the outer function
*/
login();

function login(){
    displayUserName();
    displayUserInbox();

    function displayUserName(){
        console.log(`Welcome ${userName}`);
    }
    function displayUserInbox(){
        console.log(`you have ${userInbox} new messages`);
    }
}
