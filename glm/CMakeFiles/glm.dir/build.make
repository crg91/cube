# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/crg/Downloads/glm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crg/Downloads/glm

# Include any dependencies generated for this target.
include glm/CMakeFiles/glm.dir/depend.make

# Include the progress variables for this target.
include glm/CMakeFiles/glm.dir/progress.make

# Include the compile flags for this target's objects.
include glm/CMakeFiles/glm.dir/flags.make

glm/CMakeFiles/glm.dir/core/dummy.cpp.o: glm/CMakeFiles/glm.dir/flags.make
glm/CMakeFiles/glm.dir/core/dummy.cpp.o: glm/core/dummy.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/crg/Downloads/glm/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glm/CMakeFiles/glm.dir/core/dummy.cpp.o"
	cd /home/crg/Downloads/glm/glm && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glm.dir/core/dummy.cpp.o -c /home/crg/Downloads/glm/glm/core/dummy.cpp

glm/CMakeFiles/glm.dir/core/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glm.dir/core/dummy.cpp.i"
	cd /home/crg/Downloads/glm/glm && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/crg/Downloads/glm/glm/core/dummy.cpp > CMakeFiles/glm.dir/core/dummy.cpp.i

glm/CMakeFiles/glm.dir/core/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glm.dir/core/dummy.cpp.s"
	cd /home/crg/Downloads/glm/glm && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/crg/Downloads/glm/glm/core/dummy.cpp -o CMakeFiles/glm.dir/core/dummy.cpp.s

glm/CMakeFiles/glm.dir/core/dummy.cpp.o.requires:
.PHONY : glm/CMakeFiles/glm.dir/core/dummy.cpp.o.requires

glm/CMakeFiles/glm.dir/core/dummy.cpp.o.provides: glm/CMakeFiles/glm.dir/core/dummy.cpp.o.requires
	$(MAKE) -f glm/CMakeFiles/glm.dir/build.make glm/CMakeFiles/glm.dir/core/dummy.cpp.o.provides.build
.PHONY : glm/CMakeFiles/glm.dir/core/dummy.cpp.o.provides

glm/CMakeFiles/glm.dir/core/dummy.cpp.o.provides.build: glm/CMakeFiles/glm.dir/core/dummy.cpp.o

# Object files for target glm
glm_OBJECTS = \
"CMakeFiles/glm.dir/core/dummy.cpp.o"

# External object files for target glm
glm_EXTERNAL_OBJECTS =

glm/glm: glm/CMakeFiles/glm.dir/core/dummy.cpp.o
glm/glm: glm/CMakeFiles/glm.dir/build.make
glm/glm: glm/CMakeFiles/glm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable glm"
	cd /home/crg/Downloads/glm/glm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glm/CMakeFiles/glm.dir/build: glm/glm
.PHONY : glm/CMakeFiles/glm.dir/build

glm/CMakeFiles/glm.dir/requires: glm/CMakeFiles/glm.dir/core/dummy.cpp.o.requires
.PHONY : glm/CMakeFiles/glm.dir/requires

glm/CMakeFiles/glm.dir/clean:
	cd /home/crg/Downloads/glm/glm && $(CMAKE_COMMAND) -P CMakeFiles/glm.dir/cmake_clean.cmake
.PHONY : glm/CMakeFiles/glm.dir/clean

glm/CMakeFiles/glm.dir/depend:
	cd /home/crg/Downloads/glm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crg/Downloads/glm /home/crg/Downloads/glm/glm /home/crg/Downloads/glm /home/crg/Downloads/glm/glm /home/crg/Downloads/glm/glm/CMakeFiles/glm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glm/CMakeFiles/glm.dir/depend

