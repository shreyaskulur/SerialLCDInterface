#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t
#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 7, 6, 5, 4); //initialise LCD in Serial LCD Interface Module

void setup()  
{
  pinMode(3 , OUTPUT);   //Set LCD backlight LED pin as output
  digitalWrite(3, HIGH); //Switch ON LCD backlight
  lcd.begin(16, 2);      
  setSyncProvider(RTC.get);   // the function to get the time from the RTC     
  if(timeStatus()!= timeSet) 
     lcd.print(" RTC Unavailable");
}

void loop()
{
  
  if (timeStatus() == timeSet) 
  {
    digitalClockDisplay();
  } 
  delay(100);
}


void digitalClockDisplay(){
  // digital clock display of the time
  lcd.setCursor(0,0);
  lcd.print(hour());
  printDigits(minute());
  printDigits(second());
  lcd.print("     ");
  lcd.setCursor(0,1);
  lcd.print(day());
  lcd.print("/");
  lcd.print(month());
  lcd.print("/");
  lcd.print(year()); 
  lcd.print("     "); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  if((millis()%1000)>=500)
  lcd.print(":");
  else
  lcd.print(" ");
  if(digits < 10)
    lcd.print('0');
  lcd.print(digits);
}

