//
// Created by Víctor on 19/09/2021.
//

#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int x1, int y1, Color mainColor, Color secondaryColor, Label label): ScreenObjectWithLabel(x,y, mainColor, label), ScreenObjectWithSecondaryColor(x, y, mainColor, secondaryColor), ScreenObjectWithXtraCoords(x, y, x1, y1, mainColor), ScreenObject(x, y, mainColor)
{
    setMargin(rectangleMargin);
    updateLabelLocation(getMargin());
}

Rectangle::Rectangle(int x, int y, int x1, int y1, Color mainColor, Color secondaryColor): ScreenObjectWithLabel(x,y, mainColor), ScreenObjectWithSecondaryColor(x, y, mainColor, secondaryColor), ScreenObjectWithXtraCoords(x, y, x1, y1, mainColor), ScreenObject(x, y, mainColor)
{
    setMargin(rectangleMargin);
    updateLabelLocation(getMargin());
}

Rectangle::Rectangle(int x, int y, int x1, int y1, Color mainColor, Label label): ScreenObjectWithLabel(x,y, mainColor, label), ScreenObjectWithSecondaryColor(x, y, mainColor), ScreenObjectWithXtraCoords(x, y, x1, y1, mainColor), ScreenObject(x, y, mainColor)
{
    setMargin(rectangleMargin);
    updateLabelLocation(getMargin());
}

Rectangle::Rectangle(int x, int y, int x1, int y1, Color mainColor): ScreenObjectWithLabel(x,y, mainColor), ScreenObjectWithSecondaryColor(x, y, mainColor), ScreenObjectWithXtraCoords(x, y, x1, y1, mainColor), ScreenObject(x, y, mainColor)
{
    setMargin(rectangleMargin);
    updateLabelLocation(getMargin());
}

void Rectangle::setCoords(int x, int y) {
    ScreenObject::setCoords(x, y);
    updateLabelLocation(getMargin());
}

void Rectangle::setCoords1(int x, int y) {
    ScreenObjectWithXtraCoords::setCoords1(x, y);
    updateLabelLocation(getMargin());
}
