/*
 Name:		SimpleLCDTouchScreen.h
 Created:	19/08/2021 4:26:17
 Author:	Víctor
 Editor:	http://www.visualmicro.com
*/

#ifndef _SimpleLCDTouchScreen_h
#define _SimpleLCDTouchScreen_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <TouchScreen.h>
#include <LCDWIKI_KBV.h>
#include <LCDWIKI_GUI.h>

class Color
{
public:
	static uint16_t to565(byte r, byte g, byte b);
	static void to888(uint16_t color, byte* r, byte* g, byte* b);
};

class Button
{
public:
	Button();
	
	//Button(uint16_t x, uint16_t y, uint16_t tam_x, uint16_t tam_y, uint16_t borderSize, Color borderColor = Color(0,0,0), Color fillColor = Color(0,0,0));

	static void begin();

	bool isPressed();

	void show();

	//void setShowfunction()

	void move(uint16_t x, uint16_t y);

	void setLabel(char* label, int size);

	void setForegroundColor(Color color);

	void setBackgroundColor(Color color);

private:
	uint16_t _x;
	uint16_t _y;
	uint16_t _tam_x;
	uint16_t _tam_y;
	// function pointer customshow
};

#endif

