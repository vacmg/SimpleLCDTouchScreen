# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\cmake-build-debug

# Utility rule file for SimpleLCDTouchScreen-upload.

# Include any custom commands dependencies for this target.
include CMakeFiles/SimpleLCDTouchScreen-upload.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleLCDTouchScreen-upload.dir/progress.make

CMakeFiles/SimpleLCDTouchScreen-upload: SimpleLCDTouchScreen.elf
	"C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avrdude.exe" "-CC:/Program Files (x86)/Arduino/hardware/tools/avr/etc/avrdude.conf" -patmega328p -carduino -b115200 -PCOM3 -D -v -Uflash:w:E:/Datos/Documentos/Proyectos/SimpleLCDTouchScreen/cmake-build-debug/SimpleLCDTouchScreen.hex:i -Ueeprom:w:E:/Datos/Documentos/Proyectos/SimpleLCDTouchScreen/cmake-build-debug/SimpleLCDTouchScreen.eep:i

SimpleLCDTouchScreen-upload: CMakeFiles/SimpleLCDTouchScreen-upload
SimpleLCDTouchScreen-upload: CMakeFiles/SimpleLCDTouchScreen-upload.dir/build.make
.PHONY : SimpleLCDTouchScreen-upload

# Rule to build all files generated by this target.
CMakeFiles/SimpleLCDTouchScreen-upload.dir/build: SimpleLCDTouchScreen-upload
.PHONY : CMakeFiles/SimpleLCDTouchScreen-upload.dir/build

CMakeFiles/SimpleLCDTouchScreen-upload.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SimpleLCDTouchScreen-upload.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SimpleLCDTouchScreen-upload.dir/clean

CMakeFiles/SimpleLCDTouchScreen-upload.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\cmake-build-debug E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\cmake-build-debug E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\cmake-build-debug\CMakeFiles\SimpleLCDTouchScreen-upload.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimpleLCDTouchScreen-upload.dir/depend

