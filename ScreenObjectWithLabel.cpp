//
// Created by Víctor on 19/09/2021.
//

#include "ScreenObjectWithLabel.h"

ScreenObjectWithLabel::ScreenObjectWithLabel(int x, int y, Color mainColor, Label label):ScreenObject(x, y, mainColor)
{
    this->label = label;
    this->validLabel = true;
}

ScreenObjectWithLabel::ScreenObjectWithLabel(int x, int y, Color mainColor):ScreenObject(x, y, mainColor)
{

    this->label = Label(0, 0, "0", 0, Color(0,0,0));
    this->validLabel = false;
}

ScreenObjectWithLabel::ScreenObjectWithLabel()
{
    this->label = Label(0, 0, "0", 0, Color(0,0,0));
    this->validLabel = false;
}

Label ScreenObjectWithLabel::getLabel()
{
    return label;
}

bool ScreenObjectWithLabel::isAValidLabel()
{
    return validLabel;
}

void ScreenObjectWithLabel::setLabel(Label label)
{
    this->label = label;
}//*/

