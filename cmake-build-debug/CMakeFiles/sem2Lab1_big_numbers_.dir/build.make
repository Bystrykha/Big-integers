# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sem2Lab1_big_numbers_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sem2Lab1_big_numbers_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sem2Lab1_big_numbers_.dir/flags.make

CMakeFiles/sem2Lab1_big_numbers_.dir/main.cpp.obj: CMakeFiles/sem2Lab1_big_numbers_.dir/flags.make
CMakeFiles/sem2Lab1_big_numbers_.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sem2Lab1_big_numbers_.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sem2Lab1_big_numbers_.dir\main.cpp.obj -c C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\main.cpp

CMakeFiles/sem2Lab1_big_numbers_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sem2Lab1_big_numbers_.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\main.cpp > CMakeFiles\sem2Lab1_big_numbers_.dir\main.cpp.i

CMakeFiles/sem2Lab1_big_numbers_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sem2Lab1_big_numbers_.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\main.cpp -o CMakeFiles\sem2Lab1_big_numbers_.dir\main.cpp.s

CMakeFiles/sem2Lab1_big_numbers_.dir/Big_Number.cpp.obj: CMakeFiles/sem2Lab1_big_numbers_.dir/flags.make
CMakeFiles/sem2Lab1_big_numbers_.dir/Big_Number.cpp.obj: ../Big_Number.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sem2Lab1_big_numbers_.dir/Big_Number.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sem2Lab1_big_numbers_.dir\Big_Number.cpp.obj -c C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\Big_Number.cpp

CMakeFiles/sem2Lab1_big_numbers_.dir/Big_Number.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sem2Lab1_big_numbers_.dir/Big_Number.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\Big_Number.cpp > CMakeFiles\sem2Lab1_big_numbers_.dir\Big_Number.cpp.i

CMakeFiles/sem2Lab1_big_numbers_.dir/Big_Number.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sem2Lab1_big_numbers_.dir/Big_Number.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\Big_Number.cpp -o CMakeFiles\sem2Lab1_big_numbers_.dir\Big_Number.cpp.s

# Object files for target sem2Lab1_big_numbers_
sem2Lab1_big_numbers__OBJECTS = \
"CMakeFiles/sem2Lab1_big_numbers_.dir/main.cpp.obj" \
"CMakeFiles/sem2Lab1_big_numbers_.dir/Big_Number.cpp.obj"

# External object files for target sem2Lab1_big_numbers_
sem2Lab1_big_numbers__EXTERNAL_OBJECTS =

sem2Lab1_big_numbers_.exe: CMakeFiles/sem2Lab1_big_numbers_.dir/main.cpp.obj
sem2Lab1_big_numbers_.exe: CMakeFiles/sem2Lab1_big_numbers_.dir/Big_Number.cpp.obj
sem2Lab1_big_numbers_.exe: CMakeFiles/sem2Lab1_big_numbers_.dir/build.make
sem2Lab1_big_numbers_.exe: CMakeFiles/sem2Lab1_big_numbers_.dir/linklibs.rsp
sem2Lab1_big_numbers_.exe: CMakeFiles/sem2Lab1_big_numbers_.dir/objects1.rsp
sem2Lab1_big_numbers_.exe: CMakeFiles/sem2Lab1_big_numbers_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sem2Lab1_big_numbers_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sem2Lab1_big_numbers_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sem2Lab1_big_numbers_.dir/build: sem2Lab1_big_numbers_.exe

.PHONY : CMakeFiles/sem2Lab1_big_numbers_.dir/build

CMakeFiles/sem2Lab1_big_numbers_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sem2Lab1_big_numbers_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sem2Lab1_big_numbers_.dir/clean

CMakeFiles/sem2Lab1_big_numbers_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers) C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers) C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\cmake-build-debug C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\cmake-build-debug C:\Users\Asus\CLionProjects\sem2Lab1(big_numbers)\cmake-build-debug\CMakeFiles\sem2Lab1_big_numbers_.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sem2Lab1_big_numbers_.dir/depend

