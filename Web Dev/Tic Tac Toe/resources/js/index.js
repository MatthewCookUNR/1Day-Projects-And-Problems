let canvas = document.getElementById("myCanvas");
let context = canvas.getContext("2d");
let ticBoard = [[0, 0, 0],[0,0,0],[0,0,0]];
let currentPlayer = chooseRandomPlayer();
console.log(currentPlayer);

drawBoard();
writeMessage("Player " + currentPlayer + " turn");

canvas.addEventListener("mousedown", function(event) {
  let mousePos = getMousePos(canvas, event);
  if(mousePos.y > 300)
  {
    console.log("Clicked off of board")
  }
  else
  {
    ticTacToe(mousePos)
  }

}, false);


function ticTacToe(mousePos)
{
  let row = -1;
  let col = -1;
  if(mousePos.x < 100) {
    col = 0;
  }
  else if (mousePos.x < 200) {
    col = 1;
  }
  else {
    col = 2;
  }

  if(mousePos.y < 100) {
    row = 0;
  }
  else if(mousePos.y < 200) {
    row = 1;
  }
  else {
    row = 2;
  }

  if(ticBoard[row][col] === 0)
  {
    if(currentPlayer === 'X') {
      ticBoard[row][col] = 'X';
      drawX(row, col);
      currentPlayer = 'O';    
    }
    else {
      ticBoard[row][col] = 'O';
      drawO(row, col);
      currentPlayer = 'X';
    }
    writeMessage("Player " + currentPlayer + " turn");
  }
  checkForWinner();
}

function checkForWinner() {
  for(let i = 0; i < ticBoard.length; i++)
  {
    if(ticBoard[0][i] === ticBoard[1][i] && ticBoard[0][i] === ticBoard[2][i])
    {
      writeMessage("Player " + ticBoard[0][i] + " wins!");
    }
  }

  for(let i = 0; i < ticBoard.length; i++)
  {
    if(ticBoard[i][0] === ticBoard[i][1] && ticBoard[i][0] === ticBoard[i][2])
    {
      writeMessage("Player " + ticBoard[0][i] + " wins!");
    }
  }
}

function getMousePos(canvas, event)
{
  var rect = canvas.getBoundingClientRect();
    return {
      x: event.clientX - rect.left,
      y: event.clientY - rect.top
    };
}

function drawBoard()
{
  context.beginPath();
  context.moveTo(0, 100);
  context.lineTo(300, 100);
  context.stroke();

  context.beginPath();
  context.moveTo(0, 200);
  context.lineTo(300,200);
  context.stroke();

  context.beginPath();
  context.moveTo(100, 0);
  context.lineTo(100, 300);
  context.stroke();

  context.beginPath();
  context.moveTo(200, 0);
  context.lineTo(200,300);
  context.stroke();
}

function drawX(row, col)
{
  xpos = 50 + 100 * col;
  ypos = 50 + 100 * row;
  context.beginPath();
  context.moveTo(xpos-25, ypos-25);
  context.lineTo(xpos+25, ypos+25);
  context.stroke();

  context.beginPath();
  context.moveTo(xpos-25, ypos+25);
  context.lineTo(xpos+25, ypos-25);
  context.stroke();
}

function drawO(row, col)
{
  xpos = 50 + 100 * col;
  ypos = 50 + 100 * row;
  context.beginPath();
  context.arc(xpos,ypos,40,0,2*Math.PI)
  context.stroke();
}

function chooseRandomPlayer()
{
  const random = Math.floor(Math.random()*2);
  if(random === 0) {
    return 'O';
  }
  else {
    return 'X'
  }
}

function writeMessage(message)
{
  context.beginPath();
  context.clearRect(0, 300, 300, 200);
  context.font = "30px Arial";
  context.fillText(message, 75, 350);
}

