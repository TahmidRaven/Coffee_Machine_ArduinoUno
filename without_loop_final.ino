#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define IR_PIN 2
#define BUTTON_PIN 3

// Motor 1 (Grinder)
#define MOTOR_IN1 8
#define MOTOR_IN2 7
#define MOTOR_ENA 9

// Pump
#define PUMP_IN3 5
#define PUMP_IN4 6

// Servo
#define SERVO_PIN 10
Servo coffeeServo;

// Buzzer
#define BUZZER_PIN 11

void setup() {
  pinMode(IR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Internal pull-up resistor

  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_ENA, OUTPUT);

  pinMode(PUMP_IN3, OUTPUT);
  pinMode(PUMP_IN4, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  coffeeServo.attach(SERVO_PIN);
  coffeeServo.write(0); // Initial servo position

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // New prompt asking if user wants coffee
  ////display.clearDisplay();
  //display.setCursor(0, 0);
  //display.println("Want some coffee?");
 // display.println("Press button to start");
  //display.display();

  // Wait for button press
 // while (digitalRead(BUTTON_PIN) == HIGH) {
   // delay(100);
  //}

  // Debounce
  delay(50);
  if (digitalRead(BUTTON_PIN) == LOW) {
    checkForMug();
  }
}

void checkForMug() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Checking for mug...");
  display.display();

  if (digitalRead(IR_PIN) == LOW) {
    delay(1000); // Confirm mug presence
    if (digitalRead(IR_PIN) == LOW) {
      runCoffeeProcess();
    } else {
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Mug removed!");
      display.display();
      delay(3000);
    }
  } else {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("No mug detected");
    display.println("Please place a mug");
    display.display();
    delay(3000);
  }
}

void runCoffeeProcess() {
  // Mug Detected
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Mug Detected");
  display.display();
  delay(2000);

  // Grinding
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Turning on grinder");
  display.display();

  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, 255);

  for (int i = 5; i >= 1; i--) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Grinding Time Left: ");
    display.println(i);
    display.display();
    delay(1000);
  }

  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);

  // Pouring Water
  delay(1000);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Pouring water...");
  display.display();

  digitalWrite(PUMP_IN3, HIGH);
  digitalWrite(PUMP_IN4, LOW);

  for (int i = 3; i >= 1; i--) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Pouring Time Left: ");
    display.println(i);
    display.display();
    delay(1000);
  }

  digitalWrite(PUMP_IN3, LOW);
  digitalWrite(PUMP_IN4, LOW);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Water has been poured");
  display.display();
  delay(1000);

  // Ask to add sugar and wait
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Please add sugar now");
  display.display();
  
  for (int i = 5; i >= 1; i--) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Please add sugar now");
    display.print("Time left: ");
    display.println(i);
    display.display();
    delay(1000);
  }

  // Mixing
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Mixing ingredients...");
  display.display();
  delay(1000);

  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, 255);

  for (int i = 5; i >= 1; i--) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Mixing in progress: ");
    display.println(i);
    display.display();
    delay(1000);
  }

  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);

  // Servo Release Coffee
  delay(1000);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Coffee will fall...");
  display.display();
  delay(1000);

  coffeeServo.write(45); // Open position

  for (int i = 3; i >= 1; i--) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Coffee falling in: ");
    display.println(i);
    display.display();
    delay(1000);
  }

  coffeeServo.write(0); // Close position
  delay(500);

  // Final message and buzzer
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Enjoy your coffee!");
  display.display();

  tone(BUZZER_PIN, 1000); // 1 kHz
  delay(1000);
  noTone(BUZZER_PIN);
  
  delay(3000); // Display enjoy message for 3 seconds
  // 
}
