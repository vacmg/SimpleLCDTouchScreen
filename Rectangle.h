//
// Created by Víctor on 13/09/2021.
//

#ifndef SIMPLELCDTOUCHSCREEN_RECTANGLE_H
#define SIMPLELCDTOUCHSCREEN_RECTANGLE_H

#include "SimpleLCDTouchScreen.h"
#include <LCDWIKI_KBV.h>


class Rectangle
{
public:
    Rectangle()
    {
        this->x = 0;
        this->y = 0;
        this->tam_x = 0;
        this->tam_y = 0;
        this->fillColor = Color();
        this->borderSize = 0;
        this->borderColor = Color();
    }
    Rectangle(int x, int y, int tam_x, int tam_y, Color fillColor, int borderSize, Color borderColor)
    {
        this->x = x;
        this->y = y;
        this->tam_x = tam_x;
        this->tam_y = tam_y;
        this->fillColor = fillColor;
        this->borderSize = borderSize;
        this->borderColor = borderColor;
    }

    /*void show()
    {
        LCDWIKI_KBV mylcd = SimpleLCDTouchScreen::getLcd();
        mylcd.Set_Draw_color(borderColor.to565());
        mylcd.Draw_Rectangle(x,y,x+tam_x,y+tam_y);
    }//*/

private:
    int x;
    int y;
    int tam_x;
    int tam_y;
    int borderSize;
    Color fillColor;
    Color borderColor;
};


#endif //SIMPLELCDTOUCHSCREEN_RECTANGLE_H
