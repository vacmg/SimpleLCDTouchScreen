//
// Created by Víctor on 13/09/2021.
//

#ifndef SIMPLELCDTOUCHSCREEN_COLOR_H
#define SIMPLELCDTOUCHSCREEN_COLOR_H

#include <Arduino.h>

class Color
{
public:
    //const static Color TODO create color constants
/*#define BLACK        0x0000  //   0,   0,   0
#define BLUE         0x001F  //   0,   0, 255
#define RED          0xF800  // 255,   0,   0
#define GREEN        0x07E0  //   0, 255,   0
#define CYAN         0x07FF  //   0, 255, 255
#define MAGENTA      0xF81F  // 255,   0, 255
#define YELLOW       0xFFE0  // 255, 255,   0
#define WHITE        0xFFFF  // 255, 255, 255
#define NAVY         0x000F  //   0,   0, 128
#define DARKGREEN    0x03E0  //   0, 128,   0
#define DARKCYAN     0x03EF  //   0, 128, 128
#define MAROON       0x7800  // 128,   0,   0
#define PURPLE       0x780F  // 128,   0, 128
#define OLIVE        0x7BE0  // 128, 128,   0
#define LIGHTGREY    0xC618  // 192, 192, 192
#define DARKGREY     0x7BEF  // 128, 128, 128
#define ORANGE       0xFD20  // 255, 165,   0
#define GREENYELLOW  0xAFE5  // 173, 255,  47
#define PINK         0xF81F  // 255,   0, 255 */
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    Color()
    {
        r = 0;
        g = 0;
        b = 0;
    }
    Color(uint8_t r, uint8_t g, uint8_t b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    uint16_t to565() const
    {
        return ((r & 0xf8)<<8) + ((g & 0xfc)<<3)+(b>>3);
    }
};


#endif //SIMPLELCDTOUCHSCREEN_COLOR_H
