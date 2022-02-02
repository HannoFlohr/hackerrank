index.html :

<!-- Enter your HTML code here -->
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Binary Calculator</title>
        <link rel="stylesheet" href="css/binaryCalculator.css" type="text/css">
    </head>
    <body>
        <div id="res"></div>
        <div id="btns">
            <button id="btn0" class="btn" onclick="add('0')">0</button> 
            <button id="btn1" class="btn" onclick="add('1')">1</button> 
            <button id="btnClr" class="btn" onclick="clearres()">C</button> 
            <button id="btnEql" class="btn" onclick="equal()">=</button> 
            <button id="btnSum" class="btn" onclick="assignOp('+')">+</button> 
            <button id="btnSub" class="btn" onclick="assignOp('-')">-</button> 
            <button id="btnMul" class="btn" onclick="assignOp('*')">*</button> 
            <button id="btnDiv" class="btn" onclick="assignOp('/')">/</button> 
        </div>
        <script src="js/binaryCalculator.js" type="text/javascript"></script>
    </body>
</html>

binaryCalculator.css :

body{
    width: 33%;
}
#res {
    background-color: lightgray;
    border: solid;
    height: 48px;
    font-size: 20px;
}
#btn0, #btn1 {
    background-color: lightgreen;
    color: brown;
}
#btnClr, #btnEql {
    background-color: lightgreen;
    color: white;
}
#btnSum, #btnSub, #btnMul, #btnDiv {
    background-color: black;
    color: red;
}
.btn {
    width: 25%;
    height: 36px;
    font-size: 18px;
    margin: 0px;
    float: left;
}

binaryCalculator.js :

const res = document.getElementById("res");
let operand1 = operand2 = operator = '';

function add(value) {
    if(operator)
        operand2 += value;
    else
        operand1 += value;
    renderResult();
}

function clearres() {
    operand1 = operand2 = operator = '';
    renderResult();
}

function assignOp(value) {
    operator = value;
    renderResult();
}

function equal() {
    operand1 = parseInt(operand1, 2);
    operand2 = parseInt(operand2, 2);
    switch(operator) {
        case '+':
            operand1 += operand2;
            break;
        case '-':
            operand1 -= operand2;
            break;
        case '*':
            operand1 *= operand2;
            break;
        case '/':
            operand1 /= operand2;
            break;
        default:
            break;
    }
    operand1 = parseInt(operand1).toString(2);
    operand2 = operator = "";
    renderResult();
}

function renderResult() {
    res.innerHTML = operand1 + operator + operand2;
}