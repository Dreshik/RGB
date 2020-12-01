#include <DreshikRGB.h>
LED myLed(3, 5, 6); // Инициализируем ленту pinR = 3, pinG = 5, pinB = 6
void setup() {
myLed.setWheel(845); // Устанавливаем позицию на цветовом круге (от 0 до 1530)
}

void loop() {
myLed.tick(millis()); // Сообщаем ленте текущее время
}
