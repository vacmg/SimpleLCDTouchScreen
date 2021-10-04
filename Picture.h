//
// Created by Víctor on 29/09/2021.
//

#ifndef SIMPLELCDTOUCHSCREEN_PICTURE_H
#define SIMPLELCDTOUCHSCREEN_PICTURE_H
#include <Arduino.h>
#include <SD.h>
//#include <SD/src/SD.h>
#include <SPI.h>
#include "ScreenObject.h"
#include "ScreenObjectWithXtraCoords.h"

class Picture: virtual public ScreenObjectWithXtraCoords, virtual public ScreenObject
{
public:
    Picture(int x, int y, char* picturePath);
    Picture(int x, int y, char* picturePath, Color mainColor);
    Picture();
    char* getPicturePath();
    bool init();
    bool bmpHeaderAnalysis();
    uint32_t getBmpOffset();
    uint32_t getBmpWidth();
    uint32_t getBmpHeight();
    uint32_t getIgnoreBytes();
    static bool startSD(uint8_t sd_cs);
private:
    uint32_t read_32(File file);
    uint16_t read_16(File file);
    char* picturePath;
    uint32_t bmpOffset;
    uint32_t bmpWidth;
    uint32_t bmpHeight;
    uint32_t ignoreBytes;

};


#endif //SIMPLELCDTOUCHSCREEN_PICTURE_H
