
#include <Arduino.h>
#include <LCDWIKI_KBV.h>
#include <LCDWIKI_GUI.h>
#include <TouchScreen.h>
#include "SimpleLCDTouchScreen.h"
#include "Color.h"

SimpleLCDTouchScreen my_lcd(ST7796S, A3, A2, A1, A0, A4); //model,cs,cd,wr,rd,reset
Line line(50,50,50,50+8*7-1, Color(0,255,0));
Line line2(50,50,50+8*4-1,50, Color(255,0,0));
Label label(50,50,"Patata", 8,Color(255,255,255));
Label label2(50,200,"Cocida", 8,Color(255,255,255), Color(100,100,100));
void setup() {
  Serial.begin(9600);
  delay(100);
    my_lcd.Init_LCD();
    my_lcd.Set_Rotation(3);
    my_lcd.Fill_Screen(0);
    //my_lcd.Fill_Screen(Color(255,0,0).to565());
    my_lcd.show(label);
    my_lcd.show(label2);
    my_lcd.show(line);
    my_lcd.show(line2);

    //Rectangle r1 = Rectangle(0,0,10,10,Color::RED,2,Color::RED);
    //Label l1 = Label(0,0,10,10,Color::RED,2,Color::RED,"Patata",7);
    //l1.show();
}

void loop() {

}

 //*/ #include "SimpleLCDTouchScreen_test.cpp"
