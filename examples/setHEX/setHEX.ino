#include <DreshikRGB.h>
LED myLed(3, 5, 6); // Инициализируем ленту pinR = 3, pinG = 5, pinB = 6
void setup() {
myLed.setHEX(0x008080); // Устанавливаем бирюзовый цвет
}

void loop() {
myLed.tick(millis()); // Сообщаем ленте текущее время
}
