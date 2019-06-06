// Hydrologendag_DHT11_OLED

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Wire.begin();
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);// initialize with the I2C addr 0x3C
  Serial.begin(9600);
}

void displayTempHumid(){
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    display.clearDisplay(); // clearing the display
    display.setTextColor(WHITE); //setting the color
    display.setTextSize(1); //set the font size
    display.setCursor(5,0); //set the cursor coordinates
    display.print("Failed to read from DHT sensor!");
    return;
  }
  
display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Vochtigheid: "); 
  Serial.print("Vochtigheid: "); 
  display.print(h);
  Serial.print(h);
  display.print(" %");
  Serial.println(" %");
  display.setCursor(0,10);
  display.print("Temperatuur: "); 
  Serial.print("Temperatuur: "); 
  display.print(t);
  Serial.print(t);
  display.print(" C"); 
  Serial.println(" C");
  Serial.println();

}
void loop() {
  displayTempHumid();
  display.display();
}
