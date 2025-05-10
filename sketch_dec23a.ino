#include <Keypad.h>

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pressed;

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
int motorPin = 13;

byte rowPins[ROWS] = {0, 1, 2, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4,5,6,7}; //connect to the column pinouts of the keypad



Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

/*
 * 
 * digitalWrite(motor_pin, HIGH); //turn ON motor
  }
  else
  {
    
  Serial.println("Motor 0FF");
  digitalWrite(motor_pin, LOW); //turn OFF motor
 * lcd.setCursor(0, 0);
lcd.print(“Line 1”);
lcd.setCursor(0, 1);
lcd.print(“Line 2”);
 */


void setup(){
   pinMode(motorPin, OUTPUT);
   
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Enter a key:");
  //lcd.print(pressed);
 // delay(8000);
 // lcd.clear();

 /* delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(pressed);
  delay(500);
  lcd.clear();*/
   
   Serial.begin(9600);
}
  
void loop(){

  char key = keypad.getKey();
    // Turn off the display:
  /*lcd.noDisplay();
  delay(500);
 // Turn on the display:
  lcd.display();*/                    
    // just print the pressed key
   if (key){
    Serial.println(key);
  } 

                     


   if (key =='0'){
    Serial.println("Key 0 is pressed");
    pressed = 0;
    lcd.setCursor(12,0);
    lcd.print(pressed);

    digitalWrite(motorPin, LOW); //turn ON motor

  }
   if (key =='1'){
    Serial.println("Key 1 is pressed");
    lcd.setCursor(12,0);
    pressed = 1;
    lcd.print(pressed);

    digitalWrite(motorPin, HIGH); //turn ON motor

    //analogWrite(motorPin, 1); 

  }
   if (key =='2'){
    Serial.println("Key 2 is pressed");
    //analogWrite(motorPin, 2); 

  }
   if (key =='3'){
    Serial.println("Key 3 is pressed");
    //analogWrite(motorPin, 3); 

  }
  // this checkes if 4 is pressed, then do something. Here  we print the text but you can control something.
  if (key =='4'){
    Serial.println("Key 4 is pressed");
   // analogWrite(motorPin, 4); 

  }
}
