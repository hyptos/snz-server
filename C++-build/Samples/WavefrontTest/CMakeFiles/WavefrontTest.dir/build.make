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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/antoine/Documents/MIF39/snz-server/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antoine/Documents/MIF39/snz-server/C++-build

# Include any dependencies generated for this target.
include Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/depend.make

# Include the progress variables for this target.
include Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/progress.make

# Include the compile flags for this target's objects.
include Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/flags.make

Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o: Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/flags.make
Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o: /home/antoine/Documents/MIF39/snz-server/C++/Samples/WavefrontTest/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antoine/Documents/MIF39/snz-server/C++-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Samples/WavefrontTest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/WavefrontTest.dir/main.cpp.o -c /home/antoine/Documents/MIF39/snz-server/C++/Samples/WavefrontTest/main.cpp

Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WavefrontTest.dir/main.cpp.i"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Samples/WavefrontTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antoine/Documents/MIF39/snz-server/C++/Samples/WavefrontTest/main.cpp > CMakeFiles/WavefrontTest.dir/main.cpp.i

Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WavefrontTest.dir/main.cpp.s"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Samples/WavefrontTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antoine/Documents/MIF39/snz-server/C++/Samples/WavefrontTest/main.cpp -o CMakeFiles/WavefrontTest.dir/main.cpp.s

Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o.requires:
.PHONY : Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o.requires

Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o.provides: Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o.requires
	$(MAKE) -f Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/build.make Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o.provides.build
.PHONY : Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o.provides

Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o.provides.build: Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o

# Object files for target WavefrontTest
WavefrontTest_OBJECTS = \
"CMakeFiles/WavefrontTest.dir/main.cpp.o"

# External object files for target WavefrontTest
WavefrontTest_EXTERNAL_OBJECTS =

bin/WavefrontTest: Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o
bin/WavefrontTest: Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/build.make
bin/WavefrontTest: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Core.so.5.4.1
bin/WavefrontTest: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Gui.so.5.4.1
bin/WavefrontTest: lib/libUtility.so
bin/WavefrontTest: lib/libAssetInterfaces.so
bin/WavefrontTest: lib/libAssetGenerics.so
bin/WavefrontTest: lib/libAssets.so
bin/WavefrontTest: lib/libWavefront.so
bin/WavefrontTest: lib/libQImageLoader.so
bin/WavefrontTest: lib/libAssets.so
bin/WavefrontTest: lib/libAssetGenerics.so
bin/WavefrontTest: lib/libAssetInterfaces.so
bin/WavefrontTest: lib/libUtility.so
bin/WavefrontTest: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Gui.so.5.4.1
bin/WavefrontTest: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Core.so.5.4.1
bin/WavefrontTest: Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/WavefrontTest"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Samples/WavefrontTest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WavefrontTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/build: bin/WavefrontTest
.PHONY : Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/build

Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/requires: Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/main.cpp.o.requires
.PHONY : Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/requires

Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/clean:
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Samples/WavefrontTest && $(CMAKE_COMMAND) -P CMakeFiles/WavefrontTest.dir/cmake_clean.cmake
.PHONY : Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/clean

Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/depend:
	cd /home/antoine/Documents/MIF39/snz-server/C++-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antoine/Documents/MIF39/snz-server/C++ /home/antoine/Documents/MIF39/snz-server/C++/Samples/WavefrontTest /home/antoine/Documents/MIF39/snz-server/C++-build /home/antoine/Documents/MIF39/snz-server/C++-build/Samples/WavefrontTest /home/antoine/Documents/MIF39/snz-server/C++-build/Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Samples/WavefrontTest/CMakeFiles/WavefrontTest.dir/depend

