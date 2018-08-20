import processing.serial.*;
Serial robot;
PImage gearsImg, controlsImg, hornImg, lightsImg, logoUktc, logoBan; 
boolean isLightsOn = false;
boolean connected = false;
void setup(){
  robot = new Serial(this, "COM4", 9600);
  gearsImg = loadImage("speeds.png");
  controlsImg = loadImage("stop.png");
  hornImg = loadImage("hornoff.png");
  lightsImg = loadImage("loff.png");
  logoUktc = loadImage("logo.png");
  logoBan = loadImage("logoban.png");
  size(700, 400);
}


void draw(){
  background(255);
  if(mouseX > 190 && mouseX < 250 && mouseY > 110 && mouseY < 190 && mousePressed || (keyPressed && keyCode == UP)){
    controlsImg = loadImage("forward.png");
    robot.write("F");
  }
  else if(mouseX > 190 && mouseX < 250 && mouseY > 250 && mouseY < 325 && mousePressed || (keyPressed && keyCode == DOWN)){
    controlsImg = loadImage("backward.png");
    robot.write("B");
  }
  else if(mouseX > 115 && mouseX < 190 && mouseY > 190 && mouseY < 250 && mousePressed || (keyPressed && keyCode == LEFT)){
    controlsImg = loadImage("left.png");
    robot.write("L");
  }
  else if(mouseX > 250 && mouseX < 325 && mouseY > 190 && mouseY < 250 && mousePressed || (keyPressed && keyCode == RIGHT)){
    controlsImg = loadImage("right.png");
    robot.write("R");
  }
  else{
    controlsImg = loadImage("stop.png");
    robot.write("S");
  }
  
  
  if(mouseX > 412 && mouseX < 440 && mouseY > 140 && mouseY < 170 && mousePressed){
    gearsImg = loadImage("speedsr.png");
  }
  else if(mouseX > 455 && mouseX < 470 && mouseY > 140 && mouseY < 170 && mousePressed){
    gearsImg = loadImage("speeds1.png");
    robot.write("2");
  }
  else if(mouseX > 530 && mouseX < 555 && mouseY > 140 && mouseY < 170 && mousePressed){
    gearsImg = loadImage("speeds5.png");
    robot.write("8");
  }
  else if(mouseX > 485 && mouseX < 515 && mouseY > 130 && mouseY < 170 && mousePressed){
    gearsImg = loadImage("speeds3.png");
    robot.write("5");
  }
  else if(mouseX > 445 && mouseX < 465 && mouseY > 275 && mouseY < 300 && mousePressed){
    gearsImg = loadImage("speeds2.png");
    robot.write("3");
  }
  else if(mouseX > 485 && mouseX < 505 && mouseY > 275 && mouseY < 300 && mousePressed){
    gearsImg = loadImage("speeds4.png");
    robot.write("7");
  }
  else if(mouseX > 525 && mouseX < 545 && mouseY > 275 && mouseY < 300 && mousePressed){
    gearsImg = loadImage("speeds6.png");
      robot.write("9");
  }
   else if(mouseX > 400 && mouseX < 560 && mouseY > 180 && mouseY < 260 && mousePressed){
    gearsImg = loadImage("speeds.png");
    robot.write("0");
  }
  
  if(mouseX > 200 && mouseX < 230 && mouseY > 20 && mouseY < 50 && mousePressed){
    hornImg = loadImage("hornon.png");
  }
  else{
    hornImg = loadImage("hornoff.png");
  }
  
  if(mouseX > 300 && mouseX < 330 && mouseY > 20 && mouseY < 50 && mousePressed){
    if(isLightsOn){
      lightsImg = loadImage("loff.png");
      isLightsOn = false;
    }
    else{
      lightsImg = loadImage("lon.png");
      isLightsOn = true;
    }
  }
  
  image(controlsImg, 70, 70, 300, 300);
  image(gearsImg, 400, 130, 180, 180);
  image(hornImg, 200, 20, 30, 30);
  image(lightsImg, 300, 20, 30, 30);
  image(logoUktc, 575, 70, 100, 100);
  image(logoBan, 575, 220, 100, 100);
  println(mouseX + " " + mouseY);
}
