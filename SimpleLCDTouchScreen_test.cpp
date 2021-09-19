
#include <Arduino.h>
#include <LCDWIKI_KBV.h>
#include <LCDWIKI_GUI.h>
#include <TouchScreen.h>
#include "SimpleLCDTouchScreen.h"
#include "Color.h"
/*
SimpleLCDTouchScreen my_lcd(ST7796S, A3, A2, A1, A0, A4); //model,cs,cd,wr,rd,reset
//Line l(0,0,100,100, Color(255,255,255));

void setup() {
    my_lcd.Init_LCD();
    my_lcd.Fill_Screen(Color(0,0,0).to565());
    //my_lcd.show(l);
    //Rectangle r1 = Rectangle(0,0,10,10,Color::RED,2,Color::RED);
    //Label l1 = Label(0,0,10,10,Color::RED,2,Color::RED,"Patata",7);
    //l1.show();
}

void loop() {

}

//*/ //#include "SimpleLCDTouchScreen.ino"
