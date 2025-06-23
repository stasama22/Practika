#include <Servo.h>

// Константы
const byte SERVO_PIN = 3;       // Пин сервопривода
const int DEFAULT_ANGLE = 90;   // Стартовое положение
const int MIN_ANGLE = 0;        // Минимальный угол
const int MAX_ANGLE = 180;      // Максимальный угол
const int DELAY_STEP = 15;      // Задержка между шагами (мс)

// Глобальные переменные
Servo myServo;
int currentAngle = DEFAULT_ANGLE;
int targetAngle = DEFAULT_ANGLE;

void setup() {
  Serial.begin(9600);
  while (!Serial); // Ожидание подключения Serial (для Arduino Leonardo)
  
  myServo.attach(SERVO_PIN);
  myServo.write(DEFAULT_ANGLE);
  
  printWelcomeMessage();
}

void loop() {
  handleSerialInput();
  updateServoPosition();
}

void handleSerialInput() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    if (input.length() > 0) {
      processAngleInput(input);
    }
  }
}

void processAngleInput(String input) {
  if (isValidNumber(input)) {
    int angle = input.toInt();
    
    if (angle >= MIN_ANGLE && angle <= MAX_ANGLE) {
      if (angle != currentAngle) {
        targetAngle = angle;
        Serial.print("Принят новый угол: ");
        Serial.println(targetAngle);
      } else {
        Serial.println("Сервопривод уже в этом положении");
      }
    } else {
      Serial.println("Ошибка: угол должен быть от 0 до 180");
    }
  } else {
    Serial.println("Ошибка: введите целое число");
  }
}

bool isValidNumber(String str) {
  for (byte i = 0; i < str.length(); i++) {
    if (!isDigit(str.charAt(i))) {
      return false;
    }
  }
  return str.length() > 0;
}

void updateServoPosition() {
  if (currentAngle != targetAngle) {
    int step = (targetAngle > currentAngle) ? 1 : -1;
    currentAngle += step;
    myServo.write(currentAngle);
    delay(DELAY_STEP);
  }
}

void printWelcomeMessage() {
  Serial.println("Система управления сервоприводом");
  Serial.println("--------------------------------");
  Serial.println("Введите угол от 0 до 180 градусов");
  Serial.println("Текущее положение: " + String(DEFAULT_ANGLE));
  Serial.println("--------------------------------");
}