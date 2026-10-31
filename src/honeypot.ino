
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 2;
const int buzzerPin = 3;
const int chipSelect = 10;

unsigned long attemptCount = 0;
File logFile;

void showReadyScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Secure Terminal");
  lcd.setCursor(0, 1);
  lcd.print("Press to access");
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");

  if (!SD.begin(chipSelect)) {
    lcd.clear();
    lcd.print("SD Card Error");
    Serial.println("ERROR: SD initialization failed.");

    while (true) {
      delay(100);
    }
  }

  Serial.println("Honeypot prototype initialized.");
  showReadyScreen();
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    attemptCount++;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied");
    lcd.setCursor(0, 1);
    lcd.print("Attempt Logged");

    tone(buzzerPin, 1000, 150);

    logFile = SD.open("log.txt", FILE_WRITE);

    if (logFile) {
      logFile.print("Attempt: ");
      logFile.print(attemptCount);
      logFile.print(", Uptime (ms): ");
      logFile.println(millis());
      logFile.close();

      Serial.println("Access attempt recorded.");
    } else {
      Serial.println("ERROR: Could not open log file.");
    }

    delay(3000);
    showReadyScreen();

    // Wait for button release to prevent repeated logging :>
    while (digitalRead(buttonPin) == LOW) {
      delay(10);
    }
  }
}
