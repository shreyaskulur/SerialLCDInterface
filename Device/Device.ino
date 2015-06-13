#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>      // a basic DS1307 library that returns time as a time_t
#include <LiquidCrystal.h>  //Library to drive the LCD

#define screenSaverTime 5000         //time in ms for screen saver delay   
LiquidCrystal lcd(9, 8, 7, 6, 5, 4); //initialise LCD in Serial LCD Interface Module
int line=0;                          //Keeps track of the number of lines printed on the display
long displayTime;                     //To help calculate idle time for screen saver
char prevLine[16],a;                 //To store display data

void setup()  
{
  pinMode(3 , OUTPUT);        //Set LCD backlight LED pin as output
  digitalWrite(3, HIGH);      //Switch ON LCD backlight
  lcd.begin(16, 2);      
  Serial.begin(9600);         //Begin serial UART communication at the specified baud rate
  setSyncProvider(RTC.get);   //The function to get the time from the RTC     
 // startupScreen();          //Displays a simple startup screen and also displays if RTC is connected. Space not enough on atmega8. Works on atmega328
}

void loop()
{
  if (Serial.available()) 
  {
    delay(10);                //wait for complete message
    lcd.clear();              //clear the screen
    lcd.setCursor(0,0);
    lcd.write(prevLine);    //Move the previous data on the 2nd line to the first line
      
    for(int i=0; i<16; i++) //read new data and save it in the variable prevLine
      {
        if(Serial.available()){
         a=Serial.read();
        
        if(!(  (a=='\n')||(a=='\0')||(a=='\r')))
        prevLine[i]=a;  
        else
         prevLine[i]=' ';
      }
        else
         prevLine[i]=' ';  
        
      }
    lcd.setCursor(0,1);  //display new data in the 2nd line
    lcd.write(prevLine);
    line++;               //increase the line counter
    displayTime=millis(); //save the current time to help calculate idele time later
  }
  
  if((millis()-displayTime)>screenSaverTime) //If no new data since the set time, display time
  if (timeStatus() == timeSet) 
  {
    digitalClockDisplay();
  } 
  
}

void startupScreen()   //Displays a simple startup screen and also displays if RTC is connected. Space not enough on atmega8. Works on atmega328
{
  lcd.clear();
  lcd.print("SERIAL LCD");
  lcd.setCursor(0,1);
  lcd.print("       INTERFACE");
  delay(1000);
  lcd.clear();
  
  lcd.setCursor(0,1);
  if(timeStatus()!= timeSet) 
     lcd.print("~RTC Unavailable");
  else
     lcd.println("~RTC Available"); 
     lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("Initialising.");
  for(int i=0; i<3; i++)
  {
    delay(200);
    lcd.print(".");
  }
  delay(500);
  lcd.clear();
}

//Functions to display clock
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

