//
// Created by Víctor on 10/04/2022.
//

#include "TextBox.h"

TextBox::TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label *label, byte spacing, uint32_t beginOffset, uint32_t endOffset): ScreenObject(x,y,Color())
{
    this->textPath = textPath;
    this->spacing = spacing;
    this->beginOffset = beginOffset;
    this->endOffset = endOffset;
    this->fontSize = calculateFontSize();
    this->label = label;
    this->frame = frame;

    frame->setCoords(x,y);
    frame->setCoords1(x1,y1);
}

TextBox::TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label *label, uint32_t beginOffset, uint32_t endOffset): ScreenObject(x,y,Color())
{
    this->textPath = textPath;
    this->spacing = 7;
    this->beginOffset = beginOffset;
    this->endOffset = endOffset;
    this->fontSize = calculateFontSize();
    this->label = label;
    this->frame = frame;

    frame->setCoords(x,y);
    frame->setCoords1(x1,y1);
}

TextBox::TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label *label, byte spacing): ScreenObject(x,y,Color())
{
    this->textPath = textPath;
    this->spacing = spacing;
    this->beginOffset = 0;
    this->endOffset = 0;
    this->fontSize = calculateFontSize();
    this->label = label;
    this->frame = frame;

    frame->setCoords(x,y);
    frame->setCoords1(x1,y1);
}

TextBox::TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label *label): ScreenObject(x,y,Color())
{
    this->textPath = textPath;
    this->spacing = 7;
    this->beginOffset = 0;
    this->endOffset = 0;
    this->fontSize = calculateFontSize();
    this->label = label;
    this->frame = frame;

    frame->setCoords(x,y);
    frame->setCoords1(x1,y1);
}

byte TextBox::calculateFontSize()
{
    /*File file = SD.open(textPath, FILE_READ);
    if(file)
    {
        file.seek(beginOffset);
        if(endOffset==0) true; //TODO if endOffset is not set, use EOF position as offset
        uint32_t length = endOffset - beginOffset;
        uint32_t xpx = getx1()-getx();
        uint32_t ypx = gety1()-gety();

        uint16_t newLines; //todo sacar numero de intros
        //todo comprobar length>0, xpx>0, ypx>0, spacing>0

        canBePrinted = true;
        byte maxFontSize = (-5*length*spacing)+(5*newLines*spacing)-(7*newLines*xpx)+sqrt((49*pow(newLines,2)*pow(xpx,2))-(70*pow(newLines,2)*length*spacing*xpx)+(70*pow(newLines,2)*spacing*xpx)+(140*length*xpx*ypx)-(140*newLines*xpx*ypx)+(25*pow(length,2)*pow(spacing,2))-(50*newLines*length*pow(spacing,2))+(25*pow(newLines,2)*pow(spacing,2)))/(2*(35*length-35*newLines));

        for (byte font = maxFontSize-1; font>0; font--)
        {
            // todo prueba y error para colocar las palabras
        }
    }/**/
    return 1;
}

uint16_t TextBox::maxAmountOfLines(uint16_t ypx, byte font)
{
    return ypx/((7*font)+spacing);
}

bool TextBox::getCanBePrinted()
{
    return canBePrinted;
}

byte TextBox::getSpacing()
{
    return spacing;
}

byte TextBox::getFontSize()
{
    return fontSize;
}

uint32_t TextBox::getBeginOffset()
{
    return beginOffset;
}

uint32_t TextBox::getEndOffset()
{
    return endOffset;
}

Label *TextBox::getLabel()
{
    return label;
}

Rectangle *TextBox::getFrame()
{
    return frame;
}

void TextBox::print(HardwareSerial* serial)
{
    serial->println(F("Printing stored text"));
    File file = SD.open(textPath,FILE_READ);
    file.
    while (file.available())
    {
        serial->print(file.read());
    }
    serial->println(F("Done"));
}