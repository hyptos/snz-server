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

# Include any dependencies generated for this target.
include Application/Server/Message/CMakeFiles/Message.dir/depend.make

# Include the progress variables for this target.
include Application/Server/Message/CMakeFiles/Message.dir/progress.make

# Include the compile flags for this target's objects.
include Application/Server/Message/CMakeFiles/Message.dir/flags.make

Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o: Application/Server/Message/CMakeFiles/Message.dir/flags.make
Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o: ../Application/Server/Message/messagedispatcher.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Message.dir/messagedispatcher.cpp.o -c /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message/messagedispatcher.cpp

Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Message.dir/messagedispatcher.cpp.i"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message/messagedispatcher.cpp > CMakeFiles/Message.dir/messagedispatcher.cpp.i

Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Message.dir/messagedispatcher.cpp.s"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message/messagedispatcher.cpp -o CMakeFiles/Message.dir/messagedispatcher.cpp.s

Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o.requires:
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o.requires

Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o.provides: Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o.requires
	$(MAKE) -f Application/Server/Message/CMakeFiles/Message.dir/build.make Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o.provides.build
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o.provides

Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o.provides.build: Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o

Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o: Application/Server/Message/CMakeFiles/Message.dir/flags.make
Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o: ../Application/Server/Message/protocolemanager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Message.dir/protocolemanager.cpp.o -c /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message/protocolemanager.cpp

Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Message.dir/protocolemanager.cpp.i"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message/protocolemanager.cpp > CMakeFiles/Message.dir/protocolemanager.cpp.i

Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Message.dir/protocolemanager.cpp.s"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message/protocolemanager.cpp -o CMakeFiles/Message.dir/protocolemanager.cpp.s

Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o.requires:
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o.requires

Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o.provides: Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o.requires
	$(MAKE) -f Application/Server/Message/CMakeFiles/Message.dir/build.make Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o.provides.build
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o.provides

Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o.provides.build: Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o

Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o: Application/Server/Message/CMakeFiles/Message.dir/flags.make
Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o: ../Application/Server/Message/message.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Message.dir/message.cpp.o -c /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message/message.cpp

Application/Server/Message/CMakeFiles/Message.dir/message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Message.dir/message.cpp.i"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message/message.cpp > CMakeFiles/Message.dir/message.cpp.i

Application/Server/Message/CMakeFiles/Message.dir/message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Message.dir/message.cpp.s"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message/message.cpp -o CMakeFiles/Message.dir/message.cpp.s

Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o.requires:
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o.requires

Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o.provides: Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o.requires
	$(MAKE) -f Application/Server/Message/CMakeFiles/Message.dir/build.make Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o.provides.build
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o.provides

Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o.provides.build: Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o

Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o: Application/Server/Message/CMakeFiles/Message.dir/flags.make
Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o: Application/Server/Message/Message_automoc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Message.dir/Message_automoc.cpp.o -c /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message/Message_automoc.cpp

Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Message.dir/Message_automoc.cpp.i"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message/Message_automoc.cpp > CMakeFiles/Message.dir/Message_automoc.cpp.i

Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Message.dir/Message_automoc.cpp.s"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message/Message_automoc.cpp -o CMakeFiles/Message.dir/Message_automoc.cpp.s

Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o.requires:
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o.requires

Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o.provides: Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o.requires
	$(MAKE) -f Application/Server/Message/CMakeFiles/Message.dir/build.make Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o.provides.build
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o.provides

Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o.provides.build: Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o

# Object files for target Message
Message_OBJECTS = \
"CMakeFiles/Message.dir/messagedispatcher.cpp.o" \
"CMakeFiles/Message.dir/protocolemanager.cpp.o" \
"CMakeFiles/Message.dir/message.cpp.o" \
"CMakeFiles/Message.dir/Message_automoc.cpp.o"

# External object files for target Message
Message_EXTERNAL_OBJECTS =

lib/libMessage.so: Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o
lib/libMessage.so: Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o
lib/libMessage.so: Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o
lib/libMessage.so: Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o
lib/libMessage.so: Application/Server/Message/CMakeFiles/Message.dir/build.make
lib/libMessage.so: /home/avzgui/Qt/5.4/gcc_64/lib/libQt5Core.so.5.4.1
lib/libMessage.so: /home/avzgui/Qt/5.4/gcc_64/lib/libQt5Gui.so.5.4.1
lib/libMessage.so: /home/avzgui/Qt/5.4/gcc_64/lib/libQt5Widgets.so.5.4.1
lib/libMessage.so: lib/libUtility.so
lib/libMessage.so: /home/avzgui/Qt/5.4/gcc_64/lib/libQt5Gui.so.5.4.1
lib/libMessage.so: /home/avzgui/Qt/5.4/gcc_64/lib/libQt5Core.so.5.4.1
lib/libMessage.so: Application/Server/Message/CMakeFiles/Message.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../../lib/libMessage.so"
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Message.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Application/Server/Message/CMakeFiles/Message.dir/build: lib/libMessage.so
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/build

Application/Server/Message/CMakeFiles/Message.dir/requires: Application/Server/Message/CMakeFiles/Message.dir/messagedispatcher.cpp.o.requires
Application/Server/Message/CMakeFiles/Message.dir/requires: Application/Server/Message/CMakeFiles/Message.dir/protocolemanager.cpp.o.requires
Application/Server/Message/CMakeFiles/Message.dir/requires: Application/Server/Message/CMakeFiles/Message.dir/message.cpp.o.requires
Application/Server/Message/CMakeFiles/Message.dir/requires: Application/Server/Message/CMakeFiles/Message.dir/Message_automoc.cpp.o.requires
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/requires

Application/Server/Message/CMakeFiles/Message.dir/clean:
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message && $(CMAKE_COMMAND) -P CMakeFiles/Message.dir/cmake_clean.cmake
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/clean

Application/Server/Message/CMakeFiles/Message.dir/depend:
	cd /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++ /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/Application/Server/Message /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message /home/avzgui/Documents/M1/S2/MIF39/snz-server/C++/build/Application/Server/Message/CMakeFiles/Message.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Application/Server/Message/CMakeFiles/Message.dir/depend

