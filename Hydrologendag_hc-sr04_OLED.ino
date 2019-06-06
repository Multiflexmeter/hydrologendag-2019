// Hydrologendag_hc-sr04_OLED

#include <SPI.h>
#include <Wire.h>
#include <NewPing.h> //https://bitbucket.org/teckel12/arduino-new-ping/downloads/
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TRIGGER_PIN 6
#define ECHO_PIN 3
#define MAX_DISTANCE 300

int uS = 0;
int OLED_RESET = 4;
Adafruit_SSD1306 display(OLED_RESET);
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  display.setTextSize(3); // Set the text size
  display.setTextColor(WHITE); // Set the text color
 
  Serial.begin(9600);
}
 
void loop() {
   delay(1000);
   int uS = sonar.ping_cm();
   display.clearDisplay(); // Clear the display
   display.setCursor(5,5); // Set the cursor at the beginning of the display
   display.print(uS); // Print afstand
   display.println(" cm"); // Append the unit
   display.display(); // Display the distance and unit on the display
   Serial.print(uS); // Print afstand
   Serial.println(" cm"); // Append the unit
   }
