//IR remote

#include <IRremote.h> //include IR remote library
// define all variables of the remote control
#define Fwd 16736925 // forwards
#define Bwd 16754775 // backwards
#define Lft 16720605 // left
#define Rgt 16761405 // right
#define Stp 16712445 // stop
#define UNKNOWN_Fwd 5316027     // Forward
#define UNKNOWN_Bwd 2747854299  // Backwards
#define UNKNOWN_Lft 1386468383  // Left
#define UNKNOWN_Rgt 553536955   // Right
#define UNKNOWN_Stp 3622325019  // Stop
//define all pins for the motors and car speed
const int motor1 = 7; // pin 7 connected to motor 1
const int motor2 = 8;// pin 8 connected to motor 2
const int speed1 = 5; // pin 5 connected to speed of motor 1
const int speed2 = 6; // pin 6 connected to speed of motor 2
#define carspeed 100 // define variable of carspeed at 100 

int RECV_PIN = 9;// signal pin of IR is digital pin 9

IRrecv irrecv(receiver);//creates instance of 'irrecv'
decode_results results;//creates instance of 'decode_results'
unsigned long val; // variable name
unsigned long pMillis;// variable name

void setup() {
  // put your setup code here, to run once:
digitalWrite(3, OUTPUT); // set pin 3 as output
pinMode(3,1); // open pin 3
for (int i=5 ; i<9 ; i++){ // make pins 5-6-7-8 outputs
  pinMode (i, OUTPUT);}// make pins 5-6-7-8 outputs

move(1,0,1,0);//stop, makes sure that the car is stopped
irrecv.enableIRIn(); //starts receiver
}


void move ( bool a, int b, bool c, int d){

digitalWrite(motor1, a);
analogWrite(speed1, b);

digitalWrite(motor2, c);
analogWrite(speed2, d);
}

void loop(){
 if (irrecv.decode(&results)){ // have we received an IR signal
    pMillis = millis();
    val = results.value;
    irrecv.resume();// ready to receive next values
    switch(val){
      case F:
      case UNKNOWN_F: move( 1,carspeed,1,carspeed); break; //forward
      case B:
      case UNKNOWN_B: move(0,carspeed,0,carspeed); break; //backward
      case L:
      case UNKNOWN_L: move(1,carspeed,0,carspeed); break; // left
      case R:
      case UNKNOWN_R: move(0,carspeed,1,carspeed); break; //right
      case S:
      case UNKNOWN_S: move(1,0,1,0); break; //stop
      default: break;
    }
  }
  else{
    if(millis() - pMillis > 500){ // if value of millis minous pmillis is bigger than 500,
     move(1,0,1,0);// the car stops
      preMillis = millis();
    }
  }
  }
