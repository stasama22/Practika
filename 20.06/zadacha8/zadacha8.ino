#include <Adafruit_NeoPixel.h>

#define LED_PIN     6       // Пин для ленты NeoPixel
#define LED_COUNT   64      // 8x8 = 64 светодиода
#define BRIGHTNESS  100     // Яркость (0-255)
#define WIDTH       8       // Ширина матрицы
#define HEIGHT      8       // Высота матрицы

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Функция для преобразования координат (x,y) в индекс светодиода (змейкой)
int getPixelIndex(int x, int y) {
    return (y % 2 == 0) ? y * WIDTH + x : y * WIDTH + (WIDTH - 1 - x);
}

void setPixelXY(int x, int y, uint32_t color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        strip.setPixelColor(getPixelIndex(x, y), color);
    }
}

void setup() {
    strip.begin();
    strip.show();
    strip.setBrightness(BRIGHTNESS);
}

void loop() {
    showCross(3, strip.Color(0, 255, 0));  // Зелёный крестик на 3 секунды
    animatePulsingSquare(5);               // Анимация пульсирующего квадрата (5 циклов)
}

// Функция для отрисовки крестика (без изменений)
void showCross(unsigned long duration, uint32_t color) {
    uint8_t cross[8][8] = {
      {1,0,0,0,0,0,0,1},
      {0,1,0,0,0,0,1,0},
      {0,0,1,0,0,1,0,0},
      {0,0,0,1,1,0,0,0},
      {0,0,0,1,1,0,0,0},
      {0,0,1,0,0,1,0,0},
      {0,1,0,0,0,0,1,0},
      {1,0,0,0,0,0,0,1}
    };

    unsigned long start = millis();
    while (millis() - start < duration * 1000) {
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                setPixelXY(x, y, cross[y][x] ? color : 0);
            }
        }
        strip.show();
        delay(50);
    }
}

// Анимация пульсирующего квадрата (простое изменение размера)
void animatePulsingSquare(int cycles) {
    for (int cycle = 0; cycle < cycles; cycle++) {
        // Плавное увеличение квадрата (от 2x2 до 8x8)
        for (int size = 2; size <= 8; size += 2) {
            drawSquare(size, strip.Color(255, 0, 0)); // Красный квадрат
            delay(300);
            strip.clear();
        }
        // Плавное уменьшение квадрата (с зелёным цветом)
        for (int size = 6; size >= 2; size -= 2) {
            drawSquare(size, strip.Color(0, 255, 0)); // Зелёный квадрат
            delay(300);
            strip.clear();
        }
    }
}

// Рисуем квадрат с центром в середине матрицы
void drawSquare(int size, uint32_t color) {
    int startX = (WIDTH - size) / 2;
    int startY = (HEIGHT - size) / 2;

    for (int x = startX; x < startX + size; x++) {
        for (int y = startY; y < startY + size; y++) {
            setPixelXY(x, y, color);
        }
    }
    strip.show();
}