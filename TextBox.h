//
// Created by Víctor on 10/04/2022.
//

#ifndef SIMPLELCDTOUCHSCREEN_TEXTBOX_H
#define SIMPLELCDTOUCHSCREEN_TEXTBOX_H
#include "ScreenObjectWithXtraCoords.h"
#include "ScreenObjectWithSecondaryColor.h"
#include "Rectangle.h"
#include "RoundRectangle.h"

#include <SD.h>

class TextBox: virtual public ScreenObject
{
public:
    TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label* label);
    TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label* label, byte spacing);
    TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label* label, uint32_t beginOffset, uint32_t endOffset);
    TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label* label, byte spacing, uint32_t beginOffset, uint32_t endOffset);

    void printAll(HardwareSerial* serial);
    void print(HardwareSerial* serial);
    byte calculateFontSize();
    bool getCanBePrinted();
    byte getSpacing();
    byte getFontSize();
    uint32_t getBeginOffset();
    uint32_t getEndOffset();
    Label* getLabel();
    Rectangle* getFrame();
private:
    bool checkIfFileExists();
    char* textPath;
    uint32_t beginOffset;
    uint32_t endOffset;
    byte spacing;
    byte fontSize;
    bool canBePrinted;
    bool validFile;
    Label* label;
    Rectangle* frame;

    uint16_t maxAmountOfLines(uint16_t ypx,byte font);
};


#endif //SIMPLELCDTOUCHSCREEN_TEXTBOX_H
