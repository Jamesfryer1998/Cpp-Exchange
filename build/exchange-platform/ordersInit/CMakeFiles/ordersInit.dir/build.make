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
include exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/compiler_depend.make

# Include the progress variables for this target.
include exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/progress.make

# Include the compile flags for this target's objects.
include exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/flags.make

exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/main.cpp.o: exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/flags.make
exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/main.cpp.o: /Users/james/Projects/exchange/exchange-platform/ordersInit/main.cpp
exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/main.cpp.o: exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/Projects/exchange/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/main.cpp.o"
	cd /Users/james/Projects/exchange/build/exchange-platform/ordersInit && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/main.cpp.o -MF CMakeFiles/ordersInit.dir/main.cpp.o.d -o CMakeFiles/ordersInit.dir/main.cpp.o -c /Users/james/Projects/exchange/exchange-platform/ordersInit/main.cpp

exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ordersInit.dir/main.cpp.i"
	cd /Users/james/Projects/exchange/build/exchange-platform/ordersInit && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/Projects/exchange/exchange-platform/ordersInit/main.cpp > CMakeFiles/ordersInit.dir/main.cpp.i

exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ordersInit.dir/main.cpp.s"
	cd /Users/james/Projects/exchange/build/exchange-platform/ordersInit && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/Projects/exchange/exchange-platform/ordersInit/main.cpp -o CMakeFiles/ordersInit.dir/main.cpp.s

# Object files for target ordersInit
ordersInit_OBJECTS = \
"CMakeFiles/ordersInit.dir/main.cpp.o"

# External object files for target ordersInit
ordersInit_EXTERNAL_OBJECTS =

exchange-platform/ordersInit/libordersInit.a: exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/main.cpp.o
exchange-platform/ordersInit/libordersInit.a: exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/build.make
exchange-platform/ordersInit/libordersInit.a: exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/Projects/exchange/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libordersInit.a"
	cd /Users/james/Projects/exchange/build/exchange-platform/ordersInit && $(CMAKE_COMMAND) -P CMakeFiles/ordersInit.dir/cmake_clean_target.cmake
	cd /Users/james/Projects/exchange/build/exchange-platform/ordersInit && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ordersInit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/build: exchange-platform/ordersInit/libordersInit.a
.PHONY : exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/build

exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/clean:
	cd /Users/james/Projects/exchange/build/exchange-platform/ordersInit && $(CMAKE_COMMAND) -P CMakeFiles/ordersInit.dir/cmake_clean.cmake
.PHONY : exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/clean

exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/depend:
	cd /Users/james/Projects/exchange/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/Projects/exchange /Users/james/Projects/exchange/exchange-platform/ordersInit /Users/james/Projects/exchange/build /Users/james/Projects/exchange/build/exchange-platform/ordersInit /Users/james/Projects/exchange/build/exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : exchange-platform/ordersInit/CMakeFiles/ordersInit.dir/depend

