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
include AssetGenerics/CMakeFiles/AssetGenerics.dir/depend.make

# Include the progress variables for this target.
include AssetGenerics/CMakeFiles/AssetGenerics.dir/progress.make

# Include the compile flags for this target's objects.
include AssetGenerics/CMakeFiles/AssetGenerics.dir/flags.make

AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o: AssetGenerics/CMakeFiles/AssetGenerics.dir/flags.make
AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o: /home/antoine/Documents/MIF39/snz-server/C++/AssetGenerics/generics.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antoine/Documents/MIF39/snz-server/C++-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/AssetGenerics && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AssetGenerics.dir/generics.cpp.o -c /home/antoine/Documents/MIF39/snz-server/C++/AssetGenerics/generics.cpp

AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AssetGenerics.dir/generics.cpp.i"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/AssetGenerics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antoine/Documents/MIF39/snz-server/C++/AssetGenerics/generics.cpp > CMakeFiles/AssetGenerics.dir/generics.cpp.i

AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AssetGenerics.dir/generics.cpp.s"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/AssetGenerics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antoine/Documents/MIF39/snz-server/C++/AssetGenerics/generics.cpp -o CMakeFiles/AssetGenerics.dir/generics.cpp.s

AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o.requires:
.PHONY : AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o.requires

AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o.provides: AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o.requires
	$(MAKE) -f AssetGenerics/CMakeFiles/AssetGenerics.dir/build.make AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o.provides.build
.PHONY : AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o.provides

AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o.provides.build: AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o

# Object files for target AssetGenerics
AssetGenerics_OBJECTS = \
"CMakeFiles/AssetGenerics.dir/generics.cpp.o"

# External object files for target AssetGenerics
AssetGenerics_EXTERNAL_OBJECTS =

lib/libAssetGenerics.so: AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o
lib/libAssetGenerics.so: AssetGenerics/CMakeFiles/AssetGenerics.dir/build.make
lib/libAssetGenerics.so: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Core.so.5.4.1
lib/libAssetGenerics.so: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Gui.so.5.4.1
lib/libAssetGenerics.so: lib/libUtility.so
lib/libAssetGenerics.so: lib/libAssetInterfaces.so
lib/libAssetGenerics.so: lib/libUtility.so
lib/libAssetGenerics.so: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Gui.so.5.4.1
lib/libAssetGenerics.so: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Core.so.5.4.1
lib/libAssetGenerics.so: AssetGenerics/CMakeFiles/AssetGenerics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../lib/libAssetGenerics.so"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/AssetGenerics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AssetGenerics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
AssetGenerics/CMakeFiles/AssetGenerics.dir/build: lib/libAssetGenerics.so
.PHONY : AssetGenerics/CMakeFiles/AssetGenerics.dir/build

AssetGenerics/CMakeFiles/AssetGenerics.dir/requires: AssetGenerics/CMakeFiles/AssetGenerics.dir/generics.cpp.o.requires
.PHONY : AssetGenerics/CMakeFiles/AssetGenerics.dir/requires

AssetGenerics/CMakeFiles/AssetGenerics.dir/clean:
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/AssetGenerics && $(CMAKE_COMMAND) -P CMakeFiles/AssetGenerics.dir/cmake_clean.cmake
.PHONY : AssetGenerics/CMakeFiles/AssetGenerics.dir/clean

AssetGenerics/CMakeFiles/AssetGenerics.dir/depend:
	cd /home/antoine/Documents/MIF39/snz-server/C++-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antoine/Documents/MIF39/snz-server/C++ /home/antoine/Documents/MIF39/snz-server/C++/AssetGenerics /home/antoine/Documents/MIF39/snz-server/C++-build /home/antoine/Documents/MIF39/snz-server/C++-build/AssetGenerics /home/antoine/Documents/MIF39/snz-server/C++-build/AssetGenerics/CMakeFiles/AssetGenerics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : AssetGenerics/CMakeFiles/AssetGenerics.dir/depend

