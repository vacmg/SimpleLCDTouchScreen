# Arduino SimpleLCDTouchScreen library

This library needs LCDWikiGUI, LCDWikiKBV & TouchScreen libraries to work. It is designed to implement a simple GUI using labels, buttons and more.
# How it works
All the different drawable objects like Rectangle, or Line, inherits from a super class that has all the functions and attributes it will need: i.e: Line inherits from ScreenObjectWithXtraCoords, because it needs 2 set of coords to draw a line, and all the functionality is inherited from that class.
# Auxiliary Classes
- Color: It provides a way to easily define a color via an RGB888 or RGB565 standard, and translate from one to another.
# Functional Classes
- SimpleLCDTouchScreen: The object that represents the screen, it is in charge of drawing all screenObjects.
- TouchScreenObject: The basic object that represents the touchscreen module. ScreenObjectWithTouch use it for knowing when it is touched.
- ScreenObject: The basic object that can be displayed in the screen. it has coordinates and a mainColor.
- ScreenObjectWithSecondaryColor: Class inherited from ScreenObject, it provides an extra Color property, for objects with more than one color.
- ScreenObjectWithXtraCoords: Class inherited from ScreenObject, it provides an extra set of coordinates for those objects which need 2 points for drawing them.
- ScreenObjectWithLabel: Class inherited from ScreenObjectWithXtraCoords, it provides a label to be drawn when drawing an object of this kind. The label will be drawn with center align and with a margin from the object.
- ScreenObjectWithTouch: Class inherited from ScreenObjectWithXtraCoords, it provides a way of knowing if the object is being touched or not.

# End user Classes
The function that draws every ScreenObject is in SimpleLCDTouchScreen class.
All this classes doesn't have any code but the constructor (with the exception of Label class). The functionality of those classes is provided via the functional classes.

- Line: Class inherited from ScreenObjectWithXtraCoords that draws a straight line between 2 points.
- Label: Class inherited from ScreenObjectWithSecondaryColor which allows printing text with a desired font, text color and a background color.
- Rectangle: Class inherited from ScreenObjectWithXtraCoords, ScreenObjectWithSecondaryColor and ScreenObjectWithLabel, which draws a rectangle which can have a label inside.
- RectangleButton: Class inherited from Rectangle and ScreenObjectWithTouch which enables having rectangular button with an optional label inside.
- More coming soon...
