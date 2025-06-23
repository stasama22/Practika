#define GREEN_LED_PIN 9       // Зелёный светодиод - двери открыты
#define RED_LED_PIN 5         // Красный светодиод - двери закрыты
#define SENSOR_PIN A0         // Фоторезистор

// Время, на которое двери остаются открытыми (3 секунды)
const unsigned long DOOR_OPEN_DURATION = 3000;

// Пороговое значение для определения приближения (512 - среднее значение)
const int PRESENCE_THRESHOLD = 512;

// Состояние дверей
enum DoorState {
  DOOR_CLOSED,
  DOOR_OPEN,
  DOOR_HOLD_OPEN
};
DoorState currentState = DOOR_CLOSED;

unsigned long doorOpenTime = 0; // Время, когда двери были открыты

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  Serial.begin(9600);

  // Инициализация - двери закрыты
  setDoorsClosed();
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  Serial.print("Значение с фоторезистора: ");
  Serial.println(sensorValue);

  switch(currentState) {
    case DOOR_CLOSED:
      handleClosedState(sensorValue);
      break;
    case DOOR_OPEN:
      handleOpenState(sensorValue);
      break;
    case DOOR_HOLD_OPEN:
      handleHoldOpenState(sensorValue);
      break;
  }

  delay(200); // Небольшая задержка для стабильности
}

void handleClosedState(int sensorValue) {
  if (sensorValue < PRESENCE_THRESHOLD) {
    // Обнаружено присутствие - открываем двери
    setDoorsOpen();
    doorOpenTime = millis();
    currentState = DOOR_OPEN;
    Serial.println("Обнаружен человек - двери открываются");
  }
}

void handleOpenState(int sensorValue) {
  // Проверяем, истекло ли время открытия
  if (millis() - doorOpenTime >= DOOR_OPEN_DURATION) {
    if (sensorValue < PRESENCE_THRESHOLD) {
      // Человек всё ещё рядом - остаёмся открытыми
      currentState = DOOR_HOLD_OPEN;
      Serial.println("Человек всё ещё рядом - двери остаются открытыми");
    } else {
      // Человек ушёл - закрываем двери
      setDoorsClosed();
      currentState = DOOR_CLOSED;
      Serial.println("Человек ушёл - двери закрываются");
    }
  }
}

void handleHoldOpenState(int sensorValue) {
  if (sensorValue >= PRESENCE_THRESHOLD) {
    // Человек ушёл - закрываем двери
    setDoorsClosed();
    currentState = DOOR_CLOSED;
    Serial.println("Человек ушёл - двери закрываются");
  }
}

void setDoorsOpen() {
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
}

void setDoorsClosed() {
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);
}