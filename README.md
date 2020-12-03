# RGB для Arduino V0.1.1
Особенностью данной библиотеки является полное отсутствие dilay и прочих вещей, тормозящих работу целого микроконтроллера.
# Важная особенность библиотеки
Для корректной работы большинства функций библиотеки, объекту LED требуется знать текущее время работы микроконтроллера в мс. Для этого в цикле loop нужно прописать myLed.tick(millis());
# Функции
LED(pinR, pinG, pinB) - конструктор класса ленты  
myLed.tick(millis()) - обновление состояния ленты  
setRGB(R, G, B) - устанавливает цвет в формате RGB  
setHEX(colorHEX) -  устанавливает цвет в формате HEX  
moveTo(R, G, B, time) - устанавливает цвет в формате RGB за время time(мс)  
moveTo(colorHEX, time) - устанавливает цвет в формате HEX за время time(мс)  
moveWheel() - Включает плавное движение по цветовому кругу  
setWheel(pos) - Устанавливает позицию на цветовом круге (от 0 до 1530)  
# Обновление 0.1.1
-- Исправлены мелкие недочеты  
-- Теперь яркость R,G,B компонент  по-умолчанию равна нулю  
-- Добавлен метод установки периода инкремента положения на цветовом кольце setWheelTime(unsigned int _wheelTime)  
