/*void setup() {
  // put your setup code here, to run once:
 pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  
}


*/

/*#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("First line");
  lcd.setCursor(0,1);
  lcd.print("Second line");
}

void loop() {
}*/

/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

///////////////////////////////////////////////////////////////////////////////
/*
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("text");
}

void loop() {
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
}

*/

//////////////////////////////////////////////////////////////////
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

////////////
#include <dht11.h>
#define DHT11PIN A0

dht11 DHT11;
//////////////////////////////////
//Arduino DC motor controlling

#define motor_pin 10
////////////////////////////////
void setup()
{
  Serial.begin(9600);

 // Serial.begin(9600);
 // Serial.println("Arduino Motor controller");

  pinMode(motor_pin, OUTPUT);

   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temp(C):");
 
}

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);

   // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  lcd.print(DHT11.temperature);
  delay(20000);

  if( (DHT11.temperature) < 22 )
  {
     Serial.println("Motor ON");
  digitalWrite(motor_pin, HIGH); //turn ON motor
  }
  else
  {
    
  Serial.println("Motor 0FF");
  digitalWrite(motor_pin, LOW); //turn OFF motor
  }

}
/*
#include <LiquidCrystal.h> // includes the LiquidCrystal Library 


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// these constants won't change.  But you can change the size of
// your LCD using them:
const int numRows = 2;
const int numCols = 16;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(numCols, numRows);
}

void loop() {
  // loop from ASCII 'a' to ASCII 'z':
  for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {
    // loop over the columns:
    for (int  thisRow = 0; thisRow < numRows; thisRow++) {
      // loop over the rows:
      for (int thisCol = 0; thisCol < numCols; thisCol++) {
        // set the cursor position:
        lcd.setCursor(thisCol, thisRow);
        // print the letter:
        lcd.write(thisLetter);
        delay(200);
      }
    }
  }
}*/
/*
LiquidCrystal lcd(2, 3, 4, 5, 11, 12); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
void setup() { 
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
}
void loop() { 
 lcd.print("Arduino"); // Prints "Arduino" on the LCD 
 delay(3000); // 3 seconds delay 
 lcd.setCursor(2,1); // Sets the location at which subsequent text written to the LCD will be displayed 
 lcd.print("LCD Tutorial"); 
 delay(3000); 
 lcd.clear(); // Clears the display 
 lcd.blink(); //Displays the blinking LCD cursor 
 delay(4000); 
 lcd.setCursor(12,1); 
 delay(3000); 
 lcd.noBlink(); // Turns off the blinking LCD cursor 
 lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written 
 delay(4000); 
 lcd.noCursor(); // Hides the LCD cursor 
 lcd.clear(); // Clears the LCD screen 

}
*/

/*
#include <LiquidCrystal.h>
byte slash[8]= { // Array of bytes
  B00001,  // B stands for binary formatter and the 5 numbers are the pixels
  B00010,
  B00100,
  B01000,
  B10000,
  B00000,
  B00000,
  B00000,
};
LiquidCrystal lcd(2, 3, 4, 5, 11, 12); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
void setup() { 
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  lcd.createChar(12, slash); // Create a custom character for use on the LCD. Up to eight characters of 5x8 pixels are supported
}
void loop() { 
  for(int i=0;i<=15;i++) {
    lcd.setCursor(i,0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.write(12); // Writes a character to the LCD
    delay(1000); // 1 second delay
    lcd.clear(); // Write a character to the LCD
  }
}*/
