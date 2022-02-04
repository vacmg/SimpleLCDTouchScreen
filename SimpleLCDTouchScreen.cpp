#include "SimpleLCDTouchScreen.h"
#include "ScreenObject.h"

SimpleLCDTouchScreen::SimpleLCDTouchScreen(int16_t wid, int16_t heg, uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd, uint8_t reset) : LCDWIKI_KBV(wid, heg, cs, cd, wr, rd, reset)
{
    isSDReady = false;
    sd_cs = 10;
}

SimpleLCDTouchScreen::SimpleLCDTouchScreen(uint16_t model1, uint8_t cs1, uint8_t cd1, uint8_t wr1, uint8_t rd1,uint8_t reset1) : LCDWIKI_KBV(model1, cs1, cd1, wr1, rd1, reset1)
{
    isSDReady = false;
    sd_cs = 10;
}

bool SimpleLCDTouchScreen::draw(Line* line)
{
    this->Set_Draw_color(line->getMainColor().to565());
    this->Draw_Line(line->getx(),line->gety(),line->getx1(),line->gety1());
    return true;
}

bool SimpleLCDTouchScreen::draw(Label* label)
{
    this->Set_Text_colour(label->getMainColor().to565());
    if (label->isAValidSecondaryColor())
    {
        this->Set_Text_Back_colour(label->getSecondaryColor().to565());
        this->Set_Text_Mode(false);
    }
    else
        this->Set_Text_Mode(true);
    this->Set_Text_Size(label->getFontSize());
    this->Print_String(label->getString(),label->getx(),label->gety());
    return true;
}

bool SimpleLCDTouchScreen::draw(Rectangle* rectangle)
{
    if(rectangle->isAValidSecondaryColor())
    {
        this->Set_Draw_color(rectangle->getSecondaryColor().to565());
        this->Fill_Rectangle(rectangle->getx(), rectangle->gety(), rectangle->getx1(), rectangle->gety1());
    }
    this->Set_Draw_color(rectangle->getMainColor().to565());
    this->Draw_Rectangle(rectangle->getx(),rectangle->gety(),rectangle->getx1(),rectangle->gety1());
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
        this->Set_Draw_color(roundRectangle->getSecondaryColor().to565());
        this->Fill_Round_Rectangle(roundRectangle->getx(), roundRectangle->gety(), roundRectangle->getx1(), roundRectangle->gety1(), roundRectangle->getRadius());
    }
    this->Set_Draw_color(roundRectangle->getMainColor().to565());
    this->Draw_Round_Rectangle(roundRectangle->getx(),roundRectangle->gety(),roundRectangle->getx1(),roundRectangle->gety1(),roundRectangle->getRadius());
    if(roundRectangle->isAValidLabel())
    {
        roundRectangle->updateLabelLocation(roundRectangle->getMargin());
        draw(roundRectangle->getLabel());
    }
    return true;
}

bool SimpleLCDTouchScreen::draw(Picture* picture)
{
    File file = SD.open(picture->getPicturePath(),FILE_READ);
    if(isSDReady)
    {
        if(picture->init())
        {
            drawBmpPicture(picture->getx(), picture->gety(), file, picture->getBmpOffset(), picture->getBmpHeight(), picture->getBmpWidth(), picture->getIgnoreBytes());
            return true;
        }
        else
        {
            draw(&Label(picture->getx(),picture->gety(),"Failure decoding .bmp",2,Color(255,255,255),Color(255,0,0)));
            return false;
        }
    }
    else
    {
        draw(&Label(picture->getx(),picture->gety(),"Failure starting the SD card",2,Color(255,255,255),Color(255,0,0)));
        return false;
    }
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

void SimpleLCDTouchScreen::drawBmpPicture(int x, int y, File file, uint32_t offset, uint32_t height, uint32_t width, uint32_t ignoreBytes)
{
    file.seek(offset);
    for(uint32_t row = height-1; row>=0;row--)
    {
        for(uint32_t col = 0; col<width;col++)
        {
            uint8_t colors[3];
            for(int i = 0; i<3;i++)
            {
                colors[i] = file.read();
            }
            Set_Draw_color(LCDWIKI_KBV::Color_To_565(colors[2],colors[1],colors[0]));
            Draw_Pixel((int)(x+col),(int)(y+row));
        }
        file.seek(file.position()+ignoreBytes);
    }
    file.close();
}
