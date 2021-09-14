//
// Created by Víctor on 13/09/2021.
//

#ifndef SIMPLELCDTOUCHSCREEN_COLOR_H
#define SIMPLELCDTOUCHSCREEN_COLOR_H

#include <Arduino.h>

class Color
{
public:
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

    uint16_t to565()
    {
        return 0; //TODO do this function
    }
};


#endif //SIMPLELCDTOUCHSCREEN_COLOR_H
