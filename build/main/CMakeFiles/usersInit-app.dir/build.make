# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/james/miniforge3/envs/exchange/bin/cmake

# The command to remove a file.
RM = /Users/james/miniforge3/envs/exchange/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/james/Projects/exchange

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/james/Projects/exchange/build

# Include any dependencies generated for this target.
include main/CMakeFiles/usersInit-app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include main/CMakeFiles/usersInit-app.dir/compiler_depend.make

# Include the progress variables for this target.
include main/CMakeFiles/usersInit-app.dir/progress.make

# Include the compile flags for this target's objects.
include main/CMakeFiles/usersInit-app.dir/flags.make

main/CMakeFiles/usersInit-app.dir/main.cpp.o: main/CMakeFiles/usersInit-app.dir/flags.make
main/CMakeFiles/usersInit-app.dir/main.cpp.o: /Users/james/Projects/exchange/main/main.cpp
main/CMakeFiles/usersInit-app.dir/main.cpp.o: main/CMakeFiles/usersInit-app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/Projects/exchange/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object main/CMakeFiles/usersInit-app.dir/main.cpp.o"
	cd /Users/james/Projects/exchange/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT main/CMakeFiles/usersInit-app.dir/main.cpp.o -MF CMakeFiles/usersInit-app.dir/main.cpp.o.d -o CMakeFiles/usersInit-app.dir/main.cpp.o -c /Users/james/Projects/exchange/main/main.cpp

main/CMakeFiles/usersInit-app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/usersInit-app.dir/main.cpp.i"
	cd /Users/james/Projects/exchange/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/Projects/exchange/main/main.cpp > CMakeFiles/usersInit-app.dir/main.cpp.i

main/CMakeFiles/usersInit-app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/usersInit-app.dir/main.cpp.s"
	cd /Users/james/Projects/exchange/build/main && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/Projects/exchange/main/main.cpp -o CMakeFiles/usersInit-app.dir/main.cpp.s

# Object files for target usersInit-app
usersInit__app_OBJECTS = \
"CMakeFiles/usersInit-app.dir/main.cpp.o"

# External object files for target usersInit-app
usersInit__app_EXTERNAL_OBJECTS =

main/usersInit-app: main/CMakeFiles/usersInit-app.dir/main.cpp.o
main/usersInit-app: main/CMakeFiles/usersInit-app.dir/build.make
main/usersInit-app: usersInit/libusersInit.a
main/usersInit-app: main/CMakeFiles/usersInit-app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/Projects/exchange/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable usersInit-app"
	cd /Users/james/Projects/exchange/build/main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/usersInit-app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main/CMakeFiles/usersInit-app.dir/build: main/usersInit-app
.PHONY : main/CMakeFiles/usersInit-app.dir/build

main/CMakeFiles/usersInit-app.dir/clean:
	cd /Users/james/Projects/exchange/build/main && $(CMAKE_COMMAND) -P CMakeFiles/usersInit-app.dir/cmake_clean.cmake
.PHONY : main/CMakeFiles/usersInit-app.dir/clean

main/CMakeFiles/usersInit-app.dir/depend:
	cd /Users/james/Projects/exchange/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/Projects/exchange /Users/james/Projects/exchange/main /Users/james/Projects/exchange/build /Users/james/Projects/exchange/build/main /Users/james/Projects/exchange/build/main/CMakeFiles/usersInit-app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : main/CMakeFiles/usersInit-app.dir/depend

