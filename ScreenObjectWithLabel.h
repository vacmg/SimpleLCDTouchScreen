//
// Created by Víctor on 19/09/2021.
//

#ifndef SIMPLELCDTOUCHSCREEN_SCREENOBJECTWITHLABEL_H
#define SIMPLELCDTOUCHSCREEN_SCREENOBJECTWITHLABEL_H
#include <ScreenObjectWithXtraCoords.h>
#include <Label.h>


class ScreenObjectWithLabel: virtual public ScreenObjectWithXtraCoords
{
public:
    ScreenObjectWithLabel(int x, int y, Color mainColor, Label label);
    ScreenObjectWithLabel(int x, int y, Color mainColor);
    ScreenObjectWithLabel();
    bool isAValidLabel();
    Label getLabel();
    void setLabel(Label label);
    void updateLabelLocation(uint8_t margin);
    int getMargin();
    void setMargin(int margin);
private:
    static const uint8_t blockSizeX = 5;
    static const uint8_t blockSizeY = 7;
    Label label;
    bool validLabel;
    int margin;
    static const int defaultMargin = 8;
};


#endif //SIMPLELCDTOUCHSCREEN_SCREENOBJECTWITHLABEL_H
