// car move all directioins for 1 sec

const int motor1 = 7; // pin 7 connected to motor 1
const int motor2 = 8;// pin 8 connected to motor 2
const int speed1 = 5; // pin 5 connected to speed of motor 1
const int speed2 = 6; // pin 6 connected to speed of motor 2

void setup() {
  // put your setup code here, to run once:
for (int i=5 ; i<9 ; i++){// make pins 5-6-7-8 outputs
  pinMode (i, OUTPUT);}// make pins 5-6-7-8 outputs
   digitalWrite (3,1); // turn on pin 3
}



  void forward (){
  //move forward full speed for 2 seconds
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,255);
  analogWrite (6,255); 
  }
 
 
  void backward (){
  //move backward full speed for 2 seconds
  digitalWrite (7,0);
  digitalWrite (8,0);
  analogWrite (5,255);
  analogWrite (6,255); 
  }
  
  void left (){
  //move left full speed for 2 seconds
  digitalWrite (7,1);
  digitalWrite (8,0);
  analogWrite (5,255);
  analogWrite (6,255); 
  }
  
  void right (){
  //move right full speed for 2 seconds
  digitalWrite (7,0);
  digitalWrite (8,1);
  analogWrite (5,255);
  analogWrite (6,255); 
  }
  
  void leftforward (){
  //move right forward full speed for 2 seconds
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,255);
  analogWrite (6,126); 
  }

  void leftbackward (){
  //move left backwards full speed for 2 seconds
  digitalWrite (7,0);
  digitalWrite (8,0);
  analogWrite (5,255);
  analogWrite (6,126); 
  }
 
  void rightforward (){
  //move right forward full speed for 2 seconds
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,126);
  analogWrite (6,255); 
  } 
  
  void rightbackward (){
  //move right backwards full speed for 2 seconds
  digitalWrite (7,0);
  digitalWrite (8,0);
  analogWrite (5,126);
  analogWrite (6,255); 
  }
  
  void stop (){
  //stops for 2 second
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,0);
  analogWrite (6,0); 
}

void loop() {
  // put your main code here, to run repeatedly:
"forward ()"; // call forward function
delay (1000); // do function called for 1sec
"backward ()";// call backward function
delay (1000); // do function called for 1sec
"left ()";// call left function
delay (1000); // do function called for 1sec
"right ()";// call right function
delay (1000); // do function called for 1sec
"left forward ()";// call left forwards function
delay (1000); // do function called for 1sec
"left backward ()";// call left backwards function
delay (1000); // do function called for 1sec
"right forward ()";// call right forwards function
delay (1000); // do function called for 1sec
"right backward ()";// call right backwards function
delay (1000); // do function called for 1sec
"stop ()";// call stop function
delay (1000); // do function called for 1sec
}
