# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/My Passport/Competitive Programming/Strings"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/My Passport/Competitive Programming/Strings/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Strings.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Strings.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Strings.dir/flags.make

CMakeFiles/Strings.dir/main.cpp.o: CMakeFiles/Strings.dir/flags.make
CMakeFiles/Strings.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/My Passport/Competitive Programming/Strings/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Strings.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Strings.dir/main.cpp.o -c "/Volumes/My Passport/Competitive Programming/Strings/main.cpp"

CMakeFiles/Strings.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Strings.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/My Passport/Competitive Programming/Strings/main.cpp" > CMakeFiles/Strings.dir/main.cpp.i

CMakeFiles/Strings.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Strings.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/My Passport/Competitive Programming/Strings/main.cpp" -o CMakeFiles/Strings.dir/main.cpp.s

CMakeFiles/Strings.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Strings.dir/main.cpp.o.requires

CMakeFiles/Strings.dir/main.cpp.o.provides: CMakeFiles/Strings.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Strings.dir/build.make CMakeFiles/Strings.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Strings.dir/main.cpp.o.provides

CMakeFiles/Strings.dir/main.cpp.o.provides.build: CMakeFiles/Strings.dir/main.cpp.o


# Object files for target Strings
Strings_OBJECTS = \
"CMakeFiles/Strings.dir/main.cpp.o"

# External object files for target Strings
Strings_EXTERNAL_OBJECTS =

Strings: CMakeFiles/Strings.dir/main.cpp.o
Strings: CMakeFiles/Strings.dir/build.make
Strings: CMakeFiles/Strings.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/My Passport/Competitive Programming/Strings/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Strings"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Strings.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Strings.dir/build: Strings

.PHONY : CMakeFiles/Strings.dir/build

CMakeFiles/Strings.dir/requires: CMakeFiles/Strings.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Strings.dir/requires

CMakeFiles/Strings.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Strings.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Strings.dir/clean

CMakeFiles/Strings.dir/depend:
	cd "/Volumes/My Passport/Competitive Programming/Strings/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/My Passport/Competitive Programming/Strings" "/Volumes/My Passport/Competitive Programming/Strings" "/Volumes/My Passport/Competitive Programming/Strings/cmake-build-debug" "/Volumes/My Passport/Competitive Programming/Strings/cmake-build-debug" "/Volumes/My Passport/Competitive Programming/Strings/cmake-build-debug/CMakeFiles/Strings.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Strings.dir/depend

