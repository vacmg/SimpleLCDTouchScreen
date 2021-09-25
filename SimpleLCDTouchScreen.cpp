#include "SimpleLCDTouchScreen.h"
#include "ScreenObject.h"

SimpleLCDTouchScreen::SimpleLCDTouchScreen(int16_t wid, int16_t heg, uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd, uint8_t reset) : LCDWIKI_KBV(wid, heg, cs, cd, wr, rd, reset)
{

}

SimpleLCDTouchScreen::SimpleLCDTouchScreen(uint16_t model1, uint8_t cs1, uint8_t cd1, uint8_t wr1, uint8_t rd1,uint8_t reset1) : LCDWIKI_KBV(model1, cs1, cd1, wr1, rd1, reset1)
{

}

void SimpleLCDTouchScreen::draw(Line line)
{
    this->Set_Draw_color(line.getMainColor().to565());
    this->Draw_Line(line.getx(),line.gety(),line.getx1(),line.gety1());
}

void SimpleLCDTouchScreen::draw(Label label)
{

    this->Set_Text_colour(label.getMainColor().to565());
    if (label.isAValidSecondaryColor())
    {
        this->Set_Text_Back_colour(label.getSecondaryColor().to565());
        this->Set_Text_Mode(false);
    }
    else
        this->Set_Text_Mode(true);
    this->Set_Text_Size(label.getFontSize());
    this->Print_String(label.getString(),label.getx(),label.gety());

}

void SimpleLCDTouchScreen::draw(Rectangle rectangle)
{
    Serial.println();
    if(rectangle.isAValidSecondaryColor())
    {
        this->Set_Draw_color(rectangle.getSecondaryColor().to565());
        this->Fill_Rectangle(rectangle.getx(), rectangle.gety(), rectangle.getx1(), rectangle.gety1());
    }
    this->Set_Draw_color(rectangle.getMainColor().to565());
    this->Draw_Rectangle(rectangle.getx(),rectangle.gety(),rectangle.getx1(),rectangle.gety1());
    if(rectangle.isAValidLabel())
    {
        rectangle.updateLabelLocation(rectangle.getMargin());
        draw(rectangle.getLabel());
    }
}

