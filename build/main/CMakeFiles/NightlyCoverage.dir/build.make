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

# Utility rule file for NightlyCoverage.

# Include any custom commands dependencies for this target.
include main/CMakeFiles/NightlyCoverage.dir/compiler_depend.make

# Include the progress variables for this target.
include main/CMakeFiles/NightlyCoverage.dir/progress.make

main/CMakeFiles/NightlyCoverage:
	cd /Users/james/Projects/exchange/build/main && /Users/james/miniforge3/envs/exchange/bin/ctest -D NightlyCoverage

NightlyCoverage: main/CMakeFiles/NightlyCoverage
NightlyCoverage: main/CMakeFiles/NightlyCoverage.dir/build.make
.PHONY : NightlyCoverage

# Rule to build all files generated by this target.
main/CMakeFiles/NightlyCoverage.dir/build: NightlyCoverage
.PHONY : main/CMakeFiles/NightlyCoverage.dir/build

main/CMakeFiles/NightlyCoverage.dir/clean:
	cd /Users/james/Projects/exchange/build/main && $(CMAKE_COMMAND) -P CMakeFiles/NightlyCoverage.dir/cmake_clean.cmake
.PHONY : main/CMakeFiles/NightlyCoverage.dir/clean

main/CMakeFiles/NightlyCoverage.dir/depend:
	cd /Users/james/Projects/exchange/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/Projects/exchange /Users/james/Projects/exchange/main /Users/james/Projects/exchange/build /Users/james/Projects/exchange/build/main /Users/james/Projects/exchange/build/main/CMakeFiles/NightlyCoverage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : main/CMakeFiles/NightlyCoverage.dir/depend

