#pragma once
#include <Arduino.h>
enum colors {
BLACK = 0x000000,
GRAY = 0x808080,
SILVER = 0xC0C0C0,
WHITE = 0xFFFFFF,
FUCHSIA = 0xFF00FF,
PURPLE = 0x800080,
RED = 0xFF0000,
MAROON = 0x800000,
YELLOW = 0xFFFF00,
OLIVE = 0x808000,
LIME = 0x00FF00,
GREEN = 0x008000,
AQUA = 0x00FFFF,
TEAL = 0x008080,
BLUE = 0x0000FF,
NAVY = 0x000080,
};
class LED {   
public:
  LED(uint8_t pinR, uint8_t pinG, uint8_t pinB);
  tick(unsigned long _workTimeMS);
  setRGB(uint8_t _R,uint8_t _G, uint8_t _B);
  void setHEX(uint32_t _color);
  void moveTo(uint8_t _R, uint8_t _G, uint8_t _B, unsigned int _perTime);
  void moveTo(uint32_t _color, unsigned int _perTime);
  void moveWheel();
  void setWheel(unsigned int _color);
  void setWheelTime(unsigned int _wheelTime);
private:
  float R,G,B;
  uint8_t moveR, moveG, moveB;
  uint8_t pinR, pinG, pinB;
  uint8_t mode;
  bool workState; // состояние ленты ВКЛ/ВЫКЛ
  unsigned long workTimeMS; // время работы ленты
  unsigned long preTimeMS; // время последнего события
  unsigned int wheel; // Положение на кольце
  unsigned int wheelTime; // Период смены положения на кольце
  float alphs[3]; // Коэффициенты для плавного перехода процедуры moveTo
  
  
};
