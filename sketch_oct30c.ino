// Basic Bluetooth sketch HC-05_AT_MODE_01
// Communicate with a HC-05 using the serial monitor
//
// The HC-05 defaults to communication mode when first powered on you will
//need to manually enter AT mode
// The default baud rate for AT mode is 38400
// See www.martyncurrey.com for details
//


#include <SoftwareSerial.h>
SoftwareSerial BTserial(0, 1); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX.
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
//

char c = ' ';
//int c;

void setup()
{
 Serial.begin(9600);
 pinMode(9,HIGH);
 digitalWrite(9,HIGH);
 Serial.println("Arduino is ready");
 Serial.println("Remember to select Both NL & CR in the serial monitor");
 pinMode(8,OUTPUT); //digitalWrite(8,HIGH);


 // HC-05 default serial speed for AT mode is 38400
 BTserial.begin(9600);
 while(!Serial);
 Serial.println("Input A to turn on led, Input B to turn off led");
 
}

void loop()
{

 // Keep reading from HC-05 and send to Arduino Serial Monitor
 if (BTserial.available())
 {
 c = BTserial.read();
 Serial.write(c);
 }

 // Keep reading from Arduino Serial Monitor and send to HC-05
 if (Serial.available())
 {
 c = Serial.read();
 BTserial.write(c);
 char state = c;//Serial.parseInt();
 if(c=='A')
 {
  digitalWrite(8,HIGH);
  Serial.println("LED ON");
 }
 
  if(c=='B')
 {
  digitalWrite(8,LOW);
  Serial.println("LED OFF");
 }
 }

}
