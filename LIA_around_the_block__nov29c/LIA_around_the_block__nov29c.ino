const int motor1 = 7;
const int motor2 = 8;
const int speed1 = 5;
const int speed2 = 6;

void setup() {
  // put your setup code here, to run once:
for (int i=5 ; i<9 ; i++){
  pinMode (i, OUTPUT);}
   digitalWrite (3,1);
}


  void forward (){
  //move forward full speed 
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,255);
  analogWrite (6,255); 
  }
 
  void rightforward (){
  //move right forward full speed 
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,126);
  analogWrite (6,255); 
  }
  
  void stop (){
  //stops 
  digitalWrite (7,1);
  digitalWrite (8,1);
  analogWrite (5,0);
  analogWrite (6,0); 
  }


void loop() {
  // put your main code here, to run repeatedly:
forward ();
delay (4000);
/*rightforward ();
delay (2000);
forward ();
delay (250);
rightforward ();
delay (2000);
forward ();
delay (3500);
rightforward ();
delay (2000);
forward ();
delay (250);
rightforward ();
delay (2000);*/
stop ();
delay (5000);
}
