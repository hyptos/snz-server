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
CMAKE_SOURCE_DIR = /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build

# Utility rule file for Server_automoc.

# Include the progress variables for this target.
include Application/Server/CMakeFiles/Server_automoc.dir/progress.make

Application/Server/CMakeFiles/Server_automoc:
	$(CMAKE_COMMAND) -E cmake_progress_report /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Automoc for target Server"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server && /usr/bin/cmake -E cmake_automoc /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/CMakeFiles/Server_automoc.dir/

Server_automoc: Application/Server/CMakeFiles/Server_automoc
Server_automoc: Application/Server/CMakeFiles/Server_automoc.dir/build.make
.PHONY : Server_automoc

# Rule to build all files generated by this target.
Application/Server/CMakeFiles/Server_automoc.dir/build: Server_automoc
.PHONY : Application/Server/CMakeFiles/Server_automoc.dir/build

Application/Server/CMakeFiles/Server_automoc.dir/clean:
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server && $(CMAKE_COMMAND) -P CMakeFiles/Server_automoc.dir/cmake_clean.cmake
.PHONY : Application/Server/CMakeFiles/Server_automoc.dir/clean

Application/Server/CMakeFiles/Server_automoc.dir/depend:
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++ /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/CMakeFiles/Server_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Application/Server/CMakeFiles/Server_automoc.dir/depend

