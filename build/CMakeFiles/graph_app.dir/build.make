# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build"

# Include any dependencies generated for this target.
include CMakeFiles/graph_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/graph_app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/graph_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graph_app.dir/flags.make

CMakeFiles/graph_app.dir/src/graph_app.cpp.o: CMakeFiles/graph_app.dir/flags.make
CMakeFiles/graph_app.dir/src/graph_app.cpp.o: /Users/ansen/Documents/Programming\ Projects/CS\ 251/CS251_Project4/src/graph_app.cpp
CMakeFiles/graph_app.dir/src/graph_app.cpp.o: CMakeFiles/graph_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graph_app.dir/src/graph_app.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph_app.dir/src/graph_app.cpp.o -MF CMakeFiles/graph_app.dir/src/graph_app.cpp.o.d -o CMakeFiles/graph_app.dir/src/graph_app.cpp.o -c "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/graph_app.cpp"

CMakeFiles/graph_app.dir/src/graph_app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/graph_app.dir/src/graph_app.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/graph_app.cpp" > CMakeFiles/graph_app.dir/src/graph_app.cpp.i

CMakeFiles/graph_app.dir/src/graph_app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/graph_app.dir/src/graph_app.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/graph_app.cpp" -o CMakeFiles/graph_app.dir/src/graph_app.cpp.s

# Object files for target graph_app
graph_app_OBJECTS = \
"CMakeFiles/graph_app.dir/src/graph_app.cpp.o"

# External object files for target graph_app
graph_app_EXTERNAL_OBJECTS =

graph_app: CMakeFiles/graph_app.dir/src/graph_app.cpp.o
graph_app: CMakeFiles/graph_app.dir/build.make
graph_app: libproject4.a
graph_app: CMakeFiles/graph_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable graph_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graph_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graph_app.dir/build: graph_app
.PHONY : CMakeFiles/graph_app.dir/build

CMakeFiles/graph_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graph_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graph_app.dir/clean

CMakeFiles/graph_app.dir/depend:
	cd "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles/graph_app.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/graph_app.dir/depend
