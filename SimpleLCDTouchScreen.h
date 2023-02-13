#ifndef SIMPLE_LCDTOUCH_SCREEN_H_
#define SIMPLE_LCDTOUCH_SCREEN_H_

#include <SD.h>
#include "LCDWIKI_KBV.h"
#include "LCDWIKI_GUI.h"
#include "TouchScreen.h"
#include "TouchScreenObject.h"
#include "ScreenObject.h"
#include "Line.h"
#include "Label.h"
#include "Rectangle.h"
#include "RectangleButton.h"
#include "RoundRectangle.h"
#include "RoundRectangleButton.h"
#include "Picture.h"
#include "ScreenObjectWithPicture.h"
#include "PictureButton.h"
#include "TextBox.h"

/// The amount of rows used in the buffer that speeds up image drawing in drawBmpPictureBuff
#define BMP_BUFF_ROWS 3

/// The amount of steps the calibration has
#define CALIBRATION_MAX_STEPS 9 // TODO ver cuantos son

/**
 * This class represents the Screen module connected to the MCU.
 * Once created an object of this class, configured the SD cs pin (if cs pin is not set, it defaults to pin 10) and started the module (Init_LCD())
 * it can draw any ScreenObject subclass in the screen.
 */
class SimpleLCDTouchScreen: virtual public LCDWIKI_KBV
{
public:
    /**
     * This is the constructor of the Screen module
     * @param model Driver model of the screen
     * @param cs cs screen pin
     * @param cd cd screen pin
     * @param wr wr screen pin
     * @param rd rd screen pin
     * @param reset reset screen pin
     * @param ts touch module object
     */
    SimpleLCDTouchScreen(uint16_t model, uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd, uint8_t reset, TouchScreenObject* ts);

    /**
     * This is the constructor of the Screen module
     * @param wid ID of the screen driver
     * @param cs cs screen pin
     * @param cd cd screen pin
     * @param wr wr screen pin
     * @param rd rd screen pin
     * @param reset reset screen pin
     * @param ts touch module object
     */
    SimpleLCDTouchScreen(int16_t wid, int16_t heg, uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd, uint8_t reset, TouchScreenObject* ts);

    /**
     * This function start the connection with the screen module
     * It needs to be called before drawing anything in the screen
     */
    void Init_LCD();

    /**
     * This function set the rotation of the touchscreen
     * @param rotation the new rotation of the screen
     */
    void Set_Rotation(uint8_t rotation);

    /**
     * TouchScreen module uses a builtIn SD card reader, this function allows to change in whichd pin is the SD card reader connected
     * @param sd_cs The cs pin where the SD card module is connected
     */
    void set_sd_cs(uint8_t sd_cs);

    /**
     * This function writes a Line object (which has its parameters builtin)
     * @param line The line object which is going to be drawn
     * @return true if it was successfully drawn or false otherwise
     */
    bool draw(Line* line);

    /**
     * This function writes a Label object (which has its parameters builtin)
     * @param label The label object which is going to be drawn
     * @return true if it was successfully drawn or false otherwise
     */
    bool draw(Label* label);

    /**
     * This function writes a Rectangle object (which has its parameters builtin)
     * @param rectangle The label object which is going to be drawn
     * @return true if it was successfully drawn or false otherwise
     */
    bool draw(Rectangle* rectangle);

    /**
     * This function writes a RoundRectangle object (which has its parameters builtin)
     * @param roundRectangle The label object which is going to be drawn
     * @return true if it was successfully drawn or false otherwise
     */
    bool draw(RoundRectangle* roundRectangle);

    /**
     * This function writes a Picture object (which has its parameters builtin)
     * @param picture The label object which is going to be drawn
     * @return true if it was successfully drawn or false otherwise
     */
    bool draw(Picture* picture);

    /**
     * This function writes a Textbox object (which has its parameters builtin)
     * @param textBox The label object which is going to be drawn
     * @return true if it was successfully drawn or false otherwise
     */
    bool draw(TextBox* textBox);

    /**
     * This function writes a Textbox object overriding the automatic font (which has its parameters builtin)
     * @param textBox The label object which is going to be drawn
     * @param fontSize The font size used to draw the textbox
     * @return true if it was successfully drawn or false otherwise
     */
    bool draw(TextBox* textBox, uint8_t fontSize);

    /**
     * This function runs the touchscreen calibration wizard.
     * This function is non blocking, meaning that to successfully calibrate the screen, it must be called until it returns a number <= 0
     * @return The number of steps left until calibration is done, 0 if the calibration successfully ended and -1 if the calibration was cancelled
     */
    int8_t calibrateScreen();


private:
    /**
     * This function draw a bmp picture from the specifies file
     * @param x Top left corner width coordinate
     * @param y Top left corner height coordinate
     * @param file File structure representing the opened file which holds the image
     * @param offset Offset from the beginning of the file to the start of the image
     * @param height Height of the picture in pixels
     * @param width Width of the picture in pixels
     * @param ignoreBytes Extra padding bytes between each row that must be discarded
     * @return True if the image was successfully drawn or false otherwise
     */
    bool drawBmpPicture(int x, int y, File& file, uint32_t offset, uint32_t height, uint32_t width, uint32_t ignoreBytes);

    /**
     * This function draw a bmp picture from the specifies file using a buffer of
     * @param x Top left corner width coordinate
     * @param y Top left corner height coordinate
     * @param file File structure representing the opened file which holds the image
     * @param offset Offset from the beginning of the file to the start of the image
     * @param height Height of the picture in pixels
     * @param width Width of the picture in pixels
     * @param ignoreBytes Extra padding bytes between each row that must be discarded
     * @return True if the image was successfully drawn or false otherwise
     */
    bool drawBmpPictureBuff(int x, int y, File& file, uint32_t offset, uint32_t height, uint32_t width, uint32_t ignoreBytes);

    int8_t calibrationStep;

    /// BuiltIn SD module cs pin
    uint8_t sd_cs;

    /// SD Ready switch used to check if a SD is present in the reader
    bool isSDReady;

    /// Touch object
    TouchScreenObject* ts;
};

#endif //SIMPLE_LCDTOUCH_SCREEN_H_
