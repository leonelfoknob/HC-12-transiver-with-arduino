/*    Arduino Long Range Wireless Communication using HC-12
                      Example 01
   by Dejan Nedelkovski, www.HowToMechatronics.com
*/

#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() { 
  lcd.init();
  lcd.backlight();
  lcd.begin (16, 2); 
  // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12

}

void loop() {
  while (HC12.available()) {// If HC-12 has data
    lcd.setCursor(1, 0);
  lcd.print("sayi: ");
  lcd.setCursor(7, 0);
  lcd.print(HC12.read());
  lcd.print("      ");;      // Send the data to Serial monitor
  }
}
