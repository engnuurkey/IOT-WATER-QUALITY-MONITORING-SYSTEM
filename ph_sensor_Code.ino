//Ahmed Mohamed Hassan Mohamed 
//Abdiaziz Nor Ali
//Yahye Omar Osman
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h> // Optional for periodic updates

char auth[] = "gzB-x2_-QKFrU3cPymxZjj-o0vBV-JkH";  // Blynk Auth Token
char ssid[] = "IOT Water Quality";   // Your WiFi SSID
char pass[] = "143Ahmed"; // Your WiFi Password

// Pin configurations
const int pH_Pin = A0;  // Analog pin where pH sensor is connected

// Blynk virtual pin for displaying pH value
const int vPin_pH = V0;  // Virtual Pin for displaying pH value on Blynk app

// Initialize the Blynk timer
SimpleTimer timer;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every 5 seconds (5000 ms)
  timer.setInterval(5000L, sendSensorData);  // Adjust interval as needed
}

void loop() {
  Blynk.run();
  timer.run();  // Initiates SimpleTimer
}

void sendSensorData() {
  // Read the analog input from pH sensor
  float pHValue = analogRead(pH_Pin);
  
  // Process pH value here if needed (convert to pH scale, etc.)
  
  // Send pH value to Blynk app
  Blynk.virtualWrite(vPin_pH, pHValue);
}