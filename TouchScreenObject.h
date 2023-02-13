//
// Created by Víctor on 22/09/2021.
//

#ifndef SIMPLELCDTOUCHSCREEN_TOUCHSCREENOBJECT_H
#define SIMPLELCDTOUCHSCREEN_TOUCHSCREENOBJECT_H
#include <TouchScreen.h>

/**
 * This class represent the Touch module of the touchScreen
 * Once created & calibrated, it returns the coords ot where the input was detected using getpoint()
 */
class TouchScreenObject: public TouchScreen
{
public:
    /**
     * This is the constructor of the touch module object
     */
    TouchScreenObject();

    /**
     * This is the constructor of the touch module object
     * @param xp Touch xp port
     * @param yp Touch yp port
     * @param xm Touch xm port
     * @param ym Touch ym port
     * @param DISPLAY_HEIGHT Screen module display height in pixels
     * @param DISPLAY_WIDTH Screen module display width in pixels
     * @param rotation Screen module current rotation setting (it must be the same as SimpleLCDTouchScreen object's rotation)
     */
    TouchScreenObject(uint8_t xp, uint8_t yp, uint8_t xm, uint8_t ym, int DISPLAY_HEIGHT, int DISPLAY_WIDTH, int rotation);

    /**
     * This is the constructor of the touch module object
     * @param xp Touch xp port
     * @param yp Touch yp port
     * @param xm Touch xm port
     * @param ym Touch ym port
     * @param rx Touch Screen resistance value between X+ (probably xm) and X- (probably xp) Use any multimeter to read it
     * @param DISPLAY_HEIGHT Screen module display height in pixels
     * @param DISPLAY_WIDTH Screen module display width in pixels
     * @param rotation Screen module current rotation setting (it must be the same as SimpleLCDTouchScreen object's rotation)
     */
    TouchScreenObject(uint8_t xp, uint8_t yp, uint8_t xm, uint8_t ym, uint16_t rx, int DISPLAY_HEIGHT, int DISPLAY_WIDTH, int rotation);

    /**
     * This is the constructor of the touch module object
     * @param xp Touch xp port
     * @param yp Touch yp port
     * @param xm Touch xm port
     * @param ym Touch ym port
     * @param DISPLAY_HEIGHT Screen module display height in pixels
     * @param DISPLAY_WIDTH Screen module display width in pixels
     * @param rotation Screen module current rotation setting (it must be the same as SimpleLCDTouchScreen object's rotation)
     * @param CAL_LEFT RAW longitudinal value at the furthest position on the left
     * @param CAL_RIGHT RAW longitudinal value at the furthest position on the right
     * @param CAL_TOP RAW vertical value at the furthest position on the top
     * @param CAL_BOT RAW vertical value at the furthest position on the bottom
     */
    TouchScreenObject(uint8_t xp, uint8_t yp, uint8_t xm, uint8_t ym, int DISPLAY_HEIGHT, int DISPLAY_WIDTH, int rotation, int CAL_LEFT, int CAL_RIGHT, int CAL_TOP, int CAL_BOT);

    /**
     * This is the constructor of the touch module object
     * @param xp Touch xp port
     * @param yp Touch yp port
     * @param xm Touch xm port
     * @param ym Touch ym port
     * @param rx Touch Screen resistance value between X+ (probably xm) and X- (probably xp) Use any multimeter to read it
     * @param DISPLAY_HEIGHT Screen module display height in pixels
     * @param DISPLAY_WIDTH Screen module display width in pixels
     * @param rotation Screen module current rotation setting (it must be the same as SimpleLCDTouchScreen object's rotation)
     * @param CAL_LEFT RAW longitudinal value at the furthest position on the left
     * @param CAL_RIGHT RAW longitudinal value at the furthest position on the right
     * @param CAL_TOP RAW vertical value at the furthest position on the top
     * @param CAL_BOT RAW vertical value at the furthest position on the bottom
     */
    TouchScreenObject(uint8_t xp, uint8_t yp, uint8_t xm, uint8_t ym, uint16_t rx, int DISPLAY_HEIGHT, int DISPLAY_WIDTH, int rotation, int CAL_LEFT, int CAL_RIGHT, int CAL_TOP, int CAL_BOT);

    /**
     * This function returns the coordinates of the point touched
     * @return A point with 3 coordinates (x, y, z) representing where is the touch located and its pressure on the screen
     */
    TSPoint getPoint();

    /**
     * This function is used to set if the is X axis inverted due to hardware compatibilities
     * @param inverted whether X axis is inverted or not
     */
    void invertXAxis(bool inverted);

    /**
     * This function is used to check if the is X axis inverted due to hardware compatibilities.
     * NOTE: it doesn't check the actual hardware, but the current state of the driver, so it cannot be used to detect if the axis is inverted, but to check the internal configuration
     * @return true if X axis is inverted or false otherwise
     */
    bool isXAxisInverted();

    /**
     * This function returns the current rotation of the screen
     * @return an integer representing the current rotation of the screen
     */
    int getRotation();

    /**
     * This function modifies the current rotation
     * @param rotation the new rotation value
     */
    void setRotation(int rotation);

    /**
     *
     * @param CAL_LEFT
     * @param CAL_RIGHT
     * @param CAL_TOP
     * @param CAL_BOT
     */
    void changeCalibrationValues(int CAL_LEFT, int CAL_RIGHT, int CAL_TOP, int CAL_BOT); // TODO maybe also add resistance to calibration?

private:
    int CAL_LEFT;
    int CAL_TOP;
    int CAL_RIGHT;
    int CAL_BOT;
    int DISPLAY_HEIGHT;
    int DISPLAY_WIDTH;
    int rotation;
    bool xAxisInverted;
    uint8_t xm, yp;
};


#endif //SIMPLELCDTOUCHSCREEN_TOUCHSCREENOBJECT_H
