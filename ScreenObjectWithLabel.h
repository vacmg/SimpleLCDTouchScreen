//
// Created by Víctor on 19/09/2021.
//

#ifndef SIMPLELCDTOUCHSCREEN_SCREENOBJECTWITHLABEL_H
#define SIMPLELCDTOUCHSCREEN_SCREENOBJECTWITHLABEL_H
#include "ScreenObject.h"
#include "Label.h"


class ScreenObjectWithLabel: virtual public ScreenObject
{
public:
    ScreenObjectWithLabel(int x, int y, Color mainColor, Label label);
    ScreenObjectWithLabel(int x, int y, Color mainColor);
    ScreenObjectWithLabel();
    bool isAValidLabel();
    Label getLabel();
    void setLabel(Label label);
private:
    //void updateLabelLocation();
    Label label;
    bool validLabel;
};


#endif //SIMPLELCDTOUCHSCREEN_SCREENOBJECTWITHLABEL_H
