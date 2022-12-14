// collision avoidance 

#include <Servo.h>  // add servo library 
Servo myservo;// create servo object to control a servo
int echopin = 12;// hook up HC-SR04 with echo to arduino pin 12
int trigpin = 13;// hook up HC-SR04 with trig to arduino pin 13
int R_dist = 0, M_dist = 0, L_dist = 0; //
#define maxdistance 200 //max sensor distance we want to ping, is rated at 400-500m

const int motor1 = 7; // pin 7 connected to motor 1
const int motor2 = 8; // pin 8 connected to motor 2
const int speed1 = 5; // pin 5 connected to speed of motor 1
const int speed2 = 6; // pin 6 connected to speed of motor 2
#define carspeed 150 // define variable of carspeed at 150

int Distancetest (){
  //send pulse 
  digitalWrite (trigpin, LOW);// write a pulse to the HC-SR04 Trigger Pin
  delayMicroseconds (2);
  digitalWrite (trigpin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigpin, LOW);
  float Fdistance = pulseIn (echopin, HIGH);// measure the responce from the HC-SR04 echo pin
  Fdistance = Fdistance/58;
  return (int) Fdistance;
}

void setup() {
  // put your setup code here, to run once:
digitalWrite (3,1); // turn pin 3 on 
Serial.begin (9600); // start serial monitor
for (int i=5 ; i<9 ; i++){ // make pins 5-6-7-8 outputs
  pinMode (i, OUTPUT);}// make pins 5-6-7-8 outputs
  myservo.attach (10);// attaches the servo on pin 10 to the servo object
  pinMode (echopin, INPUT);// declaire echoPin an input
  pinMode (trigpin, OUTPUT);// declaire trigPin an output
  stop (); // call stop function
}

 void forward (){
  //move forward full speed 
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,carspeed);
  analogWrite (6,carspeed); 
  Serial.println ("Forward"); // print direction/movement to serial monitor
  }
 
 
  void backward (){
  //move backward full speed 
  digitalWrite (7,0);
  digitalWrite (8,0);
  analogWrite (5,carspeed);
  analogWrite (6,carspeed); 
  Serial.println ("Backward"); // print direction/movement to serial monitor
  }
  
  void left (){
  //move left full speed 
  digitalWrite (7,1);
  digitalWrite (8,0);
  analogWrite (5,carspeed);
  analogWrite (6,carspeed); 
  Serial.println ("Left"); // print direction/movement to serial monitor
  }
  
  void right (){
  //move right full speed
  digitalWrite (7,0);
  digitalWrite (8,1);
  analogWrite (5,carspeed);
  analogWrite (6,carspeed); 
  Serial.println ("Right"); // print direction/movement to serial monitor
  }
  
  void leftforward (){
  //move right forward full speed 
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,carspeed);
  analogWrite (6,carspeed/2); 
  Serial.println ("Leftforward"); // print direction/movement to serial monitor
  }

  void leftbackward (){
  //move left backwards full speed 
  digitalWrite (7,0);
  digitalWrite (8,0);
  analogWrite (5,carspeed);
  analogWrite (6,carspeed/2); 
  Serial.println ("Leftbackward"); // print direction/movement to serial monitor
  }
 
  void rightforward (){
  //move right forward full speed 
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,carspeed/2);
  analogWrite (6,carspeed);
  Serial.println ("Rightforward");  // print direction/movement to serial monitor
  } 
  
  void rightbackward (){
  //move right backwards full speed 
  digitalWrite (7,0);
  digitalWrite (8,0);
  analogWrite (5,carspeed/2);
  analogWrite (6,carspeed); 
  Serial.println ("Rightbackward"); // print direction/movement to serial monitor
  }
  
  void stop (){
  //stops for 2 second
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,0);
  analogWrite (6,0); 
  Serial.println ("Stop"); // print direction/movement to serial monitor
}



void loop() {
  // put your main code here, to run repeatedly:
myservo.write (90); //servo position at 90 deg.
delay (500); //delay .5 sec
M_dist = Distancetest (); // middle distance test

  if (M_dist <= 20) { // if middle dist test is smaller or equal to 20, the car stops
  stop(); // call stop function
  delay (500); //delay 
  myservo.write (10);// launch servo object
  delay (1000);
  R_dist = Distancetest (); // right distance test 

  delay (500);
  myservo.write (90); // turn servo to 90 deg
  delay (1000);
  
  myservo.write (180); //turn servo to 180 deg
  delay (1000);
  L_dist = Distancetest ();// left distance test 

  delay (500);
  myservo.write (90); //turn servo to 90 deg
  delay (1000);
  if (R_dist > L_dist){ // if right distance test is bigger than left distance test, 
    right (); // the robot will go right by calling the function
    delay (300);
  }
  else if (L_dist > R_dist){// if left distance test is bigger than right distance test, 
    left ();// the robot will go left by calling the function
    delay (300);
  }
  else if ((R_dist <= 20) || (L_dist <= 20)){;  // if the right and left distance test is smaller than 20, 
    backward ();// the robot will go backwards by calling the function
    delay (200);
  }
  else { // if the distance test for all sides is bigger bigger than 20, 
    forward (); // the robot will keep going forward
  }
}
else { // if the distance test for forwards is bigger bigger than 20, 
  forward ();// the robot will keep going forward
}
}
