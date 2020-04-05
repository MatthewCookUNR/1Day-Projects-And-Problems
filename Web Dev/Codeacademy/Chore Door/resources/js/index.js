//Document Objects
let doorImage1 = document.getElementById("door1");
let doorImage2 = document.getElementById("door2");
let doorImage3 = document.getElementById("door3");
let startButton = document.getElementById("start");
let currentStreakBox = document.getElementById("currentStreak");
let bestStreakBox = document.getElementById("bestStreak");


//Image Paths
const roboPath = "file:///C:/Users/matth/Coaching-Projects-And-Problems/Web%20Dev/Codeacademy/Chore%20Door/resources/images/robot.svg";
const beachPath = "./resources/images/beach.svg";
const spacePath = "./resources/images/space.svg";
const closedDoorPath = "file:///C:/Users/matth/Coaching-Projects-And-Problems/Web%20Dev/Codeacademy/Chore%20Door/resources/images/closed_door.svg";

//Variables
let numClosedDoors = 3;
let openDoor1;
let openDoor2;
let openDoor3;
let currentlyPlaying = true;
let currentStreak = 0;

//Checks to see if door is clickable (closed)
function isClicked(myDoor) {
  if(myDoor.src === closedDoorPath) {
    return false;
  } else {
    return true;
  }
}

//Checks to see if opened door is a robot
function isBot(myDoor) {
  console.log(myDoor.src);
  if(myDoor.src === roboPath) {
    return true;
  }
  else {
    return false;
  }
}

//Decrements number of closed doors and then checks if there is
//a winner or loser
function playDoor(myDoor) {
  numClosedDoors--;
  if(numClosedDoors === 0) {
    gameOver('win');
  } else if(isBot(myDoor)) {
    gameOver('lose');
  }
}

//Function randomly generates one of 3 different combinations
//of 3 different doors. Each is unique.
function randomChoreDoorGen() {
  let choreDoor = Math.floor(Math.random()*numClosedDoors);
  if(choreDoor === 0) {
    openDoor1 = roboPath;
    openDoor2 = beachPath;
    openDoor3 = spacePath;
  } else if(choreDoor === 1) {
    openDoor1 = spacePath;
    openDoor2 = roboPath;
    openDoor3 = beachPath
  } else {
    openDoor1 = beachPath;
    openDoor2 = spacePath;
    openDoor3 = roboPath
  }
}

//Function checks if game is over and handles accordingly
function gameOver(status) {
  if(status === 'win') {
    startButton.innerHTML = "You win! Play again?";
    currentStreak++
    updateStreakDisplay();
  } else {
    startButton.innerHTML = "You lose. Try again?";
    currentStreak = 0;
    updateStreakDisplay();
  }
  currentlyPlaying = false;
}

//Function effectively resets variables
//and then lets the user play
function startRound() {
  doorImage1.src = closedDoorPath;
  doorImage2.src = closedDoorPath;
  doorImage3.src = closedDoorPath;
  startButton.innerHTML = "Good luck!";
  numClosedDoors = 3;
  randomChoreDoorGen();
  currentlyPlaying = true;
}

//Function updates the current streak box and
//best streak box text
function updateStreakDisplay() {
  currentStreakBox.innerHTML = currentStreak;
  if(currentStreak > bestStreakBox.innerHTML)
  {
    bestStreakBox.innerHTML = currentStreak;
  }
}

//The following 3 onclick functions handle the functionality
//of opening the door by switching the images
doorImage1.onclick = function() {
  if(!isClicked(doorImage1) && currentlyPlaying) {
    doorImage1.src = openDoor1;
    playDoor(doorImage1);
  }
};

doorImage2.onclick = function() {
  if(!isClicked(doorImage2) && currentlyPlaying) {
    doorImage2.src = openDoor2;
    playDoor(doorImage2);
  }
};

doorImage3.onclick = function() {
  if(!isClicked(doorImage3) && currentlyPlaying) {
    doorImage3.src = openDoor3;
    playDoor(doorImage3);
  }
};

//The start button starts the round if the game is currently
//over
startButton.onclick = function() {
  if(currentlyPlaying === false)
  {
    startRound();
  }
};

//Starts the game
startRound();
