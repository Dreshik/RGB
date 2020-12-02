#include <DreshikRGB.h>
LED myLed(3, 5, 6); // Инициализируем ленту pinR = 3, pinG = 5, pinB = 6
void setup() {
Serial.begin(9600); // Включаем последовательный интерфейс
}

void loop() {
  myLed.tick(millis()); // Сообщаем ленте текущее время
  if (Serial.available()) // Если пришёл символ
  {
    uint8_t c = Serial.read(); // Читаем символ
    switch (c)
    {
      case 'r':
        myLed.moveTo(255, 0, 0, 5000);  // Устанавливаем красный цвет в формате RGB за 5 секунд
        break;
      case 'g':
        myLed.moveTo(0, 250, 0, 5000);  // Устанавливаем зелёный цвет в формате RGB за 5 секунд
        break;
      case 'b':
        myLed.moveTo(0, 0, 255, 5000);  // Устанавливаем синий цвет в формате RGB за 5 секунд
        break;
      case 'w':
        myLed.moveTo(255, 255, 255, 5000);  // Устанавливаем белый цвет в формате RGB за 5 секунд
        break;
      case 'c':
        myLed.moveWheel();  // Включаем движение по цветовому кругу
        break;
    } 
  }
}
