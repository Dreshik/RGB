#include "DreshikRGB.h"

LED::LED(uint8_t _pinR, uint8_t _pinG, uint8_t _pinB) { // конструктор
  pinR = _pinR;
  pinG = _pinG;
  pinB = _pinB;
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  workTimeMS = 0;
  workState = 1;
  mode = 0;
  wheel = 0;
  R = 0;
  G = 0;
  B = 0;
}
LED::tick(unsigned long _workTimeMS)
{
  
  if (workState) // если лента ВКЛ
  {
    analogWrite(pinR, R); // Обновляем состояние выводов
    analogWrite(pinG, G);
    analogWrite(pinB, B);
    if( (mode == 1) && (workTimeMS != _workTimeMS) ) // moveTo
    {
      R += alphs[0]; //Обрабатываем R
      if (abs(R - moveR) < 1)
      {
        R = moveR;
        alphs[0] = 0;
      }
      
      G += alphs[1]; ; //Обрабатываем G
      if (abs(G - moveG) < 1)
      {
        G = moveG;
        alphs[1] = 0;
      }

      
      B += alphs[2]; ; //Обрабатываем B
      if (abs(B - moveB) < 1)
      {
        B = moveB;
        alphs[2] = 0;
      }
      
      if ( (alphs[0] == 0) && (alphs[1] == 0) && (alphs[2] == 0) ) // Если все альфы = 0 => переход закочен
      mode = 0;
    }
    else if ( (mode == 2) & ((_workTimeMS - preTimeMS) > 100) ) // движение по кольцу
    {
      if (wheel++ > 1530)
        wheel = 0;
      setWheel(wheel);
      preTimeMS = _workTimeMS;
    }
  }
workTimeMS = _workTimeMS; // обновляем время работы ленты
}
LED::setRGB(uint8_t _R, uint8_t _G, uint8_t _B)
{
  R = _R;
  G = _G;
  B = _B;
  mode = 0;
}
void LED::setHEX(uint32_t _color)
{
  R = (_color >> 16) & 0xff;
  G = (_color >> 8) & 0xff;
  B = _color & 0xff;
  mode = 0;
}
void LED::moveTo(uint8_t _R, uint8_t _G, uint8_t _B, unsigned int _perTime)
{
  moveR = (float)_R;
  moveG = (float)_G;
  moveB = (float)_B;
  alphs[0] = (moveR - R)/_perTime;
  alphs[1] = (moveG - G)/_perTime;
  alphs[2] = (moveB - B)/_perTime;
  mode = 1; 
}
void LED::moveTo(uint32_t _color, unsigned int _perTime)
{
  moveR = (_color >> 16) & 0xff;
  moveG = (_color >> 8) & 0xff;
  moveB = _color & 0xff;
  alphs[0] = (moveR - R)/_perTime;
  alphs[1] = (moveG - G)/_perTime;
  alphs[2] = (moveB - B)/_perTime;
  mode = 1; 
}
void LED::setWheel(unsigned int _color)
{
  if (_color > 1530)
    _color = 1530;
  else if (_color < 0)
    _color = 0;
  if (_color <= 255) {           // красный макс, зелёный растёт
    R = 255;
    G = _color;
    B = 0;
  }
  else if (_color > 255 && _color <= 510) {   // зелёный макс, падает красный 
    R = 510 - _color;
    G = 255;
    B = 0;
  }
  else if (_color > 510 && _color <= 765) {   // зелёный макс, растёт синий
    R = 0;
    G = 255;
    B = _color - 510;
  }
  else if (_color > 765 && _color <= 1020) {  // синий макс, падает зелёный
    R = 0;
    G = 1020 - _color;
    B = 255;
  }
  else if (_color > 1020 && _color <= 1275) {   // синий макс, растёт красный
    R = _color - 1020;
    G = 0;
    B = 255;
  }
  else if (_color > 1275 && _color <= 1530) { // красный макс, падает синий
    R = 255;
    G = 0;
    B = 1530 - _color;
  }
}
void LED::moveWheel()
{
  mode = 2;
}
