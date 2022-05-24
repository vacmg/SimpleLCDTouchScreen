#include "SimpleLCDTouchScreen.h"
#include "ScreenObject.h"

SimpleLCDTouchScreen::SimpleLCDTouchScreen(int16_t wid, int16_t heg, uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd, uint8_t reset) : LCDWIKI_KBV(wid, heg, cs, cd, wr, rd, reset)
{
    isSDReady = false;
    sd_cs = 10;
}

SimpleLCDTouchScreen::SimpleLCDTouchScreen(uint16_t model, uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd,uint8_t reset) : LCDWIKI_KBV(model, cs, cd, wr, rd, reset)
{
    isSDReady = false;
    sd_cs = 10;
}

bool SimpleLCDTouchScreen::draw(Line* line)
{
    Set_Draw_color(line->getMainColor().to565());
    Draw_Line(line->getx(),line->gety(),line->getx1(),line->gety1());
    return true;
}

bool SimpleLCDTouchScreen::draw(Label* label)
{
    Set_Text_colour(label->getMainColor().to565());
    if (label->isAValidSecondaryColor())
    {
        Set_Text_Back_colour(label->getSecondaryColor().to565());
        Set_Text_Mode(false);
    }
    else
        Set_Text_Mode(true);
    Set_Text_Size(label->getFontSize());
    Print_String(label->getString(),label->getx(),label->gety());
    return true;
}

bool SimpleLCDTouchScreen::draw(Rectangle* rectangle)
{
    if(rectangle->isAValidSecondaryColor())
    {
        Set_Draw_color(rectangle->getSecondaryColor().to565());
        Fill_Rectangle(rectangle->getx(),rectangle->gety(),rectangle->getx1(),rectangle->gety1());
    }
    Set_Draw_color(rectangle->getMainColor().to565());
    Draw_Rectangle(rectangle->getx(),rectangle->gety(),rectangle->getx1(),rectangle->gety1());
    if(rectangle->isAValidLabel())
    {
        rectangle->updateLabelLocation(rectangle->getMargin());
        draw(rectangle->getLabel());
    }
    return true;
}

bool SimpleLCDTouchScreen::draw(RoundRectangle* roundRectangle)
{
    if(roundRectangle->isAValidSecondaryColor())
    {
        Set_Draw_color(roundRectangle->getSecondaryColor().to565());
        Fill_Round_Rectangle(roundRectangle->getx(), roundRectangle->gety(), roundRectangle->getx1(), roundRectangle->gety1(), roundRectangle->getRadius());
    }
    Set_Draw_color(roundRectangle->getMainColor().to565());
    Draw_Round_Rectangle(roundRectangle->getx(),roundRectangle->gety(),roundRectangle->getx1(),roundRectangle->gety1(),roundRectangle->getRadius());
    if(roundRectangle->isAValidLabel())
    {
        roundRectangle->updateLabelLocation(roundRectangle->getMargin());
        draw(roundRectangle->getLabel());
    }
    return true;
}

bool SimpleLCDTouchScreen::draw(Picture* picture)
{
    if(isSDReady)
    {
        File file = SD.open(picture->getPicturePath(),FILE_READ);
        if(picture->init())
        {
            return drawBmpPictureBuff(picture->getx(), picture->gety(), file, picture->getBmpOffset(), picture->getBmpHeight(), picture->getBmpWidth(), picture->getIgnoreBytes());
        }
        else
        {
            Label label(picture->getx(),picture->gety(),"Failure decoding .bmp",2,Color(255,255,255),Color(255,0,0));
            draw(&label);
            return false;
        }
    }
    else
    {
        Label label(picture->getx(),picture->gety(),"Failure starting the SD card",2,Color(255,255,255),Color(255,0,0));
        draw(&label);
        return false;
    }
}

void pause() // TODO remove this
{
    while (Serial.available())
    {
        Serial.read();
    }
    while (!Serial.available());
    while (Serial.available())
    {
        Serial.read();
    }
}

