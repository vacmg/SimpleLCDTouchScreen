//
// Created by Víctor on 13/09/2021.
//

#ifndef SIMPLELCDTOUCHSCREEN_LABEL_H
#define SIMPLELCDTOUCHSCREEN_LABEL_H
#include "Rectangle.h"

class Label: public Rectangle
{
public:
    Label():Rectangle()
    {
        this->string = nullptr;
        this->stringSize = 0;
    }
    Label(int x, int y, int tam_x, int tam_y, Color fillColor, int borderSize, Color borderColor, char* string, int stringSize): Rectangle(x,y,tam_x,tam_y,fillColor,borderSize,borderColor)
    {
        this->string = string;
        this->stringSize = stringSize;
    }
    Label(int x, int y, int tam_x, int tam_y, Color fillColor, int borderSize, Color borderColor)
    {
        this->string = string;
        this->stringSize = stringSize;
    }

    /*void show()
    {
        Rectangle::show();
        // todo print stuff
    }//*/

private:
    char* string;
    int stringSize;
};


#endif //SIMPLELCDTOUCHSCREEN_LABEL_H
