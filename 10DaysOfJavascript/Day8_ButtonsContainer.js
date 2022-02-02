index.html :

<!-- Enter your HTML code here -->
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Buttons Grid</title>
        <link rel="stylesheet" href="css/buttonsGrid.css" type="text/css">
    </head>
    <body>
        <div id="btns">
            <button id="btn1" class="buttonClass">1</button>
            <button id="btn2" class="buttonClass">2</button>
            <button id="btn3" class="buttonClass">3</button>
            <button id="btn4" class="buttonClass">4</button>
            <button id="btn5" class="buttonClass">5</button>
            <button id="btn6" class="buttonClass">6</button>
            <button id="btn7" class="buttonClass">7</button>
            <button id="btn8" class="buttonClass">8</button>
            <button id="btn9" class="buttonClass">9</button>
        </div>
        <script src="js/buttonsGrid.js" type="text/javascript"></script>
    </body>
</html>


buttonsGrid.css :

#btns {
    width: 75%;
}
.buttonClass {
    width: 30%;
    height: 48px;
    font-size: 24px;
}


buttonsGrid.js : 

let btn1 = document.getElementById("btn1");
let btn2 = document.getElementById("btn2");
let btn3 = document.getElementById("btn3");
let btn4 = document.getElementById("btn4");
let btn5 = document.getElementById("btn5");
let btn6 = document.getElementById("btn6");
let btn7 = document.getElementById("btn7");
let btn8 = document.getElementById("btn8");
let btn9 = document.getElementById("btn9");

function clockwiseRotation() {
    [btn1.innerHTML,
     btn2.innerHTML,
     btn3.innerHTML,
     btn4.innerHTML,
     btn6.innerHTML,
     btn7.innerHTML,
     btn8.innerHTML,
     btn9.innerHTML] =
        [btn4.innerHTML,
         btn1.innerHTML,
         btn2.innerHTML,
         btn7.innerHTML,
         btn3.innerHTML,
         btn8.innerHTML,
         btn9.innerHTML,
         btn6.innerHTML]
}

btn5.addEventListener("click", clockwiseRotation)
