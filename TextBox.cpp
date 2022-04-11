//
// Created by Víctor on 10/04/2022.
//

#include "TextBox.h"


TextBox::TextBox(int x, int y, int x1, int y1, char *textPath, uint32_t beginOffset, uint32_t endOffset, Rectangle *container, Color mainColor, Color secondaryColor): ScreenObjectWithSecondaryColor(x,y,mainColor,secondaryColor), ScreenObjectWithXtraCoords(x,y,x1,y1,mainColor)
{
    this->textPath = textPath;
    this->beginOffset = beginOffset;
    this->endOffset = endOffset;
    this->RRcontainer = nullptr;
    this->Rcontainer = container;
}

TextBox::TextBox(int x, int y, int x1, int y1, char *textPath, uint32_t beginOffset, uint32_t endOffset, Rectangle *container, Color mainColor): ScreenObjectWithSecondaryColor(x,y,mainColor), ScreenObjectWithXtraCoords(x,y,x1,y1,mainColor)
{
    this->textPath = textPath;
    this->beginOffset = beginOffset;
    this->endOffset = endOffset;
    this->RRcontainer = nullptr;
    this->Rcontainer = container;
}

TextBox::TextBox(int x, int y, int x1, int y1, char *textPath, Rectangle *container, Color mainColor, Color secondaryColor): ScreenObjectWithSecondaryColor(x,y,mainColor,secondaryColor), ScreenObjectWithXtraCoords(x,y,x1,y1,mainColor)
{
    this->textPath = textPath;
    this->beginOffset = 0;
    this->endOffset = 0;
    this->RRcontainer = nullptr;
    this->Rcontainer = container;
}

TextBox::TextBox(int x, int y, int x1, int y1, char *textPath, Rectangle *container, Color mainColor): ScreenObjectWithSecondaryColor(x,y,mainColor), ScreenObjectWithXtraCoords(x,y,x1,y1,mainColor)
{
    this->textPath = textPath;
    this->beginOffset = 0;
    this->endOffset = 0;
    this->RRcontainer = nullptr;
    this->Rcontainer = container;
}

TextBox::TextBox(int x, int y, int x1, int y1, char *textPath, uint32_t beginOffset, uint32_t endOffset, RoundRectangle *container, Color mainColor, Color secondaryColor): ScreenObjectWithSecondaryColor(x,y,mainColor,secondaryColor), ScreenObjectWithXtraCoords(x,y,x1,y1,mainColor)
{
    this->textPath = textPath;
    this->beginOffset = beginOffset;
    this->endOffset = endOffset;
    this->RRcontainer = container;
    this->Rcontainer = nullptr;
}

TextBox::TextBox(int x, int y, int x1, int y1, char *textPath, uint32_t beginOffset, uint32_t endOffset, RoundRectangle *container, Color mainColor): ScreenObjectWithSecondaryColor(x,y,mainColor), ScreenObjectWithXtraCoords(x,y,x1,y1,mainColor)
{
    this->textPath = textPath;
    this->beginOffset = beginOffset;
    this->endOffset = endOffset;
    this->RRcontainer = container;
    this->Rcontainer = nullptr;
}

TextBox::TextBox(int x, int y, int x1, int y1, char *textPath, RoundRectangle *container, Color mainColor, Color secondaryColor): ScreenObjectWithSecondaryColor(x,y,mainColor,secondaryColor), ScreenObjectWithXtraCoords(x,y,x1,y1,mainColor)
{
    this->textPath = textPath;
    this->beginOffset = 0;
    this->endOffset = 0;
    this->RRcontainer = container;
    this->Rcontainer = nullptr;
}

TextBox::TextBox(int x, int y, int x1, int y1, char *textPath, RoundRectangle *container, Color mainColor): ScreenObjectWithSecondaryColor(x,y,mainColor), ScreenObjectWithXtraCoords(x,y,x1,y1,mainColor)
{
    this->textPath = textPath;
    this->beginOffset = 0;
    this->endOffset = 0;
    this->RRcontainer = container;
    this->Rcontainer = nullptr;
}


byte TextBox::getFontSize()
{
    File file = SD.open(textPath, FILE_READ);
    if(file)
    {
        file.seek(beginOffset);
        uint32_t length = endOffset - beginOffset;
        uint32_t xpx = getx1()-getx();
        uint32_t ypx = gety1()-gety();

        uint16_t newLines; //todo sacar numero de intros

        //todo comprobar length>0, xpx>0, ypx>0, spacing>0

        byte maxFontSize = (-5*length*spacing)+(5*newLines*spacing)-(7*newLines*xpx)+sqrt((49*pow(newLines,2)*pow(xpx,2))-(70*pow(newLines,2)*length*spacing*xpx)+(70*pow(newLines,2)*spacing*xpx)+(140*length*xpx*ypx)-(140*newLines*xpx*ypx)+(25*pow(length,2)*pow(spacing,2))-(50*newLines*length*pow(spacing,2))+(25*pow(newLines,2)*pow(spacing,2)))/(2*(35*length-35*newLines));

        for (byte font = maxFontSize-1; font>0; font--)
        {
            // todo prueba y error para colocar las palabras
        }
    }
}

uint16_t TextBox::maxAmountOfLines(uint16_t ypx, byte font)
{
    return ypx/((7*font)+spacing);
}
