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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/batailleNavale.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/batailleNavale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/batailleNavale.dir/flags.make

CMakeFiles/batailleNavale.dir/main.c.obj: CMakeFiles/batailleNavale.dir/flags.make
CMakeFiles/batailleNavale.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/batailleNavale.dir/main.c.obj"
	C:\MinGW\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\batailleNavale.dir\main.c.obj   -c C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale\main.c

CMakeFiles/batailleNavale.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/batailleNavale.dir/main.c.i"
	C:\MinGW\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale\main.c > CMakeFiles\batailleNavale.dir\main.c.i

CMakeFiles/batailleNavale.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/batailleNavale.dir/main.c.s"
	C:\MinGW\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale\main.c -o CMakeFiles\batailleNavale.dir\main.c.s

# Object files for target batailleNavale
batailleNavale_OBJECTS = \
"CMakeFiles/batailleNavale.dir/main.c.obj"

# External object files for target batailleNavale
batailleNavale_EXTERNAL_OBJECTS =

batailleNavale.exe: CMakeFiles/batailleNavale.dir/main.c.obj
batailleNavale.exe: CMakeFiles/batailleNavale.dir/build.make
batailleNavale.exe: CMakeFiles/batailleNavale.dir/linklibs.rsp
batailleNavale.exe: CMakeFiles/batailleNavale.dir/objects1.rsp
batailleNavale.exe: CMakeFiles/batailleNavale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable batailleNavale.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\batailleNavale.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/batailleNavale.dir/build: batailleNavale.exe

.PHONY : CMakeFiles/batailleNavale.dir/build

CMakeFiles/batailleNavale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\batailleNavale.dir\cmake_clean.cmake
.PHONY : CMakeFiles/batailleNavale.dir/clean

CMakeFiles/batailleNavale.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale\cmake-build-debug C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale\cmake-build-debug C:\Users\Axel.PITTET\Documents\GitHub\Bataille-navale\batailleNavale\cmake-build-debug\CMakeFiles\batailleNavale.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/batailleNavale.dir/depend

