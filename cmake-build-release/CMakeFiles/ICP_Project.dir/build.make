# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:\Sources_Code\ICP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:\Sources_Code\ICP\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/ICP_Project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ICP_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ICP_Project.dir/flags.make

CMakeFiles/ICP_Project.dir/main.c.obj: CMakeFiles/ICP_Project.dir/flags.make
CMakeFiles/ICP_Project.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\Sources_Code\ICP\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ICP_Project.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ICP_Project.dir\main.c.obj   -c H:\Sources_Code\ICP\main.c

CMakeFiles/ICP_Project.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ICP_Project.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E H:\Sources_Code\ICP\main.c > CMakeFiles\ICP_Project.dir\main.c.i

CMakeFiles/ICP_Project.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ICP_Project.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S H:\Sources_Code\ICP\main.c -o CMakeFiles\ICP_Project.dir\main.c.s

# Object files for target ICP_Project
ICP_Project_OBJECTS = \
"CMakeFiles/ICP_Project.dir/main.c.obj"

# External object files for target ICP_Project
ICP_Project_EXTERNAL_OBJECTS =

ICP_Project.exe: CMakeFiles/ICP_Project.dir/main.c.obj
ICP_Project.exe: CMakeFiles/ICP_Project.dir/build.make
ICP_Project.exe: CMakeFiles/ICP_Project.dir/linklibs.rsp
ICP_Project.exe: CMakeFiles/ICP_Project.dir/objects1.rsp
ICP_Project.exe: CMakeFiles/ICP_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=H:\Sources_Code\ICP\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ICP_Project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ICP_Project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ICP_Project.dir/build: ICP_Project.exe

.PHONY : CMakeFiles/ICP_Project.dir/build

CMakeFiles/ICP_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ICP_Project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ICP_Project.dir/clean

CMakeFiles/ICP_Project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\Sources_Code\ICP H:\Sources_Code\ICP H:\Sources_Code\ICP\cmake-build-release H:\Sources_Code\ICP\cmake-build-release H:\Sources_Code\ICP\cmake-build-release\CMakeFiles\ICP_Project.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ICP_Project.dir/depend

