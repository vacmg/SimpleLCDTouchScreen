#include <Arduino.h>
#include <LCDWIKI_KBV.h>
#include <LCDWIKI_GUI.h>
#include <TouchScreen.h>
#include "SimpleLCDTouchScreen.h"
#include "Color.h"
#include "Rectangle.h"
#include "Label.h"

SimpleLCDTouchScreen my_lcd(ST7796S, A3, A2, A1, A0, A4); //model,cs,cd,wr,rd,reset

void setup() {
    my_lcd.Init_LCD();
    //Rectangle r1 = Rectangle(0,0,10,10,Color::RED,2,Color::RED);
    //Label l1 = Label(0,0,10,10,Color::RED,2,Color::RED,"Patata",7);
    //l1.show();
}

void loop() {

}
