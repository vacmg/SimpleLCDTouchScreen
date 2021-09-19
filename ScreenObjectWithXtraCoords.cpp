//
// Created by Víctor on 19/09/2021.
//

#include "ScreenObjectWithXtraCoords.h"

ScreenObjectWithXtraCoords::ScreenObjectWithXtraCoords(int x, int y, int x1, int y1, Color mainColor): ScreenObject(x, y, mainColor)
{
    this->x1 = x1;
    this->y1 = y1;
}

int ScreenObjectWithXtraCoords::getx1()
{
    return x1;
}

int ScreenObjectWithXtraCoords::gety1()
{
    return y1;
}

int ScreenObjectWithXtraCoords::setCoords1(int x1, int y1)
{
    this->x1 = x1;
    this->y1 = y1;
}

ScreenObjectWithXtraCoords::ScreenObjectWithXtraCoords()
{
    this->x1 = 0;
    this->y1 = 0;
}
