# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/Gonza/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Gonza/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Gonza/Desktop/l02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Gonza/Desktop/l02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ej1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej1.dir/flags.make

CMakeFiles/ej1.dir/tests/test_geometria.cpp.o: CMakeFiles/ej1.dir/flags.make
CMakeFiles/ej1.dir/tests/test_geometria.cpp.o: ../tests/test_geometria.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Gonza/Desktop/l02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej1.dir/tests/test_geometria.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej1.dir/tests/test_geometria.cpp.o -c /cygdrive/c/Users/Gonza/Desktop/l02/tests/test_geometria.cpp

CMakeFiles/ej1.dir/tests/test_geometria.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej1.dir/tests/test_geometria.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Gonza/Desktop/l02/tests/test_geometria.cpp > CMakeFiles/ej1.dir/tests/test_geometria.cpp.i

CMakeFiles/ej1.dir/tests/test_geometria.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej1.dir/tests/test_geometria.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Gonza/Desktop/l02/tests/test_geometria.cpp -o CMakeFiles/ej1.dir/tests/test_geometria.cpp.s

# Object files for target ej1
ej1_OBJECTS = \
"CMakeFiles/ej1.dir/tests/test_geometria.cpp.o"

# External object files for target ej1
ej1_EXTERNAL_OBJECTS =

ej1.exe: CMakeFiles/ej1.dir/tests/test_geometria.cpp.o
ej1.exe: CMakeFiles/ej1.dir/build.make
ej1.exe: libgtest.a
ej1.exe: libgtest_main.a
ej1.exe: CMakeFiles/ej1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Gonza/Desktop/l02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej1.dir/build: ej1.exe

.PHONY : CMakeFiles/ej1.dir/build

CMakeFiles/ej1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej1.dir/clean

CMakeFiles/ej1.dir/depend:
	cd /cygdrive/c/Users/Gonza/Desktop/l02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Gonza/Desktop/l02 /cygdrive/c/Users/Gonza/Desktop/l02 /cygdrive/c/Users/Gonza/Desktop/l02/cmake-build-debug /cygdrive/c/Users/Gonza/Desktop/l02/cmake-build-debug /cygdrive/c/Users/Gonza/Desktop/l02/cmake-build-debug/CMakeFiles/ej1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej1.dir/depend

