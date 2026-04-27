#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin Definitions
#define IR1_PIN 2
#define IR2_PIN 3
#define LED_PIN 5
#define BUZZER_PIN 4

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables
unsigned long startTime = 0;
unsigned long endTime = 0;
bool objectDetected = false;

// Constants
const float distanceCM = 10.0;     // Distance between sensors (change if needed)
const float speedLimit = 20.0;     // Speed limit in km/h

void setup() {
  pinMode(IR1_PIN, INPUT);
  pinMode(IR2_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Speed Radar");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensor1 = digitalRead(IR1_PIN);
  int sensor2 = digitalRead(IR2_PIN);

  // Step 1: Object crosses first sensor
  if (sensor1 == LOW && !objectDetected) {
    startTime = millis();
    objectDetected = true;
  }

  // Step 2: Object crosses second sensor
  if (sensor2 == LOW && objectDetected) {
    endTime = millis();

    unsigned long timeTaken = endTime - startTime;

    if (timeTaken > 0) {
      float timeSec = timeTaken / 1000.0;

      float speedCmps = distanceCM / timeSec;
      float speedKmph = speedCmps * 0.036;

      // Display on LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Speed:");
      lcd.setCursor(0, 1);
      lcd.print(speedKmph, 2);
      lcd.print(" km/h");

      // Alert system
      if (speedKmph > speedLimit) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
      } else {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
      }

      delay(2000); // display time
    }

    // Reset for next reading
    objectDetected = false;
  }
}