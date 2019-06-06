// Hydrologendag_druksensor_OLED

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  display.setTextSize(3); // Set the text size
  display.setTextColor(WHITE); // Set the text color
  Serial.begin(9600);
}

void loop()
{
  delay(50);
int diepte = (analogRead(A0) - 150) * 0.4;
 
/*
 diepte=(analogRead(A0)-sensorvalue_0cm)*(345/(1023-sensorvalue_0cm)
 maximale range 5psi sensor = 345 cm
 maximale analogRead = 1023
 sensorvalue_0cm = analogRead met sensor boven water  
 */

   Serial.print("analogRead ");
   Serial.print(analogRead(A0));
   Serial.print("  diepte ");
   Serial.print(diepte);
   Serial.println(" cm"); // Append the unit
   
   display.clearDisplay(); // Clear the display
   display.setCursor(5,5); // Set the cursor at the beginning of the display
   display.print(diepte); // Print diepte
   display.println(" cm"); // Append the unit
   display.display(); // Display depth and unit on the display
   }
