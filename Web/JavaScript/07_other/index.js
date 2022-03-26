
/*
Error handling


try {
    
} catch (error) {
    
}

*/



try{

    let userName = "";

    document.getElementById("enter").onclick = function(){
        userName = document.getElementById("name").value;
        console.log(userName.toUpperCase());

        if(Number(userName) > 0 || Number(userName) <= 0){
            document.getElementById("username").innerHTML = "That was a number, please enter your user name";
            throw "error: It isn't a string";
        }
        if(userName==""){
            document.getElementById("username").innerHTML = "It's empty, please enter your user name";
            throw "error: It's empty";
        }
        
        document.getElementById("username").innerHTML = "Your user name is: " + "<h3 style=\"background-color: yellow; text-align: center;\">"+userName+"</h3>";
        
    }
}catch(error){
    console.log(error);

}finally{
    // finally always executes
    console.log("finally can be used to close a opened file");
}


