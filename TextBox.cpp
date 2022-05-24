//
// Created by Víctor on 10/04/2022.
//

#include "TextBox.h"

TextBox::TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label *label, byte spacing, uint32_t beginOffset, uint32_t endOffset): ScreenObject(x,y,Color()), ScreenObjectWithXtraCoords(x,y,x1,y1,Color())
{
    this->textPath = textPath;
    this->spacing = spacing;
    this->beginOffset = beginOffset;
    this->endOffset = endOffset;
    this->fontSize = 0;
    this->validFile = false;
    this->label = label;
    this->frame = frame;
}

TextBox::TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label *label, uint32_t beginOffset, uint32_t endOffset): ScreenObject(x,y,Color()), ScreenObjectWithXtraCoords(x,y,x1,y1,Color())
{
    this->textPath = textPath;
    this->spacing = 7;
    this->beginOffset = beginOffset;
    this->endOffset = endOffset;
    this->fontSize = 0;
    this->validFile = false;
    this->label = label;
    this->frame = frame;
}

TextBox::TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label *label, byte spacing): ScreenObject(x,y,Color()), ScreenObjectWithXtraCoords(x,y,x1,y1,Color())
{
    this->textPath = textPath;
    this->spacing = spacing;
    this->beginOffset = 0;
    this->endOffset = 0;
    this->validFile = false;
    this->fontSize = 0;
    this->label = label;
    this->frame = frame;
}

TextBox::TextBox(int x, int y, int x1, int y1, char* textPath, Rectangle* frame, Label *label): ScreenObject(x,y,Color()), ScreenObjectWithXtraCoords(x,y,x1,y1,Color())
{
    this->textPath = textPath;
    this->spacing = 7;
    this->beginOffset = 0;
    this->endOffset = 0;
    this->validFile = false;
    this->fontSize = 0;
    this->label = label;
    this->frame = frame;
}

/*
 * This function separates a string based on space ' ' or new line '\n' delimiters and returns the first word between start and a delimiter
 * This function separates a string in words like that: "I like\narduino" --> "I"+" "+"like"+"\n"+"arduino"
 * If the end position is reached before the end of a word, it returns nullptr
 */
char* TextBox::nextWord(File* file, uint32_t start, uint32_t end, uint32_t* length)
{
    if(!init())
        return nullptr;
    file->seek(start);
    while (file->available() && file->position()<end) // look for terminators
    {
        char character = (char)file->read();
        if(character == ' ' || character == '\n')
            end = file->position()-1;
        else if(file->position()==end)
            return nullptr;
    }
    if(!file->available())
        return nullptr;

    char* word = (char*)malloc((end-start+1)* sizeof(char)); // WARNING: Dynamic allocation, be careful with memory leaks
    if(word == nullptr)
        return nullptr;

    file->seek(start);
    uint16_t i = 0;
    while (file->available() && file->position()<end) // read word
    {
        word[i] = (char)file->read();
        i++;
    }
    word[i] = '\0';
    *length = i;
    return word;
}

