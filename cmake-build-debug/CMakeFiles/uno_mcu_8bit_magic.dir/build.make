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

# Include any dependencies generated for this target.
include CMakeFiles/uno_mcu_8bit_magic.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/uno_mcu_8bit_magic.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/uno_mcu_8bit_magic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uno_mcu_8bit_magic.dir/flags.make

CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.obj: CMakeFiles/uno_mcu_8bit_magic.dir/flags.make
CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.obj: ../LCDWIKI_KBV/LCDWIKI_KBV.cpp
CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.obj: CMakeFiles/uno_mcu_8bit_magic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.obj"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.obj -MF CMakeFiles\uno_mcu_8bit_magic.dir\LCDWIKI_KBV\LCDWIKI_KBV.cpp.obj.d -o CMakeFiles\uno_mcu_8bit_magic.dir\LCDWIKI_KBV\LCDWIKI_KBV.cpp.obj -c E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\LCDWIKI_KBV\LCDWIKI_KBV.cpp

CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.i"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\LCDWIKI_KBV\LCDWIKI_KBV.cpp > CMakeFiles\uno_mcu_8bit_magic.dir\LCDWIKI_KBV\LCDWIKI_KBV.cpp.i

CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.s"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\LCDWIKI_KBV\LCDWIKI_KBV.cpp -o CMakeFiles\uno_mcu_8bit_magic.dir\LCDWIKI_KBV\LCDWIKI_KBV.cpp.s

# Object files for target uno_mcu_8bit_magic
uno_mcu_8bit_magic_OBJECTS = \
"CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.obj"

# External object files for target uno_mcu_8bit_magic
uno_mcu_8bit_magic_EXTERNAL_OBJECTS =

libuno_mcu_8bit_magic.a: CMakeFiles/uno_mcu_8bit_magic.dir/LCDWIKI_KBV/LCDWIKI_KBV.cpp.obj
libuno_mcu_8bit_magic.a: CMakeFiles/uno_mcu_8bit_magic.dir/build.make
libuno_mcu_8bit_magic.a: CMakeFiles/uno_mcu_8bit_magic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libuno_mcu_8bit_magic.a"
	$(CMAKE_COMMAND) -P CMakeFiles\uno_mcu_8bit_magic.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\uno_mcu_8bit_magic.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uno_mcu_8bit_magic.dir/build: libuno_mcu_8bit_magic.a
.PHONY : CMakeFiles/uno_mcu_8bit_magic.dir/build

CMakeFiles/uno_mcu_8bit_magic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\uno_mcu_8bit_magic.dir\cmake_clean.cmake
.PHONY : CMakeFiles/uno_mcu_8bit_magic.dir/clean

CMakeFiles/uno_mcu_8bit_magic.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\cmake-build-debug E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\cmake-build-debug E:\Datos\Documentos\Proyectos\SimpleLCDTouchScreen\cmake-build-debug\CMakeFiles\uno_mcu_8bit_magic.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uno_mcu_8bit_magic.dir/depend

