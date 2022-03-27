
/*
DOM = Document Object Model (API)
*/

let body = document.body;
body.style.backgroundColor  = "skyblue";

let div = document.getElementById("division");
div.style.backgroundColor = "lightblue"

let cars = document.getElementsByName("cars");
console.log(cars)

cars.forEach(car => {
    if(car.checked){
        console.log(car.value);
    }
})

//query Selector, can select (ids, classes, tag name or a attribute )

let myTitle = document.querySelector("#myTitle");
myTitle.style.backgroundColor = "grey";
myTitle.style.fontFamily = "consolas";
myTitle.style.padding = "8px";
myTitle.style.textAlign = "center";


let models = document.querySelectorAll("label");
models.forEach(model => {
    model.style.color = "red";
})


/*

ADD and CHANGE, HTML elements

*/

const nameTag = document.createElement("h3");
//nameTag.textContent = window.prompt("Enter a h3 mini title"); 
document.body.append(nameTag);

// add a row in a list

const numberList = document.querySelector("#numbers");
const newElement = document.createElement("li")
newElement.textContent = "Two";
numberList.append(newElement);


/*

Events

*/

// onclick
const myButton = document.getElementById("myButton");
myButton.onclick = matrixPrinter;

/* onload
const elementBody = document.body;
elementBody.onload = matrixPrinter;
*/

function matrixPrinter(){

    let matrixText = "";
    let r = 20;
    let c = 40;
    for(let i=0;i<r;i++){
        for(let j=0;j<c;j++){
            matrixText += "$";
        }
        matrixText += "<br>";
    }
    
    document.getElementById("money").innerHTML = matrixText;
}


const elementBox = document.getElementById("box");
const elementBox2 = document.getElementById("box2");
elementBox.onmouseover = changeRed;
elementBox.onmouseout = changeYellow;

elementBox2.onmousedown = changeRed;
elementBox2.onmouseup = changeYellow;

function changeRed(){
    this.style.backgroundColor = "red";
}
function changeYellow(){
    this.style.background = "yellow";
}



/*

AddEventListener metod, with this you can add many event handlers to one element.

.addEventListener(event, function, useCapture)

*/

const elmentBox3 = document.getElementById("box3");

elmentBox3.addEventListener("mouseover", changeGreen);
elmentBox3.addEventListener("mouseout", changePurple);

function changeGreen(){
    this.style.background = "green";
}
function changePurple(){
    this.style.background = "purple";
}

/*

Show and hide HTML elemnts

*/

const toggleButton = document.querySelector("#toggleButton");
const carImage = document.querySelector("#car");

toggleButton.addEventListener("click", () => {
    if(carImage.style.visibility == "hidden"){
        carImage.style.visibility = "visible";
    }else{
        carImage.style.visibility = "hidden"
    }
})

/*

Detect key pressed

*/

let x = 0;
let y = 0;

window.addEventListener("keydown", move);

function move(event){
    switch(event.key){
        case "ArrowRight":
            x += 5;
            carImage.style.left = x + "px";
            break;
    
        case "ArrowLeft":
            x -= 5;
            carImage.style.left = x + "px";
            break;

        case "ArrowUp":
            y -= 5;
            carImage.style.top = y + "px";
            break;        
        case "ArrowDown":
            y += 5;
            carImage.style.top = y + "px";
            break;
        default:
            break;

    }
}


/*
    Animations
*/

const dog = document.querySelector("#dog");
const startButton = document.querySelector("#startButton");

startButton.addEventListener("click", startAnimation);

function startAnimation(){
    let timerId = null;
    let x = 0;
    let y = 0;
    let degrees = 0;

    timerId = setInterval(frame, 5);

    function frame(){
        if(x >= 300 || y>=300){
            clearInterval(timerId);
        }else{
            x+=1;
            y+=1;
            degrees+=4;

            dog.style.left = x + "px";
            dog.style.top = y + "px";
            dog.style.transform = "rotateZ("+degrees+"deg)";
        }
    }
}