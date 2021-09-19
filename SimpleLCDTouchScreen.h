#ifndef _SIMPLE_LCDTOUCH_SCREEN_H_
#define _SIMPLE_LCDTOUCH_SCREEN_H_

#include <LCDWIKI_KBV.h>
#include <LCDWIKI_GUI.h>
#include <TouchScreen.h>
#include "ScreenObject.h"
#include "Line.h"
#include "Label.h"
#include "Rectangle.h"

class SimpleLCDTouchScreen: public LCDWIKI_KBV
{
public:
    SimpleLCDTouchScreen(uint16_t model1, uint8_t cs1, uint8_t cd1, uint8_t wr1, uint8_t rd1, uint8_t reset1): LCDWIKI_KBV(model1, cs1, cd1, wr1, rd1, reset1)
    {

    }
    SimpleLCDTouchScreen(int16_t wid, int16_t heg, uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd, uint8_t reset): LCDWIKI_KBV(wid, heg, cs, cd, wr, rd, reset)
    {

    }
    void show(Line line);
    void show(Label);


private:
};


//Write here


#endif //_SIMPLE_LCDTOUCH_SCREEN_H_
