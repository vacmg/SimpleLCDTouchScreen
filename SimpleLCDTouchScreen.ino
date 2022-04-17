/*
 * Library test file
 */

#include <Arduino.h>
#include <LCDWIKI_KBV.h>
#include <LCDWIKI_GUI.h>
#include <TouchScreen.h>
#include "SimpleLCDTouchScreen.h"

#define MEGA true
#define ROTATION 3

//circle, triangle, bitmap?

SimpleLCDTouchScreen my_lcd(ST7796S, A3, A2, A1, A0, A4); //model,cs,cd,wr,rd,reset
//TouchScreenObject ts(8,A3,A2,9,300,320,480,3,924,111,58,935); // rx is the resistance between X+ and X- Use any multimeter to read it or leave it blanc
TouchScreenObject ts(9,A2,A3,8,300,320,480,(ROTATION+1)%4,177,900,157,958); // for 3.5inch
//TouchScreenObject ts(8,A3,A2,9,300,480,320,0,0,0,1023,1023); // rx is the resistance between X+ and X- Use any multimeter to read it or leave it blanc

//Line line(93,68,93,68+2*8-2, Color(0,255,0));
//Line line2(93,68+2*8-2,93+2*6-2,68+2*8-2, Color(255,0,0));
//Label label(20,10,"Patata", 1,Color(255,255,255));
//Label label2(60,200,"45", 8,Color(255,255,255), Color(100,100,100));
//Rectangle rectangle(50,50,400,200,Color(0,255,255),Color(255,200,0),label);
//Rectangle rectangle2(410,30,470,300,Color(0,255,255),Color(255,200,0),label2);
//RectangleButton rectangleBtn(100,50,400,200,Color(0,255,255),Color(255,200,0),label, ts);
//RectangleButton rboton(1,1,200,200,Color(0,0,255),Color(255,0,0),&ts);
//RoundRectangle roundRectangle(50,100,400,250,20,Color(255,255,255),Color(0,255,40),label);
//RoundRectangleButton roundRectangleBtn(50,100,400,250,20,Color(255,120,0),Color(0,255,40),&label,&ts);
//Picture picture(30,50,"test.bmp");
//Picture picture(30,50,"05v2.bmp");
//PictureButton pictureButton(150,50, "05v2.bmp",ts);
//Picture picture(14,44,"schArd.bmp");
Label label3(0,0,"No Debo Salir",1,Color(0));
Rectangle rectangle3(0,0,1,1,Color(0),Color(240,240,240));
TextBox textBox(20,20,460,300,"test.txt",&rectangle3,&label3,10,2,30);


void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("Connected");
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
    my_lcd.Set_Rotation(ROTATION);
    //ts.setRotation(ROTATION);
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
    /*char* patata = (char*) malloc(500*sizeof(byte));//6500
    if(patata == NULL)
    Serial.println("Dale menos");
    unsigned long b4 = millis();
    my_lcd.draw(&picture); // ya no hace copia
    unsigned long after = millis();
    Serial.println(after-b4);
    //my_lcd.Fill_Screen(Color(255,255,255).to565());
    free(patata);*/

    //my_lcd.draw(&rboton);
    
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
    textBox.print(&Serial);
    textBox.printAll(&Serial);
    my_lcd.draw(&textBox);

}
int i = 0;
void loop() 
{
    /*rectangle.setLabel(Label(i,80, "pepe",4,Color(0,255,100),Color(100,255,0)));
    my_lcd.show(rectangle);
    Serial.println(freeMemory());
    Serial.println(i);
    i++;*/
    //delay(10);
    //rectangleBtn.isPressed();
    /*if(rectangleBtn.isPressed())
    Serial.println("Boton pulsado");
    /*if(pictureButton.isPressed())
        Serial.println("Boton pulsado");*/
    /*if(roundRectangleBtn.isPressed())
        Serial.println("Boton pulsado");*/
    /*if(rboton.isPressed())
    {
        rboton.setSecondaryColor(Color(0,255,0));
        my_lcd.draw(&rboton);
        delay(100);
        while (rboton.isPressed());
        rboton.setSecondaryColor(Color(255,0,0));
        my_lcd.draw(&rboton);
    }*/
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
