//Ahmed Mohamed Hassan Mohamed 
//Abdiaziz Nor Ali
//Yahye Omar Osman
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Initialize the LCD, set the I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address to 0x3F if your LCD has a different I2C address

// Pin definitions
const int turbiditySensorPin = A0;

// Turbidity thresholds (these values might need calibration according to your specific sensor)
const int cleanThreshold = 300;  // Example threshold for clean water
const int cloudyThreshold = 700; // Example threshold for cloudy water

void setup() {
  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);
  lcd.backlight();
  
  // Initialize the serial monitor for debugging
  Serial.begin(9600);
  
  // Print initial message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("Turbidity Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  
  lcd.clear();
}

void loop() {
  // Read the turbidity sensor value
  int sensorValue = analogRead(turbiditySensorPin);
  
  // Print the sensor value to the serial monitor
  Serial.print("Turbidity Sensor Value: ");
  Serial.println(sensorValue);
  
  // Determine the water quality based on the sensor value
  String waterQuality;
  
  if (sensorValue < cleanThreshold) {
    waterQuality = "Clean";
  } else if (sensorValue < cloudyThreshold) {
    waterQuality = "Cloudy";
  } else {
    waterQuality = "Dirty";
  }
  
  // Display the water quality on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water Quality:");
  lcd.setCursor(0, 1);
  lcd.print(waterQuality);
  
  // Wait for a short period before the next reading
  delay(1000);
}
