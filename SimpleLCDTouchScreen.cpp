#include "SimpleLCDTouchScreen.h"
#include "ScreenObject.h"

void SimpleLCDTouchScreen::show(Line line)
{
    this->Set_Draw_color(line.getMainColor().to565());
    this->Draw_Line(line.getx(),line.gety(),line.getx1(),line.gety1());
}

void SimpleLCDTouchScreen::show(Label label)
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
