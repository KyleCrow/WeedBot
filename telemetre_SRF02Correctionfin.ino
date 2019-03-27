#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

const int colorR = 16;
const int colorG = 52;
const int colorB = 50;
const int adresseSRF08=124;

int reading = 0;
int value;

void sfr02_mesure()
{

  // step 1: instruct sensor to read echoes
  Wire.beginTransmission(adresseSRF08); // transmit to device #112 (0x70)
  // the address specified in the datasheet is 224 (0xE0)
  // but i2c adressing uses the high 7 bits so it's 112
  Wire.write(byte(0x00));      // sets register pointer to the command register (0x00)
  Wire.write(byte(0x51));      // command sensor to measure in "inches" (0x50)
  // use 0x51 for centimeters
  // use 0x52 for ping microseconds
  Wire.endTransmission();      // stop transmitting

  // step 2: wait for readings to happen
  delay(70);                   // datasheet suggests at least 65 milliseconds

  // step 3: instruct sensor to return a particular echo reading
  Wire.beginTransmission(adresseSRF08); // transmit to device #112
  Wire.write(byte(0x02));      // sets register pointer to echo #1 register (0x02)
  Wire.endTransmission();      // stop transmitting

  // step 4: request reading from sensor
  Wire.requestFrom(adresseSRF08, 2);    // request 2 bytes from slave device #112

  // step 5: receive reading from sensor
  if (2 <= Wire.available()) { // if two bytes were received
    reading = Wire.read();  // receive high byte (overwrites previous reading)
    reading = reading << 8;    // shift high byte to be high 8 bits
    reading |= Wire.read(); // receive low byte as lower 8 bits
  }


}

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("Telemetre");
  delay(1000);
}
void loop()
{
  // put your main code here, to run repeatedly:
    sfr02_mesure();
    lcd.clear();
    lcd.print(reading);
    Serial.println(reading);
    value=10*(reading-10);
    if (value<5)
    {
      value=5;
    }
    delay(value);

}
