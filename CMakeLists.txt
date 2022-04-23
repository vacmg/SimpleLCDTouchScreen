cmake_minimum_required(VERSION 2.8.4)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME SimpleLCDTouchScreen)

set(${PROJECT_NAME}_BOARD mega)
set(ARDUINO_CPU atmega2560)
project(${PROJECT_NAME})

# Define additional source and header files or default arduino sketch files
set(${PROJECT_NAME}_SRCS SimpleLCDTouchScreen.cpp SimpleLCDTouchScreen_test.cpp)
set(${PROJECT_NAME}_HDRS SimpleLCDTouchScreen.h)

### Additional static libraries to include in the target.
# set(${PROJECT_NAME}_LIBS)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

### Main sketch file
# set(${PROJECT_NAME}_SKETCH SimpleLCDTouchScreen.ino)

### Add project directories into the build
# add_subdirectory(./libs)

# add_library(LCDWIKI_KVB ./libs/LCDWIKI_KBV/LCDWIKI_KBV.cpp)
# add_library(LCDWIKI_GUI ./libs/LCDWIKI_GUI/LCDWIKI_GUI.cpp)
# add_library(TouchScreen ./libs/TouchScreen/TouchScreen.cpp)
# include_directories(libs/LCDWIKI_KBV)
# include_directories(libs/LCDWIKI_GUI)
# include_directories(libs/TouchScreen)
include_directories(./)

### Additional settings to add non-standard or your own Arduino libraries.
# For this example (libs will contain additional arduino libraries)
# An Arduino library my_lib will contain files in libs/my_lib/: my_lib.h, my_lib.cpp + any other cpp files

# For nested library sources replace ${LIB_NAME} with library name for each library
set(_RECURSE true)

#### Additional settings for programmer. From programmers.txt
set(${PROJECT_NAME}_PROGRAMMER avrisp)
set(${PROJECT_NAME}_PORT COM3)
# set(mega.upload.speed 9600)

## Verbose build process
set(${PROJECT_NAME}_AFLAGS -v)
set(CMAKE_CXX_FLAGS "-fpermissive -std=c++11")

generate_arduino_firmware(${PROJECT_NAME})


print_board_list()
print_programmer_list()
