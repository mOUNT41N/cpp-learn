# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Application\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\Application\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code\c++\c++learn\worker_mangement_system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\c++\c++learn\worker_mangement_system\build

# Utility rule file for ContinuousStart.

# Include any custom commands dependencies for this target.
include CMakeFiles/ContinuousStart.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ContinuousStart.dir/progress.make

CMakeFiles/ContinuousStart:
	D:\Application\CMake\bin\ctest.exe -D ContinuousStart

ContinuousStart: CMakeFiles/ContinuousStart
ContinuousStart: CMakeFiles/ContinuousStart.dir/build.make
.PHONY : ContinuousStart

# Rule to build all files generated by this target.
CMakeFiles/ContinuousStart.dir/build: ContinuousStart
.PHONY : CMakeFiles/ContinuousStart.dir/build

CMakeFiles/ContinuousStart.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ContinuousStart.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousStart.dir/clean

CMakeFiles/ContinuousStart.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\c++\c++learn\worker_mangement_system D:\Code\c++\c++learn\worker_mangement_system D:\Code\c++\c++learn\worker_mangement_system\build D:\Code\c++\c++learn\worker_mangement_system\build D:\Code\c++\c++learn\worker_mangement_system\build\CMakeFiles\ContinuousStart.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousStart.dir/depend