byte TextBox::calculateFontSize()
{
    if(!init())
    {
        fontSize = 0;
        return 0;
    }
    uint8_t font = 0;
    File file = SD.open(textPath, FILE_READ);

    uint32_t length = endOffset - beginOffset;
    uint32_t xpx = frame->getx1()-frame->getx();
    uint32_t ypx = frame->gety1()-frame->gety();

    if(length>0 && xpx>0 && ypx>0 && spacing>0)
    {
        uint8_t maxFontSize = 50; // An arbitrary big enough value to ensure the biggest font available is selected (during our tests we found it's quicker to loop 40 times (loops are almost instantaneous until font = 6)
                               // than to solve the equation that gives the maximum font size in ideal conditions (after getting that value, at least 1 loop is needed to adjust the final result)
        bool fontFound = false;
        for (font = maxFontSize; font>0 && !fontFound; font--) // For each font from maxFontSize to one
        {
            uint16_t maxNumOfCharPerRow = charactersPerRow(xpx, font);
            uint16_t maxNumOfRows = maxAmountOfRows(ypx, font);
            uint16_t row = 0;
            uint16_t pos = beginOffset;
            uint32_t wordSize;
            char* nxWord = nextWord(&file,pos,endOffset,&wordSize);
            while (nxWord!= nullptr && row<maxNumOfRows) // For each line until the paragraph is read or numOfRows is exceeded
            {
                uint16_t charsReadInARow = 0;
                bool maxCharPerLineExceeded = false;
                while (nxWord!= nullptr && !maxCharPerLineExceeded) // For each word until the line is full or a \n is read
                {
                    if(maxNumOfCharPerRow-charsReadInARow<(wordSize+1)) // If there is no enough free space
                    {
                        maxCharPerLineExceeded = true; // end line
                    }
                    else // If there is enough free space
                    {
                        pos+=wordSize+1; // Move forward text pointer
                        charsReadInARow+=(wordSize+1); // Add the word to the line // wordSize + delimiter (1 char)
                        free(nxWord);
                        if(file.read() == '\n') // If the delimiter is a \n, end line
                            maxCharPerLineExceeded = true;
                        nxWord = nextWord(&file,pos,endOffset,&wordSize); // read next word
                    }
                }
                row++;
            }

            if(nxWord == nullptr) // If nextWord is nullptr, it must have reached the end of the paragraph
            {
                fontFound = true;
            }
            else // If it is not nullptr, free the pointer to avoid memory leaks
            {
                free(nxWord);
            }
        }
        font++; // Compensate font-- of for loop
    }
    file.close();
    if(font > 0)
        fontSize = 0;
    return font;
}

uint16_t TextBox::maxAmountOfRows(uint16_t ypx, byte font)
{
    return ypx/((7*font)+spacing);
}

uint16_t TextBox::charactersPerRow(uint16_t xpx, byte font)
{
    return (xpx-2*spacing)/(5*font);
}

byte TextBox::getSpacing()
{
    return spacing;
}

byte TextBox::getFontSize()
{
    return fontSize==0?calculateFontSize():fontSize;
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

char *TextBox::getTextPath()
{
    return textPath;
}

bool TextBox::canBeDrawn()
{
    return getFontSize()>0;
}

bool TextBox::print(HardwareSerial* serial)
{
    if(!init())
        return false;
    File file = SD.open(textPath,FILE_READ);
    serial->print(F("Printing file: "));
    serial->println(file.name());
    serial->println();
    file.seek(beginOffset);

    while (file.available() && file.position()<endOffset)
    {
        serial->print((char)file.read());
    }
    file.close();
    serial->println();
    return validFile;
}

bool TextBox::printAll(HardwareSerial* serial)
{
    if(!init())
        return false;
    uint32_t bOffset = beginOffset;
    uint32_t eOffset = endOffset;
    beginOffset = 0;
    endOffset = UINT32_MAX;
    bool res = print(serial);
    beginOffset = bOffset;
    endOffset = eOffset;
    return res;
}

bool TextBox::init()
{
    if(!validFile)
    {
        checkIfFileExists();
        frame->setCoords(getx(),gety());
        frame->setCoords1(getx1(),gety1());
    }
    return validFile;
}

bool TextBox::checkIfFileExists()
{
    validFile = false;
    File file = SD.open(textPath,FILE_READ);
    if(!file)
    {
        file.close();
        return false;
    }
    if(file.isDirectory()) // If the file exists, and it is not a directory...
    {
        file.close();
        return false;
    }
    file.seek(beginOffset);
    if(!file.available()) // ...and if file is at least as long as startOffset (otherwise cancel)
    {
        file.close();
        return false;
    }
    file.seek(endOffset);
    if(!file.available() || endOffset == 0) // ...and if file is at least as long as endOffset or its set to auto (otherwise set endOffset to last position of the file)
    {
        endOffset = file.size();
    }
    validFile = true;
    return true;
}
