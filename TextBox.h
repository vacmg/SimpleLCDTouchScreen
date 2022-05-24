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

class TextBox: virtual public ScreenObjectWithXtraCoords
{
public:
    TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label* label);
    TextBox(int x, int y, int x1, int y1, char* textPath, byte spacing, Rectangle* frame, Label* label);
    TextBox(int x, int y, int x1, int y1, char* textPath, byte spacing, uint16_t marginX, uint16_t marginY, Rectangle* frame, Label *label);
    TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label* label, uint32_t beginOffset, uint32_t endOffset);
    TextBox(int x, int y, int x1, int y1, char* textPath, byte spacing, Rectangle* frame, Label* label, uint32_t beginOffset, uint32_t endOffset);
    TextBox(int x, int y, int x1, int y1, char* textPath, byte spacing, uint16_t marginX, uint16_t marginY, Rectangle* frame, Label *label, uint32_t beginOffset, uint32_t endOffset);

    char* nextWord(File* file, uint32_t start, uint32_t end, uint32_t* length);
    bool printAll(HardwareSerial* serial);
    bool print(HardwareSerial* serial);
    bool init();
    uint16_t maxAmountOfRows(uint16_t ypx,byte font);
    uint16_t charactersPerRow(uint16_t xpx, byte font);
    char* getTextPath();
    uint16_t getSpacing();
    uint16_t getMarginX();
    uint16_t getMarginY();
    void setSpacing(uint16_t spacing);
    void setMarginX(uint16_t marginX);
    void setMarginY(uint16_t marginY);
    uint8_t getFontSize();
    bool canBeDrawn();
    uint32_t getBeginOffset();
    uint32_t getEndOffset();
    Label* getLabel();
    Rectangle* getFrame();
private:
    bool checkIfFileExists();
    uint8_t calculateFontSize();
    char* textPath;
    uint32_t beginOffset;
    uint32_t endOffset;
    uint16_t spacing;
    uint16_t marginX;
    uint16_t marginY;

    uint8_t fontSize; // 0 if invalid
    bool validFile;
    Label* label;
    Rectangle* frame;
};


#endif //SIMPLELCDTOUCHSCREEN_TEXTBOX_H
