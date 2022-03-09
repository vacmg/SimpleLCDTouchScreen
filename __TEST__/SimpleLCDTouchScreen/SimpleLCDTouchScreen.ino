
#include <Arduino.h>
#include <LCDWIKI_KBV.h>
#include <LCDWIKI_GUI.h>
#include <TouchScreen.h>
#include <SimpleLCDTouchScreen.h>
//#include "Color.h"

#define MEGA true

//circle, triangle, bitmap?

SimpleLCDTouchScreen my_lcd(ST7796S, A3, A2, A1, A0, A4); //model,cs,cd,wr,rd,reset
TouchScreenObject ts(8,A3,A2,9,300,320,480,3,924,111,58,935); // rx is the resistance between X+ and X- Use any multimeter to read it or leave it blanc
//TouchScreenObject ts(8,A3,A2,9,300,480,320,0,0,0,1023,1023); // rx is the resistance between X+ and X- Use any multimeter to read it or leave it blanc

//Line line(93,68,93,68+2*8-2, Color(0,255,0));
//Line line2(93,68+2*8-2,93+2*6-2,68+2*8-2, Color(255,0,0));
Label label(20,10,"Patata", 1,Color(255,255,255));
//Label label2(60,200,"45", 8,Color(255,255,255), Color(100,100,100));
//Rectangle rectangle(50,50,400,200,Color(0,255,255),Color(255,200,0),label);
//Rectangle rectangle2(410,30,470,300,Color(0,255,255),Color(255,200,0),label2);
//RectangleButton rectangleBtn(100,50,400,200,Color(0,255,255),Color(255,200,0),label, ts);
//RoundRectangle roundRectangle(50,100,400,250,20,Color(255,255,255),Color(0,255,40),label);
RoundRectangleButton roundRectangleBtn(50,100,400,250,20,Color(255,120,0),Color(0,255,40),&label,&ts);
//Picture picture(30,50,"test.bmp");
//Picture picture(30,50,"05v2.bmp");
//PictureButton pictureButton(150,50, "05v2.bmp",ts);
Picture picture(14,44,"schArd.bmp");


void setup() {
  Serial.begin(9600);
  delay(100);
  //Serial.println(freeMemory());
  #if MEGA
  my_lcd.set_sd_cs(53);
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  pinMode(10,INPUT);
  #else
  my_lcd.set_sd_cs(10);
  #endif
  my_lcd.Init_LCD();
    my_lcd.Set_Rotation(1);
     my_lcd.Fill_Screen(0);
    my_lcd.Fill_Screen(Color(255,255,255).to565());
    //my_lcd.Fill_Screen(Color(255,0,0).to565());
    //rectangleBtn
/*
    Serial.println(rectangleBtn.getx());
    Serial.println(rectangleBtn.gety());
    Serial.println(rectangleBtn.isAValidLabel());
    Serial.println(rectangleBtn.getMainColor().to565(),HEX);

    Serial.println('\n');*/

    // picture.init();
    my_lcd.draw(&picture); // ya no hace copia
    
    //my_lcd.draw(label);
    //my_lcd.draw(rectangle);
    //my_lcd.draw(rectangle2);
    //my_lcd.draw(rectangleBtn);
    //my_lcd.draw(roundRectangle);
    //my_lcd.draw(&roundRectangleBtn);
    
    //Serial.println(picture.getx1());
    //Serial.println(picture.gety1());

    /*pictureButton.init();
    my_lcd.draw(pictureButton);
    Serial.println(pictureButton.getx1());
    Serial.println(pictureButton.gety1());*/
    //Serial.println(my_lcd.draw(picture));

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
    i++;*/
    delay(10);
    //rectangleBtn.isPressed();
    /*if(rectangleBtn.isPressed())
    Serial.println("Boton pulsado");
    /*if(pictureButton.isPressed())
        Serial.println("Boton pulsado");*/
    if(roundRectangleBtn.isPressed())
        Serial.println("Boton pulsado");
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