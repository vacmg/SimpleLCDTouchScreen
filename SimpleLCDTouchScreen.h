#ifndef _SIMPLE_LCDTOUCH_SCREEN_H_
#define _SIMPLE_LCDTOUCH_SCREEN_H_

#include "LCDWIKI_KBV.h"
#include "LCDWIKI_GUI.h"
#include "TouchScreen.h"
#include "TouchScreenObject.h"
#include "ScreenObject.h"
#include "Line.h"
#include "Label.h"
#include "Rectangle.h"
#include "RectangleButton.h"
#include "Picture.h"
#include "ScreenObjectWithPicture.h"
#include "PictureButton.h"

class SimpleLCDTouchScreen: virtual public LCDWIKI_KBV
{
public:
    SimpleLCDTouchScreen(uint16_t model1, uint8_t cs1, uint8_t cd1, uint8_t wr1, uint8_t rd1, uint8_t reset1);
    SimpleLCDTouchScreen(int16_t wid, int16_t heg, uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd, uint8_t reset);
    void Init_LCD();
    void set_sd_cs(uint8_t sd_cs);
    bool draw(Line line);
    bool draw(Label label);
    bool draw(Rectangle rectangle);
    bool draw(Picture picture);

private:
    /*SD ACCESS*/
    void drawBmpPicture(int x, int y, File file, uint32_t offset, uint32_t height, uint32_t width, uint32_t ignoreBytes);
    /*SD ACCESS*/

    uint8_t sd_cs;
    bool isSDReady;
};

#endif //_SIMPLE_LCDTOUCH_SCREEN_H_
