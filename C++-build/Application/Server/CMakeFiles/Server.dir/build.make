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
include Application/Server/CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include Application/Server/CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include Application/Server/CMakeFiles/Server.dir/flags.make

Application/Server/CMakeFiles/Server.dir/decoder.cpp.o: Application/Server/CMakeFiles/Server.dir/flags.make
Application/Server/CMakeFiles/Server.dir/decoder.cpp.o: /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/decoder.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antoine/Documents/MIF39/snz-server/C++-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/CMakeFiles/Server.dir/decoder.cpp.o"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/decoder.cpp.o -c /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/decoder.cpp

Application/Server/CMakeFiles/Server.dir/decoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/decoder.cpp.i"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/decoder.cpp > CMakeFiles/Server.dir/decoder.cpp.i

Application/Server/CMakeFiles/Server.dir/decoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/decoder.cpp.s"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/decoder.cpp -o CMakeFiles/Server.dir/decoder.cpp.s

Application/Server/CMakeFiles/Server.dir/decoder.cpp.o.requires:
.PHONY : Application/Server/CMakeFiles/Server.dir/decoder.cpp.o.requires

Application/Server/CMakeFiles/Server.dir/decoder.cpp.o.provides: Application/Server/CMakeFiles/Server.dir/decoder.cpp.o.requires
	$(MAKE) -f Application/Server/CMakeFiles/Server.dir/build.make Application/Server/CMakeFiles/Server.dir/decoder.cpp.o.provides.build
.PHONY : Application/Server/CMakeFiles/Server.dir/decoder.cpp.o.provides

Application/Server/CMakeFiles/Server.dir/decoder.cpp.o.provides.build: Application/Server/CMakeFiles/Server.dir/decoder.cpp.o

Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o: Application/Server/CMakeFiles/Server.dir/flags.make
Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o: /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/communicationserver.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antoine/Documents/MIF39/snz-server/C++-build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/communicationserver.cpp.o -c /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/communicationserver.cpp

Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/communicationserver.cpp.i"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/communicationserver.cpp > CMakeFiles/Server.dir/communicationserver.cpp.i

Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/communicationserver.cpp.s"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/communicationserver.cpp -o CMakeFiles/Server.dir/communicationserver.cpp.s

Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o.requires:
.PHONY : Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o.requires

Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o.provides: Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o.requires
	$(MAKE) -f Application/Server/CMakeFiles/Server.dir/build.make Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o.provides.build
.PHONY : Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o.provides

Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o.provides.build: Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o

Application/Server/CMakeFiles/Server.dir/server.cpp.o: Application/Server/CMakeFiles/Server.dir/flags.make
Application/Server/CMakeFiles/Server.dir/server.cpp.o: /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antoine/Documents/MIF39/snz-server/C++-build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/CMakeFiles/Server.dir/server.cpp.o"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/server.cpp.o -c /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/server.cpp

Application/Server/CMakeFiles/Server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/server.cpp.i"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/server.cpp > CMakeFiles/Server.dir/server.cpp.i

Application/Server/CMakeFiles/Server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/server.cpp.s"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/server.cpp -o CMakeFiles/Server.dir/server.cpp.s

Application/Server/CMakeFiles/Server.dir/server.cpp.o.requires:
.PHONY : Application/Server/CMakeFiles/Server.dir/server.cpp.o.requires

Application/Server/CMakeFiles/Server.dir/server.cpp.o.provides: Application/Server/CMakeFiles/Server.dir/server.cpp.o.requires
	$(MAKE) -f Application/Server/CMakeFiles/Server.dir/build.make Application/Server/CMakeFiles/Server.dir/server.cpp.o.provides.build
.PHONY : Application/Server/CMakeFiles/Server.dir/server.cpp.o.provides

Application/Server/CMakeFiles/Server.dir/server.cpp.o.provides.build: Application/Server/CMakeFiles/Server.dir/server.cpp.o

Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o: Application/Server/CMakeFiles/Server.dir/flags.make
Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o: /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/messagehandlerexample.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antoine/Documents/MIF39/snz-server/C++-build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/messagehandlerexample.cpp.o -c /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/messagehandlerexample.cpp

Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/messagehandlerexample.cpp.i"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/messagehandlerexample.cpp > CMakeFiles/Server.dir/messagehandlerexample.cpp.i

Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/messagehandlerexample.cpp.s"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/messagehandlerexample.cpp -o CMakeFiles/Server.dir/messagehandlerexample.cpp.s

Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o.requires:
.PHONY : Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o.requires

Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o.provides: Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o.requires
	$(MAKE) -f Application/Server/CMakeFiles/Server.dir/build.make Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o.provides.build
.PHONY : Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o.provides

Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o.provides.build: Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o

Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o: Application/Server/CMakeFiles/Server.dir/flags.make
Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o: /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/protocolemanager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antoine/Documents/MIF39/snz-server/C++-build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/Message/protocolemanager.cpp.o -c /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/protocolemanager.cpp

Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Message/protocolemanager.cpp.i"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/protocolemanager.cpp > CMakeFiles/Server.dir/Message/protocolemanager.cpp.i

Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Message/protocolemanager.cpp.s"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/protocolemanager.cpp -o CMakeFiles/Server.dir/Message/protocolemanager.cpp.s

Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o.requires:
.PHONY : Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o.requires

Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o.provides: Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o.requires
	$(MAKE) -f Application/Server/CMakeFiles/Server.dir/build.make Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o.provides.build
