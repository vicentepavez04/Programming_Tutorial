
// Maps

const age = new Map([
    ["Vicent", 24],
    ["Xavier", 54],
    ["Joseph", 13]
]);

age.forEach((value, key)=>console.log(`${key} is ${value} years old`));
console.log(".get: ",age.get("Vicent"));
age.set("Kathy", 27);
age.delete("Kathy")
console.log(".has :", age.has("Kathy"))
let textMaps = "";
age.forEach((value, key)=> textMaps+= `${key} is ${value} years old <br>`)

document.getElementById("maps").innerHTML = textMaps;

// objects

const car = {
    model: "Dodge",
    color: "White",
    year: "1998",
    string: " ",

    setUp: function(){
        this.string += "This is Car Object <br>"
        this.string += `model: ${this.model} <br>`;
        this.string += `color: ${this.color} <br>`;
        this.string += `year: ${this.year} <br>`;
    },
    
    drive: function(){
        console.log("You start driving");
        this.string+="You start driving"+"<br>";
    },
    stop: function(){
        console.log("You end your journey")
        this.string+="You end your journey"+"<br>";
    }

}

// as property
console.log(car.color);
//using indexer
console.log(car["color"])

car.setUp();
car.drive();
car.stop();

document.getElementById("objects").innerHTML = car.string;


// this keyword
// "this" is a reference to the object

const student = {
    name: "Vincent",
    age: "24",

    print: function(){
        console.log(`Student: ${this.name}, age: ${this.age}`)
    }
}

student.print();

// classes

//whitout a constructor

class alarm{
    sleepTime= 0;

    stop(){
        console.log("Alarm stopped");
    }
    setTime(){
        console.log("Please set time like: Year:Month:day:hour:minute");
    }
    battery(){
        console.log("please connect your alarm")
    }

}

const Lenovo = new alarm();
Lenovo.sleepTime = 5;

Lenovo.stop();
Lenovo.setTime();
Lenovo.battery();

// Class Constructor, A special method of a class, accepts arguments and assing properties
// its like the init method of python, or constructors in c++
class weapon{

    constructor(lenght, power, material, price){
        this.lenght = lenght;
        this.material = material;
        this.price = price;
        this.power = power;
        this.description = `Legth: ${lenght} cm <br> material: ${material} <br> power: ${power} <br> price: $${price} <br>`;
    }

    fire(){
        if (this.power > 1000) {
            console.log(`Wow, the gun has a lot of power (${this.power})`);
            this.description += `this.fire: Wow, the gun has a lot of power (${this.power}) <br>`;
        }else{
            console.log(`Doesn't have power (${this.power})`)
            this.description+=`this.fire: Doesn't have power (${this.power}) <br>`;
        }
        
    }
    
}

const Colt = new weapon(23, 2000, "steel", 450);
const Slingshot = new weapon(10, 50, "wood", 20);

Colt.fire();
Slingshot.fire();


document.getElementById("classes").innerHTML += "Colt: <br>"+Colt.description + "<br> Slingshot: <br>" + Slingshot.description ;


// Static = belongs to the class, not the object.

class OS{
    static numberOS = 0;
    constructor(nameOS){
        // "this" is only for the object
        this.name = nameOS;

        OS.numberOS+=1;
    }
}

const OS1 = new OS("ubuntu");
const OS2 = new OS("windows");
const OS3 = new OS("kali");
const OS4 = new OS("debian");
const OS5 = new OS("popOs");

console.log(`Number of OS created ${OS.numberOS}`)


// Inheritace

class Monster{

    dangerous = true;
    attack(){
        console.log(`This ${this.name} is attacking`)
    }
}

class Alien extends Monster{
    alive = true;
    fromThisPlanet = true;
    name = "Alien";
}
class ZombieDog extends Monster{
    alive = false;
    fromThisPlanet = false;
    mame = "Zombie Dog"
}
class Zombie extends Monster{
    alive = false;
    fromThisPlanet = false;
    name = "Zombie"
}

const zombie = new Zombie();
const zombieDog = new ZombieDog();
const alien = new Alien();

console.log(alien.dangerous);
zombie.attack();



// super : Refers to a parent class, Commonly used to invoke the constructor of a parent class

class Animal{
    constructor(name, age){
        this.name = name;
        this.age = age;
    }
}

class Fish extends Animal{
    constructor(name, age, swimSpeed){
        super(name,age);
        this.swimSpeed = swimSpeed;
    }
}
class Cat extends Animal{
    constructor(name, age, runSpeed){
        super(name,age);
        this.runSpeed = runSpeed;
    }
    
}
class Dog extends Animal{
    constructor(name, age, runSpeed){
        super(name,age);
        this.runSpeed = runSpeed;
    }
    
}

const dog = new Dog("dog", 8, 20);
const fish = new Fish("fish", 2, 36);
const cat = new Cat("cat", 5, 15);

console.log(fish.name);


// get : bind an object property (variable) to a function 
//          when that property is accesed
// set 


class User{
    constructor(username, password, height){
        this._password = password;
        this._height = height;
        this._username = username;
    }

    
    get password(){
        return this._password;
    }
    get height(){
        return `${this._height} cm`;
    }
    get username(){
        return this._username;
    }
    set username(name){
        this._username = name;
    }
}

let user1 = new User("Vincent","12345", 170);

user1.password = "2391" ;
console.log(`password:  ${user1.password}`);  //print(12345)
console.log(user1.height);
user1.username = "Xavier";
console.log(`username:  ${user1.username}`); // print(Xavier)


/*
Objects are like variables, can be stored in an array or be passed as arguments to a function.

*/