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
include tests/CMakeFiles/test-usersInit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test-usersInit.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test-usersInit.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test-usersInit.dir/flags.make

tests/CMakeFiles/test-usersInit.dir/TestOrders.cpp.o: tests/CMakeFiles/test-usersInit.dir/flags.make
tests/CMakeFiles/test-usersInit.dir/TestOrders.cpp.o: /Users/james/Projects/exchange/tests/TestOrders.cpp
tests/CMakeFiles/test-usersInit.dir/TestOrders.cpp.o: tests/CMakeFiles/test-usersInit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/james/Projects/exchange/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test-usersInit.dir/TestOrders.cpp.o"
	cd /Users/james/Projects/exchange/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test-usersInit.dir/TestOrders.cpp.o -MF CMakeFiles/test-usersInit.dir/TestOrders.cpp.o.d -o CMakeFiles/test-usersInit.dir/TestOrders.cpp.o -c /Users/james/Projects/exchange/tests/TestOrders.cpp

tests/CMakeFiles/test-usersInit.dir/TestOrders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-usersInit.dir/TestOrders.cpp.i"
	cd /Users/james/Projects/exchange/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/james/Projects/exchange/tests/TestOrders.cpp > CMakeFiles/test-usersInit.dir/TestOrders.cpp.i

tests/CMakeFiles/test-usersInit.dir/TestOrders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-usersInit.dir/TestOrders.cpp.s"
	cd /Users/james/Projects/exchange/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/james/Projects/exchange/tests/TestOrders.cpp -o CMakeFiles/test-usersInit.dir/TestOrders.cpp.s

# Object files for target test-usersInit
test__usersInit_OBJECTS = \
"CMakeFiles/test-usersInit.dir/TestOrders.cpp.o"

# External object files for target test-usersInit
test__usersInit_EXTERNAL_OBJECTS =

tests/test-usersInit: tests/CMakeFiles/test-usersInit.dir/TestOrders.cpp.o
tests/test-usersInit: tests/CMakeFiles/test-usersInit.dir/build.make
tests/test-usersInit: lib/libgtest_main.a
tests/test-usersInit: usersInit/libusersInit.a
tests/test-usersInit: lib/libgtest.a
tests/test-usersInit: tests/CMakeFiles/test-usersInit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/james/Projects/exchange/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-usersInit"
	cd /Users/james/Projects/exchange/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-usersInit.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/james/Projects/exchange/build/tests && /Users/james/miniforge3/envs/exchange/bin/cmake -D TEST_TARGET=test-usersInit -D TEST_EXECUTABLE=/Users/james/Projects/exchange/build/tests/test-usersInit -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/james/Projects/exchange/build/tests -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test-usersInit_TESTS -D CTEST_FILE=/Users/james/Projects/exchange/build/tests/test-usersInit[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /Users/james/miniforge3/envs/exchange/share/cmake-3.26/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
tests/CMakeFiles/test-usersInit.dir/build: tests/test-usersInit
.PHONY : tests/CMakeFiles/test-usersInit.dir/build

tests/CMakeFiles/test-usersInit.dir/clean:
	cd /Users/james/Projects/exchange/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test-usersInit.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test-usersInit.dir/clean

tests/CMakeFiles/test-usersInit.dir/depend:
	cd /Users/james/Projects/exchange/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/james/Projects/exchange /Users/james/Projects/exchange/tests /Users/james/Projects/exchange/build /Users/james/Projects/exchange/build/tests /Users/james/Projects/exchange/build/tests/CMakeFiles/test-usersInit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test-usersInit.dir/depend

