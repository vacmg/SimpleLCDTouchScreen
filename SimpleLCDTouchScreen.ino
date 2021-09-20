
#include <Arduino.h>
#include <LCDWIKI_KBV.h>
#include <LCDWIKI_GUI.h>
#include <TouchScreen.h>
#include "SimpleLCDTouchScreen.h"
#include "Color.h"

SimpleLCDTouchScreen my_lcd(ST7796S, A3, A2, A1, A0, A4); //model,cs,cd,wr,rd,reset
Line line(93,68,93,68+2*8-2, Color(0,255,0));
Line line2(93,68+2*8-2,93+2*6-2,68+2*8-2, Color(255,0,0));
Label label(60,60,"Patata", 8,Color(255,255,255));
Label label2(60,200,"Cocida", 8,Color(255,255,255), Color(100,100,100));
Rectangle rectangle(50,50,400,200,Color(0,255,255),Color(255,200,0),label);
Rectangle rectangle2(410,30,470,300,Color(0,255,255),Color(255,200,0),label);

void setup() {
  Serial.begin(9600);
  delay(100);
  //Serial.println(freeMemory());
    my_lcd.Init_LCD();
    my_lcd.Set_Rotation(3);
    my_lcd.Fill_Screen(0);
    //my_lcd.Fill_Screen(Color(255,0,0).to565());

    
    my_lcd.draw(rectangle);
    my_lcd.draw(rectangle2);

    //my_lcd.show(line);
    //my_lcd.show(line2);
    
    //Serial.println(freeMemory());
}
int i = 0;
void loop() 
{
    /*rectangle.setLabel(Label(i,80, "pepe",4,Color(0,255,100),Color(100,255,0)));
    my_lcd.show(rectangle);
    Serial.println(freeMemory());
    Serial.println(i);
    i++;
    //delay(1000);*/
}

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval;
#endif  // __arm__

int freeMemory() {
  char top;
#ifdef __arm__
  return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
  return &top - __brkval;
#else  // __arm__
  return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}

 //*/ #include "SimpleLCDTouchScreen_test.cpp"
