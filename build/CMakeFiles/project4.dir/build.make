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
include CMakeFiles/project4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project4.dir/flags.make

CMakeFiles/project4.dir/src/color_walk.cpp.o: CMakeFiles/project4.dir/flags.make
CMakeFiles/project4.dir/src/color_walk.cpp.o: /Users/ansen/Documents/Programming\ Projects/CS\ 251/CS251_Project4/src/color_walk.cpp
CMakeFiles/project4.dir/src/color_walk.cpp.o: CMakeFiles/project4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project4.dir/src/color_walk.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project4.dir/src/color_walk.cpp.o -MF CMakeFiles/project4.dir/src/color_walk.cpp.o.d -o CMakeFiles/project4.dir/src/color_walk.cpp.o -c "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/color_walk.cpp"

CMakeFiles/project4.dir/src/color_walk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project4.dir/src/color_walk.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/color_walk.cpp" > CMakeFiles/project4.dir/src/color_walk.cpp.i

CMakeFiles/project4.dir/src/color_walk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project4.dir/src/color_walk.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/color_walk.cpp" -o CMakeFiles/project4.dir/src/color_walk.cpp.s

CMakeFiles/project4.dir/src/graph.cpp.o: CMakeFiles/project4.dir/flags.make
CMakeFiles/project4.dir/src/graph.cpp.o: /Users/ansen/Documents/Programming\ Projects/CS\ 251/CS251_Project4/src/graph.cpp
CMakeFiles/project4.dir/src/graph.cpp.o: CMakeFiles/project4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project4.dir/src/graph.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project4.dir/src/graph.cpp.o -MF CMakeFiles/project4.dir/src/graph.cpp.o.d -o CMakeFiles/project4.dir/src/graph.cpp.o -c "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/graph.cpp"

CMakeFiles/project4.dir/src/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project4.dir/src/graph.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/graph.cpp" > CMakeFiles/project4.dir/src/graph.cpp.i

CMakeFiles/project4.dir/src/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project4.dir/src/graph.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/graph.cpp" -o CMakeFiles/project4.dir/src/graph.cpp.s

CMakeFiles/project4.dir/src/graph_app.cpp.o: CMakeFiles/project4.dir/flags.make
CMakeFiles/project4.dir/src/graph_app.cpp.o: /Users/ansen/Documents/Programming\ Projects/CS\ 251/CS251_Project4/src/graph_app.cpp
CMakeFiles/project4.dir/src/graph_app.cpp.o: CMakeFiles/project4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project4.dir/src/graph_app.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project4.dir/src/graph_app.cpp.o -MF CMakeFiles/project4.dir/src/graph_app.cpp.o.d -o CMakeFiles/project4.dir/src/graph_app.cpp.o -c "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/graph_app.cpp"

CMakeFiles/project4.dir/src/graph_app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project4.dir/src/graph_app.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/graph_app.cpp" > CMakeFiles/project4.dir/src/graph_app.cpp.i

CMakeFiles/project4.dir/src/graph_app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project4.dir/src/graph_app.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/graph_app.cpp" -o CMakeFiles/project4.dir/src/graph_app.cpp.s

CMakeFiles/project4.dir/src/max_height.cpp.o: CMakeFiles/project4.dir/flags.make
CMakeFiles/project4.dir/src/max_height.cpp.o: /Users/ansen/Documents/Programming\ Projects/CS\ 251/CS251_Project4/src/max_height.cpp
CMakeFiles/project4.dir/src/max_height.cpp.o: CMakeFiles/project4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project4.dir/src/max_height.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project4.dir/src/max_height.cpp.o -MF CMakeFiles/project4.dir/src/max_height.cpp.o.d -o CMakeFiles/project4.dir/src/max_height.cpp.o -c "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/max_height.cpp"

CMakeFiles/project4.dir/src/max_height.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project4.dir/src/max_height.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/max_height.cpp" > CMakeFiles/project4.dir/src/max_height.cpp.i

CMakeFiles/project4.dir/src/max_height.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project4.dir/src/max_height.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/max_height.cpp" -o CMakeFiles/project4.dir/src/max_height.cpp.s

CMakeFiles/project4.dir/src/scc.cpp.o: CMakeFiles/project4.dir/flags.make
CMakeFiles/project4.dir/src/scc.cpp.o: /Users/ansen/Documents/Programming\ Projects/CS\ 251/CS251_Project4/src/scc.cpp
CMakeFiles/project4.dir/src/scc.cpp.o: CMakeFiles/project4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project4.dir/src/scc.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project4.dir/src/scc.cpp.o -MF CMakeFiles/project4.dir/src/scc.cpp.o.d -o CMakeFiles/project4.dir/src/scc.cpp.o -c "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/scc.cpp"

CMakeFiles/project4.dir/src/scc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project4.dir/src/scc.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/scc.cpp" > CMakeFiles/project4.dir/src/scc.cpp.i

CMakeFiles/project4.dir/src/scc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project4.dir/src/scc.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/src/scc.cpp" -o CMakeFiles/project4.dir/src/scc.cpp.s

# Object files for target project4
project4_OBJECTS = \
"CMakeFiles/project4.dir/src/color_walk.cpp.o" \
"CMakeFiles/project4.dir/src/graph.cpp.o" \
"CMakeFiles/project4.dir/src/graph_app.cpp.o" \
"CMakeFiles/project4.dir/src/max_height.cpp.o" \
"CMakeFiles/project4.dir/src/scc.cpp.o"

# External object files for target project4
project4_EXTERNAL_OBJECTS =

libproject4.a: CMakeFiles/project4.dir/src/color_walk.cpp.o
libproject4.a: CMakeFiles/project4.dir/src/graph.cpp.o
libproject4.a: CMakeFiles/project4.dir/src/graph_app.cpp.o
libproject4.a: CMakeFiles/project4.dir/src/max_height.cpp.o
libproject4.a: CMakeFiles/project4.dir/src/scc.cpp.o
libproject4.a: CMakeFiles/project4.dir/build.make
libproject4.a: CMakeFiles/project4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libproject4.a"
	$(CMAKE_COMMAND) -P CMakeFiles/project4.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project4.dir/build: libproject4.a
.PHONY : CMakeFiles/project4.dir/build

CMakeFiles/project4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project4.dir/clean

CMakeFiles/project4.dir/depend:
	cd "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build" "/Users/ansen/Documents/Programming Projects/CS 251/CS251_Project4/build/CMakeFiles/project4.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/project4.dir/depend