.PHONY : Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o.provides

Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o.provides.build: Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o

Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o: Application/Server/CMakeFiles/Server.dir/flags.make
Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o: /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/message.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antoine/Documents/MIF39/snz-server/C++-build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/Message/message.cpp.o -c /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/message.cpp

Application/Server/CMakeFiles/Server.dir/Message/message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Message/message.cpp.i"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/message.cpp > CMakeFiles/Server.dir/Message/message.cpp.i

Application/Server/CMakeFiles/Server.dir/Message/message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Message/message.cpp.s"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/message.cpp -o CMakeFiles/Server.dir/Message/message.cpp.s

Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o.requires:
.PHONY : Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o.requires

Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o.provides: Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o.requires
	$(MAKE) -f Application/Server/CMakeFiles/Server.dir/build.make Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o.provides.build
.PHONY : Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o.provides

Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o.provides.build: Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o

Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o: Application/Server/CMakeFiles/Server.dir/flags.make
Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o: /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/messagedispatcher.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/antoine/Documents/MIF39/snz-server/C++-build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o -c /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/messagedispatcher.cpp

Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Message/messagedispatcher.cpp.i"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/messagedispatcher.cpp > CMakeFiles/Server.dir/Message/messagedispatcher.cpp.i

Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Message/messagedispatcher.cpp.s"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/antoine/Documents/MIF39/snz-server/C++/Application/Server/Message/messagedispatcher.cpp -o CMakeFiles/Server.dir/Message/messagedispatcher.cpp.s

Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o.requires:
.PHONY : Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o.requires

Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o.provides: Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o.requires
	$(MAKE) -f Application/Server/CMakeFiles/Server.dir/build.make Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o.provides.build
.PHONY : Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o.provides

Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o.provides.build: Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/decoder.cpp.o" \
"CMakeFiles/Server.dir/communicationserver.cpp.o" \
"CMakeFiles/Server.dir/server.cpp.o" \
"CMakeFiles/Server.dir/messagehandlerexample.cpp.o" \
"CMakeFiles/Server.dir/Message/protocolemanager.cpp.o" \
"CMakeFiles/Server.dir/Message/message.cpp.o" \
"CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

lib/libServer.so: Application/Server/CMakeFiles/Server.dir/decoder.cpp.o
lib/libServer.so: Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o
lib/libServer.so: Application/Server/CMakeFiles/Server.dir/server.cpp.o
lib/libServer.so: Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o
lib/libServer.so: Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o
lib/libServer.so: Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o
lib/libServer.so: Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o
lib/libServer.so: Application/Server/CMakeFiles/Server.dir/build.make
lib/libServer.so: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Core.so.5.4.1
lib/libServer.so: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Gui.so.5.4.1
lib/libServer.so: lib/libUtility.so
lib/libServer.so: lib/libNetworking.so
lib/libServer.so: lib/libTcpNetworking.so
lib/libServer.so: lib/libAssetInterfaces.so
lib/libServer.so: lib/libAssetGenerics.so
lib/libServer.so: lib/libAssets.so
lib/libServer.so: lib/libWavefront.so
lib/libServer.so: lib/libQImageLoader.so
lib/libServer.so: lib/libMessage.so
lib/libServer.so: lib/libNetworking.so
lib/libServer.so: lib/libAssets.so
lib/libServer.so: lib/libAssetGenerics.so
lib/libServer.so: lib/libAssetInterfaces.so
lib/libServer.so: lib/libUtility.so
lib/libServer.so: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Gui.so.5.4.1
lib/libServer.so: /home/antoine/Qt/5.4/gcc_64/lib/libQt5Core.so.5.4.1
lib/libServer.so: Application/Server/CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/libServer.so"
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Application/Server/CMakeFiles/Server.dir/build: lib/libServer.so
.PHONY : Application/Server/CMakeFiles/Server.dir/build

Application/Server/CMakeFiles/Server.dir/requires: Application/Server/CMakeFiles/Server.dir/decoder.cpp.o.requires
Application/Server/CMakeFiles/Server.dir/requires: Application/Server/CMakeFiles/Server.dir/communicationserver.cpp.o.requires
Application/Server/CMakeFiles/Server.dir/requires: Application/Server/CMakeFiles/Server.dir/server.cpp.o.requires
Application/Server/CMakeFiles/Server.dir/requires: Application/Server/CMakeFiles/Server.dir/messagehandlerexample.cpp.o.requires
Application/Server/CMakeFiles/Server.dir/requires: Application/Server/CMakeFiles/Server.dir/Message/protocolemanager.cpp.o.requires
Application/Server/CMakeFiles/Server.dir/requires: Application/Server/CMakeFiles/Server.dir/Message/message.cpp.o.requires
Application/Server/CMakeFiles/Server.dir/requires: Application/Server/CMakeFiles/Server.dir/Message/messagedispatcher.cpp.o.requires
.PHONY : Application/Server/CMakeFiles/Server.dir/requires

Application/Server/CMakeFiles/Server.dir/clean:
	cd /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server && $(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : Application/Server/CMakeFiles/Server.dir/clean

Application/Server/CMakeFiles/Server.dir/depend:
	cd /home/antoine/Documents/MIF39/snz-server/C++-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antoine/Documents/MIF39/snz-server/C++ /home/antoine/Documents/MIF39/snz-server/C++/Application/Server /home/antoine/Documents/MIF39/snz-server/C++-build /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server /home/antoine/Documents/MIF39/snz-server/C++-build/Application/Server/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Application/Server/CMakeFiles/Server.dir/depend

