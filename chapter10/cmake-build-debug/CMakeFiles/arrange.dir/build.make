# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/e/projects/cpp/data_structure/chapter10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/projects/cpp/data_structure/chapter10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/arrange.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/arrange.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/arrange.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arrange.dir/flags.make

CMakeFiles/arrange.dir/arrange.cpp.o: CMakeFiles/arrange.dir/flags.make
CMakeFiles/arrange.dir/arrange.cpp.o: ../arrange.cpp
CMakeFiles/arrange.dir/arrange.cpp.o: CMakeFiles/arrange.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/projects/cpp/data_structure/chapter10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arrange.dir/arrange.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/arrange.dir/arrange.cpp.o -MF CMakeFiles/arrange.dir/arrange.cpp.o.d -o CMakeFiles/arrange.dir/arrange.cpp.o -c /mnt/e/projects/cpp/data_structure/chapter10/arrange.cpp

CMakeFiles/arrange.dir/arrange.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrange.dir/arrange.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/projects/cpp/data_structure/chapter10/arrange.cpp > CMakeFiles/arrange.dir/arrange.cpp.i

CMakeFiles/arrange.dir/arrange.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrange.dir/arrange.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/projects/cpp/data_structure/chapter10/arrange.cpp -o CMakeFiles/arrange.dir/arrange.cpp.s

# Object files for target arrange
arrange_OBJECTS = \
"CMakeFiles/arrange.dir/arrange.cpp.o"

# External object files for target arrange
arrange_EXTERNAL_OBJECTS =

arrange: CMakeFiles/arrange.dir/arrange.cpp.o
arrange: CMakeFiles/arrange.dir/build.make
arrange: CMakeFiles/arrange.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/projects/cpp/data_structure/chapter10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arrange"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arrange.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arrange.dir/build: arrange
.PHONY : CMakeFiles/arrange.dir/build

CMakeFiles/arrange.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arrange.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arrange.dir/clean

CMakeFiles/arrange.dir/depend:
	cd /mnt/e/projects/cpp/data_structure/chapter10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/projects/cpp/data_structure/chapter10 /mnt/e/projects/cpp/data_structure/chapter10 /mnt/e/projects/cpp/data_structure/chapter10/cmake-build-debug /mnt/e/projects/cpp/data_structure/chapter10/cmake-build-debug /mnt/e/projects/cpp/data_structure/chapter10/cmake-build-debug/CMakeFiles/arrange.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arrange.dir/depend
