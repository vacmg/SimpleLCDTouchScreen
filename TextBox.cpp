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
    this->validFile = false;
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
    this->validFile = false;
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
    this->validFile = false;
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
    this->validFile = false;
    this->fontSize = calculateFontSize();
    this->label = label;
    this->frame = frame;

    frame->setCoords(x,y);
    frame->setCoords1(x1,y1);
}

char* nextWord(File* file, uint32_t start, uint32_t end, uint32_t* length) // This function separates a string in words like that: "I like\narduino" --> "I"+" "+"like"+"\n"+"arduino"
{
    file->seek(start);
    while (file->available() && file->position()<end) // look for terminators
    {
        char character = (char)file->read();
        if(character == ' ' || character == '\n')
            end = file->position()-1;
    }
    char* word = (char*)malloc((end-start+1)* sizeof(char)); // WARNING: Dynamic allocation, be careful with memory leaks
    if(word == NULL)
        return NULL;

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
    byte font = 0;
    if(validFile || checkIfFileExists())
    {
        File file = SD.open(textPath, FILE_READ);
        file.seek(beginOffset);

        if(endOffset==0) endOffset=file.size();
        uint32_t length = endOffset - beginOffset;
        uint32_t xpx = frame->getx1()-frame->getx();
        uint32_t ypx = frame->gety1()-frame->gety();

        uint16_t newLines; //todo sacar numero de intros
        if(length>0 && xpx>0 && ypx>0 && spacing>0)
        {
            canBePrinted = true;
            byte maxFontSize = (-5*length*spacing)+(5*newLines*spacing)-(7*newLines*xpx)+sqrt((49*pow(newLines,2)*pow(xpx,2))-(70*pow(newLines,2)*length*spacing*xpx)+(70*pow(newLines,2)*spacing*xpx)+(140*length*xpx*ypx)-(140*newLines*xpx*ypx)+(25*pow(length,2)*pow(spacing,2))-(50*newLines*length*pow(spacing,2))+(25*pow(newLines,2)*pow(spacing,2)))/(2*(35*length-35*newLines));

            for (font = maxFontSize-1; font>0; font--)
            {
                uint16_t maxChar = charactersPerRow(xpx, font);
                uint16_t chars = 0;

                // todo prueba y error para colocar las palabras
            }
        }
        file.close();
    }

    return font;
}

uint16_t TextBox::maxAmountOfRows(uint16_t ypx, byte font)
{
    return ypx/((7*font)+spacing);
}

uint16_t TextBox::charactersPerRow(uint16_t xpx, byte font)
{
    return xpx/(5*font);
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

bool TextBox::print(HardwareSerial* serial)
{
    if(validFile || checkIfFileExists())
    {
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
    }
    return validFile;
}

bool TextBox::printAll(HardwareSerial* serial)
{
    uint32_t bOffset = beginOffset;
    uint32_t eOffset = endOffset;
    beginOffset = 0;
    endOffset = UINT32_MAX;
    bool res = print(serial);
    beginOffset = bOffset;
    endOffset = eOffset;
    return res;
}

bool TextBox::checkIfFileExists()
{
    File file = SD.open(textPath,FILE_READ);
    bool res = file && !file.isDirectory(); // If the file exists, and it is not a directory...
    file.seek(endOffset);
    res &=file.available(); // ...and if file is at least as long as endOffset bytes
    file.close();
    validFile = res;
    return res;
}

void TextBox::test() //TODO remove this function
{
    File file = SD.open(textPath,FILE_READ);
    Serial.print(F("Using file: "));
    Serial.println(file.name());
    Serial.println();
    uint32_t length;
    uint32_t pos = 0;

    Serial.println(nextWord(&file,pos,file.size(),&length));

    Serial.println("\n\nNext scan:");
    Serial.print(F("Using file: "));
    Serial.println(file.name());
    //Serial.println();

    Serial.println(file.read()==' '?"Space delimiter":"\\n delimiter");

    pos+=length+1;
    Serial.print(nextWord(&file,pos,file.size(),&length));
}
