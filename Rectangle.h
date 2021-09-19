//
// Created by Víctor on 19/09/2021.
//

#ifndef SIMPLELCDTOUCHSCREEN_RECTANGLE_H
#define SIMPLELCDTOUCHSCREEN_RECTANGLE_H
#include "ScreenObjectWithSecondaryColor.h"
#include "ScreenObjectWithLabel.h"
#include "ScreenObjectWithXtraCoords.h"

class Rectangle: public ScreenObjectWithSecondaryColor, public ScreenObjectWithLabel, public ScreenObjectWithXtraCoords
{
public:
    Rectangle(int x, int y, int x1, int y1, Color mainColor, Color secondaryColor, Label label);
    Rectangle(int x, int y, int x1, int y1, Color mainColor, Color secondaryColor);
    Rectangle(int x, int y, int x1, int y1, Color mainColor, Label label);
    Rectangle(int x, int y, int x1, int y1, Color mainColor);

private:
    void updateLabelLocation();
};


#endif //SIMPLELCDTOUCHSCREEN_RECTANGLE_H
