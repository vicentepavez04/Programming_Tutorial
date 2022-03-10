

// If and Else

let text = "value"
const listNames = ["Vincent","Xavier", "Adam", "Kathy"]


document.getElementById("enter").onclick = function(){



// if 
    text = document.getElementById("myText").value;
    if (listNames.includes(text)) {
        document.getElementById("output").innerHTML = text +" ,You are in the list.";
    }else{
        document.getElementById("output").innerHTML = "You are not in the list";
    }





// Switch
    switch (text) {
        case "Vincent":
            console.log("you are in the list");
            break;
        case "Xavier":
            console.log("you are in the list");
            break;
        case "Adam":
            console.log("you are in the list");
            break;
        case "Kathy":
            console.log("you are in the list");
            break;

        default:
            console.log("you are not in the list")
            break;
    }
    
    
}

// For Loop

const listAnimals = ["dog", "cat", "lion", "tiger", "bear", "duck", "wolf"];

document.getElementById("goAnimal").onclick = function(){
    let varAnimal = " ";



// For Of
    for (let animal of listAnimals) {
        varAnimal = varAnimal + " " + animal ;
    }
    document.getElementById("outputAnimal").innerHTML = varAnimal ;
    
    
}

const person = {name:"Vincent", secondName:"Xavier", age:23};


//for In

for (const key in person) {
    console.log(key);
    console.log(person[key]);
}


// classical for

listText =""
listOfPrices = [123,41234,3251,145,146,465,324,234,123];
for(let x = 0; x< listOfPrices.length; x++){
    listText += "$" + String(listOfPrices[x]) + "<br>";
}

document.getElementById("getPrices").onclick = function(){
    document.getElementById("prices").innerHTML = listText;

}




// While Loop




document.getElementById("goWhile").onclick = function(){
    let n=0;
    let whileText =""
    while (n<5) {    
        whileText += String(n) + " is < 5" + "<br>";
        n+=1;
    }
    document.getElementById("whileLoop").innerHTML = whileText;
}





/*
The do while loop is a variant of the while loop. 
This loop will execute the code block once, before checking if the condition is true, then it will repeat the loop as long as the condition is true.
*/

let n=0;
do {
    console.log("n == 0, but I can enter one time")
} while (n!=0);



/*
Nested Loops, with this loops you can print a matrix and make more complicated thigs :).

*/

document.getElementById("goNested").onclick = function(){
    let symbol = window.prompt("Enter a symbol");
    let columns = window.prompt("Enter the number of columns");
    let rows = window.prompt("Enter the number of rows");
    for(let x=0; x<rows; x++){

        for(let y=0; y<columns;y++){

            document.getElementById("nestedLoop").innerHTML += symbol;
        } 
        document.getElementById("nestedLoop").innerHTML += "<br>";    }
}



