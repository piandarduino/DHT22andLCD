
// https://github.com/adafruit/DHT-sensor-library
#include "DHT.h"

//https://github.com/adafruit/Adafruit_LiquidCrystal
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"


#define DHTPIN 2

#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);
//Initialize LCD.
Adafruit_LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp.     ");
  lcd.print(t);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humid.    ");
  lcd.print(h);
  lcd.print("%");
}


