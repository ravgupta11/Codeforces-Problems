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
CMAKE_SOURCE_DIR = "/Volumes/My Passport/Competitive Programming/Math/uva10469"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/My Passport/Competitive Programming/Math/uva10469/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/uva10469.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uva10469.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uva10469.dir/flags.make

CMakeFiles/uva10469.dir/main.cpp.o: CMakeFiles/uva10469.dir/flags.make
CMakeFiles/uva10469.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/My Passport/Competitive Programming/Math/uva10469/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uva10469.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uva10469.dir/main.cpp.o -c "/Volumes/My Passport/Competitive Programming/Math/uva10469/main.cpp"

CMakeFiles/uva10469.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uva10469.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/My Passport/Competitive Programming/Math/uva10469/main.cpp" > CMakeFiles/uva10469.dir/main.cpp.i

CMakeFiles/uva10469.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uva10469.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/My Passport/Competitive Programming/Math/uva10469/main.cpp" -o CMakeFiles/uva10469.dir/main.cpp.s

CMakeFiles/uva10469.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/uva10469.dir/main.cpp.o.requires

CMakeFiles/uva10469.dir/main.cpp.o.provides: CMakeFiles/uva10469.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/uva10469.dir/build.make CMakeFiles/uva10469.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/uva10469.dir/main.cpp.o.provides

CMakeFiles/uva10469.dir/main.cpp.o.provides.build: CMakeFiles/uva10469.dir/main.cpp.o


# Object files for target uva10469
uva10469_OBJECTS = \
"CMakeFiles/uva10469.dir/main.cpp.o"

# External object files for target uva10469
uva10469_EXTERNAL_OBJECTS =

uva10469: CMakeFiles/uva10469.dir/main.cpp.o
uva10469: CMakeFiles/uva10469.dir/build.make
uva10469: CMakeFiles/uva10469.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/My Passport/Competitive Programming/Math/uva10469/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable uva10469"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uva10469.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uva10469.dir/build: uva10469

.PHONY : CMakeFiles/uva10469.dir/build

CMakeFiles/uva10469.dir/requires: CMakeFiles/uva10469.dir/main.cpp.o.requires

.PHONY : CMakeFiles/uva10469.dir/requires

CMakeFiles/uva10469.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/uva10469.dir/cmake_clean.cmake
.PHONY : CMakeFiles/uva10469.dir/clean

CMakeFiles/uva10469.dir/depend:
	cd "/Volumes/My Passport/Competitive Programming/Math/uva10469/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/My Passport/Competitive Programming/Math/uva10469" "/Volumes/My Passport/Competitive Programming/Math/uva10469" "/Volumes/My Passport/Competitive Programming/Math/uva10469/cmake-build-debug" "/Volumes/My Passport/Competitive Programming/Math/uva10469/cmake-build-debug" "/Volumes/My Passport/Competitive Programming/Math/uva10469/cmake-build-debug/CMakeFiles/uva10469.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/uva10469.dir/depend

