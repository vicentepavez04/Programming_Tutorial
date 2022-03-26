
// Primitives / Value Types

let Name  = "Vicent"        // String
let Age  = "23"             // Number
let isReal  = true          // Boolean
let secondName  = undefined // Undefined
let lastName = null         // null



/*
Reference Types:
    Objects
    Arrays
    Functions
*/ 

// Objects

let person = {
    name: "Xavier",
    age: 50
};

    // Dot notation
let objectName = person.name;
person.age = 66;

    // Bracket Notation
person['age'] = 34;

console.log(objectName);
console.log(person.age);

// Arrays
 // Array can have diferents Types
let listOfPeople = ['John', 'Nicola', 'Edison'];
listOfPeople[2] = 23.4;

console.log(listOfPeople.length);
document.getElementById("people").innerHTML = "Array: { " + listOfPeople + " }"; 



// Functions
// functions have access to globals variables 

function add(a, b){
    return a+b;
}

function mul(a, b){
    return a*b;
}

document.getElementById("sum").innerHTML = "Addition: " + add(10,6);
document.getElementById("mul").innerHTML = "Multiplication: " + mul(10,6);




