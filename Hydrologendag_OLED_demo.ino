// Hydrologendag_OLED_demo

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC);
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setTextSize(1); //set the font size
  display.setCursor(0,0); //set the cursor coordinates
  display.print("Multiflexmeter");
  display.setCursor(0,8); //set the cursor coordinates
  display.print("sensor-workshop");
  display.setTextSize(1); //set the font size
  display.setCursor(0,20); //set the cursor coordinates
  display.print("Hydrologendag 2019");
  display.display();
}