bool SimpleLCDTouchScreen::draw(TextBox* textBox)
{
    if(!textBox->init() || textBox->getFontSize()==0)
        return false;
    draw(textBox->getFrame());
    uint32_t xpx = textBox->getx1()-textBox->getx();
    uint32_t ypx = textBox->gety1()-textBox->gety();

    uint8_t font = textBox->getFontSize();
    textBox->getLabel()->setFontSize(font);
    Serial.print("Font size: ");Serial.println(font);
    uint16_t maxNumOfCharPerRow = textBox->charactersPerRow(xpx,font);
    Serial.print("MaxNumOfCharsPerRow: ");Serial.println(maxNumOfCharPerRow);
    uint16_t maxNumOfRows = textBox->maxAmountOfRows(ypx, font);
    uint16_t row = 0;
    uint16_t pos = textBox->getBeginOffset();
    uint32_t wordSize;
    File file = SD.open(textBox->getTextPath(), FILE_READ);

    char* nxWord = textBox->nextWord(&file,pos,textBox->getEndOffset(),&wordSize);
    while (nxWord!= nullptr && row<maxNumOfRows) // For each line until the paragraph is read or numOfRows is exceeded
    {
        uint16_t charsReadInARow = 0;
        bool maxCharPerLineExceeded = false;
        char* line = (char*) calloc(maxNumOfCharPerRow, sizeof(char));
        while (nxWord!= nullptr && !maxCharPerLineExceeded) // For each word until the line is full or a \n is read
        {
            Serial.print("charsAvailable: ");Serial.println(maxNumOfCharPerRow-charsReadInARow);
            Serial.print("charsToAppend: ");Serial.println((wordSize+1));

            if(maxNumOfCharPerRow-charsReadInARow<(wordSize+1)) // If there is no enough free space // todo there is a bug with free space recognicion
            {
                Serial.println("NO");
                maxCharPerLineExceeded = true; // end line
            }
            else // If there is enough free space
            {
                Serial.println("OK");
                strcat(line,nxWord); // Add the word to the line
                charsReadInARow+=(wordSize+1); // wordSize + delimiter (1 char)
                free(nxWord); // Free old pointer once it has been appended to the line

                char terminator[2] = "";
                terminator[0] = (char)file.read(); // get the delimiter as a string
                terminator[1] = NULL;
                if(terminator[0] == '\n') // If the delimiter is a \n, end line
                    maxCharPerLineExceeded = true;
                else
                    strcat(line,terminator); // If the delimiter is a space, add it to the line
                pos+=wordSize+1; // Move forward text pointer
                pause();
                nxWord = textBox->nextWord(&file,pos,textBox->getEndOffset(),&wordSize); // read next word
            }
        }
        Label* label = textBox->getLabel();
        label->setString(line); // set the string to draw
        label->setCoords(textBox->getx()+textBox->getSpacing(),(int)(textBox->gety()+textBox->getSpacing()+((7*font)+textBox->getSpacing())*row)); // set the coords where to draw the string
        draw(label);
        free(line); // free line string after using it
        row++;
        Serial.println("\n");
    }
    file.close();
    if(nxWord!= nullptr)
    {
        return false;
    }
    Serial.print("Successfully drawn the text with a font of ");Serial.println(font);
    return true;

}

void SimpleLCDTouchScreen::Init_LCD()
{
    LCDWIKI_KBV::Init_LCD();
    pinMode(sd_cs,OUTPUT);
    isSDReady = SD.begin(sd_cs);
}

void SimpleLCDTouchScreen::set_sd_cs(uint8_t sd_cs)
{
    this->sd_cs = sd_cs;
}

bool SimpleLCDTouchScreen::drawBmpPicture(int x, int y, File file, uint32_t offset, uint32_t height, uint32_t width, uint32_t ignoreBytes)
{
    file.seek(offset);
    for(long row = (long)height-1; row>=0;row--)
    {
        for(long col = 0; col<width;col++)
        {
            uint8_t colors[3];
            for(unsigned char & color : colors)
            {
                color = file.read();
            }
            Set_Draw_color(LCDWIKI_KBV::Color_To_565(colors[2],colors[1],colors[0]));
            Draw_Pixel((int)(x+col),(int)(y+row));
        }
        file.seek(file.position()+ignoreBytes);
    }
    file.close();
    return true;
}

bool SimpleLCDTouchScreen::drawBmpPictureBuff(int x, int y, File file, uint32_t offset, uint32_t height, uint32_t width, uint32_t ignoreBytes)
{
    file.seek(offset);
    uint8_t* rowBuff = (uint8_t*) malloc(width*3*sizeof(uint8_t));
    if (rowBuff == nullptr)
    {
        return drawBmpPicture(x,y,file,offset,height,width,ignoreBytes); // use fallback method (no buffer/slower)
    }
    for(long row = (long)height-1; row>=0;row--)
    {
        file.read(rowBuff,width*3);
        for(long col = 0; col<width;col++)
        {
            uint32_t pos = (col*3);
            Set_Draw_color(LCDWIKI_KBV::Color_To_565(rowBuff[pos+2],rowBuff[pos+1],rowBuff[pos]));
            Draw_Pixel((int)(x+col),(int)(y+row));
        }
        file.seek(file.position()+ignoreBytes);
    }
    free(rowBuff);
    file.close();
    return true;
}
