// goal of code is to get the numbers to get the analog readings
//of all three sensors for the line tracker to then use them in the main code
#define FS_R analogRead (A0)// define variable of Analog read of pin A0 as the Right side of the module
#define FS_M analogRead (A1)// define variable of Analog read of pin A1 as the middle of the module
#define FS_L analogRead (A2)// define variable of Analog read of pin A2 as the left side of the module
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600); // start serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print (FS_R); // print variables on serial monitor
Serial.print ("\t"); // print variables on serial monitor

Serial.print (FS_M); // print variables on serial monitor
Serial.print ("\t"); // print variables on serial monitor

Serial.println (FS_L); // print variables on serial monitor
delay (50); 
}
