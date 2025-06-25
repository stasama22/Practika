import cv2
import numpy as np
image = cv2.imread('test2.jpg')
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
# Определение диапазонов цветов в HSV
lower_green = np.array([35, 50, 50])
upper_green = np.array([85, 255, 255])
lower_yellow = np.array([20, 50, 50])
upper_yellow = np.array([35, 255, 255])
# Создание масок для цветов
mask_green = cv2.inRange(hsv, lower_green, upper_green)
mask_yellow = cv2.inRange(hsv, lower_yellow, upper_yellow)
# Нахождение контуров
contours_green, _ = cv2.findContours(mask_green, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
contours_yellow, _ = cv2.findContours(mask_yellow, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
# Обработка зелёных объектов
for cnt in contours_green:
    # Получаем ограничивающий прямоугольник
    x, y, w, h = cv2.boundingRect(cnt)
    # Центр прямоугольника = (x + w//2, y + h//2)
    cX, cY = x + w // 2, y + h // 2
    # Рисуем контур синим
    cv2.drawContours(image, [cnt], -1, (255, 0, 0), 2)
    # Рисуем центр
    cv2.circle(image, (cX, cY), 5, (255, 0, 0), -1)
    cv2.putText(image, "Green", (cX - 20, cY - 20),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)
# Обработка жёлтых объектов
for cnt in contours_yellow:
    # Получаем ограничивающий прямоугольник
    x, y, w, h = cv2.boundingRect(cnt)
    # Центр прямоугольника = (x + w//2, y + h//2)
    cX, cY = x + w // 2, y + h // 2
    # Рисуем контур зелёным
    cv2.drawContours(image, [cnt], -1, (0, 255, 0), 2)
    # Рисуем центр
    cv2.circle(image, (cX, cY), 5, (0, 255, 0), -1)
    cv2.putText(image, "Yellow", (cX - 20, cY - 20),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
# Сохранение и отображение результата
cv2.imwrite('result.jpg', image)
cv2.imshow('Result', image)
cv2.waitKey(0)
cv2.destroyAllWindows()