#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(9, 8, 7, 6, 5, 4); //initialisation for LCD Module
// make some custom characters:

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};
void setup() {
  // create a new character
  lcd.createChar(1, smiley);
  // create a new character
  lcd.createChar(3, armsDown);  
  // create a new character
  lcd.createChar(4, armsUp);  

  // set up the lcd's number of columns and rows: 
  lcd.begin(16, 2);

pinMode(3, OUTPUT);  //Pin 3 is connected to the LCD Backlight
digitalWrite(3,HIGH);//Turn ON the LCD Backlight
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("      MASK     ");
  for(int i=0;i<5;i++)
  {
  // read the potentiometer on A0:
  int sensorReading = analogRead(A0);
  // map the result to 0-15
  int delayTime = 200;
  int loc=map(sensorReading, 0, 1023, 0, 15);
  
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(loc, 1);
  lcd.write(3);
  lcd.setCursor(15-loc, 1);
  lcd.write(1);
  delay(delayTime);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(loc, 1);
  lcd.write(4);
  lcd.setCursor(15-loc, 1);
  lcd.write(1);
  delay(delayTime); 
}

lcd.setCursor(0, 0);
  lcd.print(" Shreyas  Kulur ");
  for(int i=0;i<5;i++)
    {
  int sensorReading = analogRead(A0);
  int delayTime = 120;
  int loc=map(sensorReading, 0, 1023, 0, 15);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(loc, 1);
  lcd.write(3);
  lcd.setCursor(15-loc, 1);
  lcd.write(1);
  delay(delayTime);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(loc, 1);
  lcd.write(4);
  lcd.setCursor(15-loc, 1);
  lcd.write(1);
  delay(delayTime); 
}


  lcd.setCursor(0, 0);
  lcd.print("    shreyask.in ");
  for(int i=0;i<5;i++)
    {
  int sensorReading = analogRead(A0);
  int delayTime = 300;
  int loc=map(sensorReading, 0, 1023, 0, 15);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(loc, 1);
  lcd.write(3);
  lcd.setCursor(15-loc, 1);
  lcd.write(1);
  lcd.setCursor(0, 0);
  lcd.print(">>  ");
  delay(delayTime);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(loc, 1);
  lcd.write(4);
  lcd.setCursor(15-loc, 1);
  lcd.write(1);
  lcd.setCursor(0, 0);
  lcd.print(" >> ");
  delay(delayTime);
 
 lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(loc, 1);
  lcd.write(3);
  lcd.setCursor(15-loc, 1);
  lcd.write(1);
  lcd.setCursor(0, 0);
  lcd.print("  >>");
  delay(delayTime);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(loc, 1);
  lcd.write(4);
  lcd.setCursor(15-loc, 1);
  lcd.write(1);
  lcd.setCursor(0, 0);
  lcd.print(">  >");
  delay(delayTime); 
}}



