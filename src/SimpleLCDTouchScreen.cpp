/*
 Name:		SimpleLCDTouchScreen.cpp
 Created:	19/08/2021 4:26:17
 Author:	Víctor
 Editor:	http://www.visualmicro.com
*/

#include "SimpleLCDTouchScreen.h"

void Color::to888(uint16_t color, uint8_t* r, uint8_t* g, uint8_t* b)
{
	uint8_t r = (color & 0xF800) >> 8;       // rrrrr... ........ -> rrrrr000
	uint8_t g = (color & 0x07E0) >> 3;       // .....ggg ggg..... -> gggggg00
	uint8_t b = (color & 0x1F) << 3;         // ............bbbbb -> bbbbb000

	*r = (r << 3) | (r >> 2);
	*g = (g << 2) | (g >> 4);
	*b = (b << 3) | (b >> 2);
}

/*Button::Button(uint16_t x, uint16_t y, uint16_t tam_x, uint16_t tam_y)
{
	_x = x;
	_y = y;
	_tam_x = x;
	_tam_y = y;
}*/

Button::Button()
{

}
void Button::begin()
{

}
