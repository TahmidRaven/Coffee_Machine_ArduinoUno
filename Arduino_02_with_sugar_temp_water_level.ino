// ARD2

#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int sensorPin = A0;
const int redLED = 8;
const int yellowLED = 9;
const int blueLED = 10;
const int buttonPin = 4;
const int servoPin = 5;

const int tempSensorPin = 3;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

OneWire oneWire(tempSensorPin);
DallasTemperature sensors(&oneWire);

Servo myServo;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  myServo.attach(servoPin);
  myServo.write(-90);

  sensors.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);  // smaller size to fit both lines clearly
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  int waterLevel = analogRead(sensorPin);
  int buttonState = digitalRead(buttonPin);


  String waterStatus;

  // Handle water level and LEDs
  if (waterLevel < 400) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
    waterStatus = "WATER LEVEL: LOW";
  } else if (waterLevel < 600) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(blueLED, LOW);
    waterStatus = "WATER LEVEL: MODERATE";
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, HIGH);
    waterStatus = "WATER LEVEL: FULL";
  }

  // Servo control via button
  if (buttonState == LOW && lastButtonState == HIGH) {
    Serial.println("Button Pressed");
    myServo.write(-90);
  }

  if (buttonState == HIGH) {
    myServo.write(90);
  }

  lastButtonState = buttonState;

  // Get temperature
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  Serial.print("Water Temp: ");
  Serial.print(tempC);
  Serial.println(" C");

  // Display both temperature and water level on OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(tempC);
  display.print(" C");

  display.setCursor(0, 16);
  display.print(waterStatus);

  display.display();

  delay(200);
}
