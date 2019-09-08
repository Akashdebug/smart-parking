
#include <Servo.h>
Servo myservo;
int y=0; 
#include <LCD.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int place[]={13,12,11,10,9,8};
byte val[6];
const int in=7;
const int out=6;
int count=0;
int valin=0;
int valout=0;
int pos = 0; 
int cnt;
void setup() {
  Serial.begin(9600);
  for(int i=0;i<5;i++)
     {pinMode(place[i], INPUT);}  
     
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  
  myservo.attach(5); 
  
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print("NAMASTE SIR/MAM ");
delay(1800);
 

lcd.clear();
//lcd.setCursor(0, 0);
  count=0;

}
void loop() {
 //******************************************************* 
  lcd.setCursor(0,0);
  lcd.print("P-L");
  lcd.setCursor(0,1);
  valin = digitalRead(in);
  valout = digitalRead(out);
  if(valin==0)
  {
    if(count>=6)
    {
      lcd.clear();
      lcd.print("full");
    delay(1000);
    }
    else if(count<6)
    {
      lcd.print("Available:");
      count++;
      Serial.print("count:");      
      Serial.println(count);
       
  for(y=0;y<=5;y++)
  {
    val[y]=digitalRead(place[y]);
   Serial.println(val[y]);
    if(val[y]==1)
    {
      lcd.print(y+1);
    }
    else
    {
      lcd.print(" ");
    }
    
    }
  
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in ste ps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
    }
  }
  if(valout==0)
  {
     for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
count--;
Serial.print("count:");   
Serial.println(count);
  }
}
   
