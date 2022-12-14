// linetracking
// line tracking info/define
#define FS_R analogRead (A0)// define variable of Analog read of pin A0 as the Right side of the module  
#define FS_M analogRead (A1)// define variable of Analog read of pin A1 as the middle of the module
#define FS_L analogRead (A2)// define variable of Analog read of pin A2 as the left side of the module
// define variables for motor and motor speed
const int motor1 = 7; // pin 7 connected to motor 1
const int motor2 = 8;// pin 8 connected to motor 2
const int speed1 = 5; // pin 5 connected to speed of motor 1
const int speed2 = 6; // pin 6 connected to speed of motor 2
#define carspeed 100 // define variable of carspeed at 100

void setup() {
  // put your setup code here, to run once:
  digitalWrite (3,1); // turn pin 3 on 
Serial.begin (9600); // start serial monitor
for (int i=5 ; i<9 ; i++){ // make pins 5-6-7-8 outputs
  pinMode (i, OUTPUT);}// make pins 5-6-7-8 outputs
    pinMode (FS_R,INPUT); // Make pin A0 an input
    pinMode (FS_M,INPUT); // Make pin A1 an input
    pinMode (FS_L,INPUT); // Make pin A2 an input
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
if (FS_M >250 && FS_M <850) { // if the middle sensor id between 250 and 850,
  forward ();// the will go forward by calling the function
  }
  else if (FS_R > 300){ // if the right sensor goes above 300,
    right ();// the car will turn right by calling the function
  }
  else if (FS_L > 250){// if the left sensor goes over 250, 
    left ();// the car will go left by calling the function
  }
  else if (FS_M <851 && FS_L <851 && FS_R <851){ // if the middle,left,right sensor are under 851
    right ();// the car will turn to the right to search for the line and go back on its steps.
  }
  else if (FS_M <950 && FS_L <950 && FS_R <950){ // if the sensors all read over 950,
    stop ();// the car stops since it is being picked up
  }
}










 
