/*******************************************************************
 *                  Capstone Voltmeter
 * An arduino based 2 channel voltmeter created as a part of our Capstone.
 * 
 * By: Matthew Wagner, Noah Blain, Donovan Booker, Brandon Garner
 *******************************************************************/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);                                                                                   // Set the LCD address to 0x27 for a 16 chars and 2 line display

void errorHandler(char code[]);                                                                                     // Prints the Error code and performs a reset

void setup() {
  pinMode(A0, INPUT); // Channel 1
  pinMode(A2, INPUT); // Channel 2
  
  // Initialize the lcd
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  // Read the voltage values for both channels
  double V1 = map(analogRead(A0),0,1023,0,1000);
  double V2 = map(analogRead(A2),0,1023,0,1000);

  // Multiple reads provide more accurate results
  for(int i=0; i<10; i++) {
    V1 = map(analogRead(A0),0,1023,0,1000);
    V2 = map(analogRead(A2),0,1023,0,1000);
  }

  // Display the voltage values
  lcd.print(V1/100);
  lcd.print("V      CH: 1");
  lcd.setCursor(0,1);
  lcd.print(V2/100);
  lcd.print("V      CH: 2");
  delay(2300);
  lcd.clear();

}

