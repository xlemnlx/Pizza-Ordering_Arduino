/*
 * Welcome to BevPizza
 * Now Serving Order #
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int switchPin = 6;
int hits = 0;
int switchState = 0;
int prevSwitchState = 0;

void setup() 
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Welcome to");
  lcd.setCursor(0,1);
  lcd.print("BevPizza!");
}

void loop() 
{
  switchState = digitalRead(switchPin);
  
  if (switchState != prevSwitchState)
  {
    if (switchState == LOW)
    {
      hits = hits + 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Order #:");
      lcd.setCursor(0,1);
      lcd.print(hits);
    }
  }
  prevSwitchState = switchState;

//  for (int i = 0; i < 13; i++)
//  {
//    lcd.scrollDisplayLeft();
//    delay(300);
//  }
//    
//  for (int i = 0; i < 26; i++)
//  {
//    lcd.scrollDisplayRight();
//    delay(300);
//  }
}
