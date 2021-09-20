//
// Created by Víctor on 19/09/2021.
//

#include "ScreenObjectWithLabel.h"

ScreenObjectWithLabel::ScreenObjectWithLabel(int x, int y, Color mainColor, Label label):ScreenObject(x, y, mainColor)
{
    this->label = label;
    this->validLabel = true;
    this->margin = defaultMargin;
}

ScreenObjectWithLabel::ScreenObjectWithLabel(int x, int y, Color mainColor):ScreenObject(x, y, mainColor)
{

    this->label = Label(0, 0, "0", 0, Color(0,0,0));
    this->validLabel = false;
    this->margin = defaultMargin;
}

ScreenObjectWithLabel::ScreenObjectWithLabel()
{
    this->label = Label(0, 0, "0", 0, Color(0,0,0));
    this->validLabel = false;
    this->margin = defaultMargin;
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
}

// This function dynamicly set rectangle's label position and font size
// The algorythm used is a little bit complex: the first part uses a predefined scheme of making the label to use 3/4 parts of the rectangle
// With that scheme, it gets the fontSize. The second part of the algorythm uses the fontSize to get the coords used to draw the label
void ScreenObjectWithLabel::updateLabelLocation(uint8_t margin)
{
    int wlen = strlen(getLabel().getString());
    int sizeX = getx1()-getx();
    int sizeY = gety1()-gety();
    int borderX = sizeX/margin;
    int borderY = sizeY/margin;
    int wordSizeX = sizeX-2*borderX;
    int wordSizeY = sizeY-2*borderY;
    int fontSizeX = wordSizeX/((wlen-1)*(blockSizeX+1)+blockSizeX);
    int fontSizeY = wordSizeY/blockSizeY;
    int fontSize = fontSizeX<fontSizeY?fontSizeX:fontSizeY;

    wordSizeX = ((wlen-1)*(blockSizeX+1)+blockSizeX)*fontSize;
    wordSizeY = blockSizeY*fontSize;

    borderX = (sizeX - wordSizeX)/2;
    borderY = (sizeY - wordSizeY)/2;

    if (getLabel().isAValidSecondaryColor())
    {
        Label newLabel = Label(getx()+borderX,gety()+borderY,getLabel().getString(),fontSize,getLabel().getMainColor(),getLabel().getSecondaryColor());
        setLabel(newLabel);
    }
    else
    {
        Label newLabel = Label(getx()+borderX,gety()+borderY,getLabel().getString(),fontSize,getLabel().getMainColor());
        setLabel(newLabel);
    }
}

int ScreenObjectWithLabel::getMargin()
{
    return margin;
}

void ScreenObjectWithLabel::setMargin(int margin)
{
    this->margin = margin;
}
