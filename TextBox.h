//
// Created by Víctor on 10/04/2022.
//

#ifndef SIMPLELCDTOUCHSCREEN_TEXTBOX_H
#define SIMPLELCDTOUCHSCREEN_TEXTBOX_H
#include "ScreenObjectWithXtraCoords.h"
#include "ScreenObjectWithSecondaryColor.h"
#include "Rectangle.h"
#include "RoundRectangle.h"

#include "SD/src/SD.h" // todo remove this

class TextBox: virtual public ScreenObjectWithXtraCoords, virtual public ScreenObjectWithSecondaryColor
{
public:
    TextBox(int x, int y, int x1, int y1, char* textPath, uint32_t beginOffset, uint32_t endOffset, Rectangle* container, Color mainColor, Color secondaryColor);
    TextBox(int x, int y, int x1, int y1, char* textPath, uint32_t offset, uint32_t endOffset, Rectangle* container, Color mainColor);
    TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* container, Color mainColor, Color secondaryColor);
    TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* container, Color mainColor);

    TextBox(int x, int y, int x1, int y1, char* textPath, uint32_t offset, uint32_t endOffset, RoundRectangle* container, Color mainColor, Color secondaryColor);
    TextBox(int x, int y, int x1, int y1, char* textPath, uint32_t offset, uint32_t endOffset, RoundRectangle* container, Color mainColor);
    TextBox(int x, int y, int x1, int y1, char* textPath, RoundRectangle* container, Color mainColor, Color secondaryColor);
    TextBox(int x, int y, int x1, int y1, char* textPath, RoundRectangle* container, Color mainColor);

    byte getFontSize();

private:
    char* textPath;
    uint32_t beginOffset;
    uint32_t endOffset;
    Rectangle* Rcontainer;
    RoundRectangle* RRcontainer;
    static const byte spacing = 7;

    uint16_t maxAmountOfLines(uint16_t ypx,byte font);
};


#endif //SIMPLELCDTOUCHSCREEN_TEXTBOX_H
