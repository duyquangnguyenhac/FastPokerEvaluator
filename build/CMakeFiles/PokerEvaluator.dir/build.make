# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/quangnguyen/Developer/Cpp/PokerEvaluator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/quangnguyen/Developer/Cpp/PokerEvaluator/build

# Include any dependencies generated for this target.
include CMakeFiles/PokerEvaluator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PokerEvaluator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PokerEvaluator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PokerEvaluator.dir/flags.make

CMakeFiles/PokerEvaluator.dir/src/main.cpp.o: CMakeFiles/PokerEvaluator.dir/flags.make
CMakeFiles/PokerEvaluator.dir/src/main.cpp.o: /Users/quangnguyen/Developer/Cpp/PokerEvaluator/src/main.cpp
CMakeFiles/PokerEvaluator.dir/src/main.cpp.o: CMakeFiles/PokerEvaluator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/quangnguyen/Developer/Cpp/PokerEvaluator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PokerEvaluator.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PokerEvaluator.dir/src/main.cpp.o -MF CMakeFiles/PokerEvaluator.dir/src/main.cpp.o.d -o CMakeFiles/PokerEvaluator.dir/src/main.cpp.o -c /Users/quangnguyen/Developer/Cpp/PokerEvaluator/src/main.cpp

CMakeFiles/PokerEvaluator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PokerEvaluator.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/quangnguyen/Developer/Cpp/PokerEvaluator/src/main.cpp > CMakeFiles/PokerEvaluator.dir/src/main.cpp.i

CMakeFiles/PokerEvaluator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PokerEvaluator.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/quangnguyen/Developer/Cpp/PokerEvaluator/src/main.cpp -o CMakeFiles/PokerEvaluator.dir/src/main.cpp.s

# Object files for target PokerEvaluator
PokerEvaluator_OBJECTS = \
"CMakeFiles/PokerEvaluator.dir/src/main.cpp.o"

# External object files for target PokerEvaluator
PokerEvaluator_EXTERNAL_OBJECTS =

PokerEvaluator: CMakeFiles/PokerEvaluator.dir/src/main.cpp.o
PokerEvaluator: CMakeFiles/PokerEvaluator.dir/build.make
PokerEvaluator: CMakeFiles/PokerEvaluator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/quangnguyen/Developer/Cpp/PokerEvaluator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PokerEvaluator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PokerEvaluator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PokerEvaluator.dir/build: PokerEvaluator
.PHONY : CMakeFiles/PokerEvaluator.dir/build

CMakeFiles/PokerEvaluator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PokerEvaluator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PokerEvaluator.dir/clean

CMakeFiles/PokerEvaluator.dir/depend:
	cd /Users/quangnguyen/Developer/Cpp/PokerEvaluator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/quangnguyen/Developer/Cpp/PokerEvaluator /Users/quangnguyen/Developer/Cpp/PokerEvaluator /Users/quangnguyen/Developer/Cpp/PokerEvaluator/build /Users/quangnguyen/Developer/Cpp/PokerEvaluator/build /Users/quangnguyen/Developer/Cpp/PokerEvaluator/build/CMakeFiles/PokerEvaluator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PokerEvaluator.dir/depend
