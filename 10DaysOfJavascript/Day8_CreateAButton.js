index.html

<!-- Enter your HTML code here -->
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Button</title>
        <link rel="stylesheet" href="css/button.css" type="text/css">
        <style></style>
    </head>
    <body>
        <script src="js/button.js" type="text/javascript"></script>
        <button id="btn" onclick="increment()">0</button>
    </body>
</html>


button.js :

  function increment() {
      var button = document.getElementById("btn");
      let count = 1;
      button.innerHTML = count;
      button.addEventListener("click", ()=>{
          button.innerHTML = +(button.innerHTML)+1;
      });
  }
  
button.css :

#btn {
    width: 96px; 
    height: 48px;
    font-size: 24px;
}