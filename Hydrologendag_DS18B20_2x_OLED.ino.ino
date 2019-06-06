//Hydrologendag_DS18B20_2x_OLED.ino

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int OLED_RESET = 4;
Adafruit_SSD1306 display(OLED_RESET);

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  display.setTextSize(2); // Set the text size
  display.setTextColor(WHITE); // Set the text color
  
Serial.begin(9600);
  sensors.begin();

}
void loop()
{
  display.clearDisplay(); // Clear the display
  sensors.requestTemperatures(); // Send the command to get temperatures
  display.setCursor(0,0); // Set the cursor at the beginning of the display
  display.print("1: ");
  Serial.print("1: "); // Serial print
  display.print((sensors.getTempCByIndex(0)),1); // Display temp with one decimal
  Serial.print((sensors.getTempCByIndex(0)),1); // Serial print
  display.println(" C"); // Append the unit
  Serial.println(" C"); // Serial print
  display.print("2: "); // Serial print
  Serial.print("2: "); // Serial print
  display.print((sensors.getTempCByIndex(1)),1); // Display temp with one decimal
  Serial.print((sensors.getTempCByIndex(1)),1);
  display.println(" C"); // Append the unit
  Serial.println(" C"); // Serial print
  display.display(); // Display the temperature and unit on the display
  Serial.println();

delay(500);
}
