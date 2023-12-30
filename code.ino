#include <LiquidCrystal.h>
#include<math.h>

int fan = 7;
int led = 6;
const int GasSensor = A1;
LiquidCrystal lcd_1(13, 12, 11, 10, 9, 8);
void setup()
{
  pinMode(A1, INPUT);
  pinMode(fan,OUTPUT);
  pinMode(led,OUTPUT);
  lcd_1.begin(16, 2); 
  lcd_1.clear();
}

void loop()
{
  int sensorstate = analogRead(GasSensor);
  int sensorvalue = sensorstate;
  lcd_1.setCursor(0, 0);
  lcd_1.print("ROOM OXYGEN   ");
  if( sensorvalue < 101){
    lcd_1.setCursor(0, 1);
    lcd_1.print("LEVEL: Good.");
    digitalWrite(fan , LOW);
    digitalWrite(led , HIGH);
  }
  else if(sensorvalue >101 && sensorvalue < 225){
    lcd_1.setCursor(0, 1);
  	lcd_1.println("LEVEL: Poor.     ");
    digitalWrite(fan , HIGH);
  }
  else if(sensorvalue >225 && sensorvalue < 300){
    lcd_1.setCursor(0, 1);
  	lcd_1.println("LEVEL: Toxic     ");
    digitalWrite(fan , HIGH);
  }
  else if(sensorvalue > 300){
    lcd_1.setCursor(0, 1);
  	lcd_1.println("LEVEL: DEAD      ");
    digitalWrite(fan , HIGH);
  }
  delay(1000);
  
}
