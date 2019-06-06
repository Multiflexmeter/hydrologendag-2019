// Hydrologendag_capacitative_soil_sensor

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const int AirValue = 600;   //calibrate this value for air
const int WaterValue = 270;  //calibrate this value for water
int intervals = (AirValue - WaterValue)/3;
int soilMoistureValue = 0;

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  display.setTextSize(2); // Set the text size
  display.setTextColor(WHITE); // Set the text color
}

void loop() {
   display.clearDisplay(); // Clear the display
   display.setCursor(5,5); // Set the cursor at the beginning of the display

  soilMoistureValue = analogRead(0); //connect sensor to Analog 0
  Serial.println(soilMoistureValue); //print the value to serial port
  if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
{
  Serial.println("Kleddernat");
  display.print("Kleddernat"); // Print status
  display.display();
}
else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
{
  Serial.println("Nat");
  display.print("Nat"); // Print status
  display.display();
}
else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
{
  Serial.println("Droog");
  display.print("Droog"); // Print status
  display.display();
}
  delay(100);
}
