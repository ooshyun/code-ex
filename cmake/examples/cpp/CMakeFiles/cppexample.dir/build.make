# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/seunghyunoh/workplace/examplace/practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/seunghyunoh/workplace/examplace/practice/cmake

# Include any dependencies generated for this target.
include examples/cpp/CMakeFiles/cppexample.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/cpp/CMakeFiles/cppexample.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/cpp/CMakeFiles/cppexample.dir/progress.make

# Include the compile flags for this target's objects.
include examples/cpp/CMakeFiles/cppexample.dir/flags.make

examples/cpp/CMakeFiles/cppexample.dir/Src/main.cc.o: examples/cpp/CMakeFiles/cppexample.dir/flags.make
examples/cpp/CMakeFiles/cppexample.dir/Src/main.cc.o: ../examples/cpp/Src/main.cc
examples/cpp/CMakeFiles/cppexample.dir/Src/main.cc.o: examples/cpp/CMakeFiles/cppexample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seunghyunoh/workplace/examplace/practice/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/cpp/CMakeFiles/cppexample.dir/Src/main.cc.o"
	cd /Users/seunghyunoh/workplace/examplace/practice/cmake/examples/cpp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/cpp/CMakeFiles/cppexample.dir/Src/main.cc.o -MF CMakeFiles/cppexample.dir/Src/main.cc.o.d -o CMakeFiles/cppexample.dir/Src/main.cc.o -c /Users/seunghyunoh/workplace/examplace/practice/examples/cpp/Src/main.cc

examples/cpp/CMakeFiles/cppexample.dir/Src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppexample.dir/Src/main.cc.i"
	cd /Users/seunghyunoh/workplace/examplace/practice/cmake/examples/cpp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seunghyunoh/workplace/examplace/practice/examples/cpp/Src/main.cc > CMakeFiles/cppexample.dir/Src/main.cc.i

examples/cpp/CMakeFiles/cppexample.dir/Src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppexample.dir/Src/main.cc.s"
	cd /Users/seunghyunoh/workplace/examplace/practice/cmake/examples/cpp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seunghyunoh/workplace/examplace/practice/examples/cpp/Src/main.cc -o CMakeFiles/cppexample.dir/Src/main.cc.s

# Object files for target cppexample
cppexample_OBJECTS = \
"CMakeFiles/cppexample.dir/Src/main.cc.o"

# External object files for target cppexample
cppexample_EXTERNAL_OBJECTS =

bin/cppexample: examples/cpp/CMakeFiles/cppexample.dir/Src/main.cc.o
bin/cppexample: examples/cpp/CMakeFiles/cppexample.dir/build.make
bin/cppexample: examples/cpp/libccex.a
bin/cppexample: /opt/homebrew/Cellar/boost/1.82.0_1/lib/libboost_filesystem.a
bin/cppexample: /opt/homebrew/Cellar/boost/1.82.0_1/lib/libboost_system-mt.a
bin/cppexample: /opt/homebrew/Cellar/boost/1.82.0_1/lib/libboost_thread-mt.a
bin/cppexample: /opt/homebrew/Cellar/boost/1.82.0_1/lib/libboost_chrono.a
bin/cppexample: /opt/homebrew/Cellar/boost/1.82.0_1/lib/libboost_atomic-mt.a
bin/cppexample: /opt/homebrew/Cellar/curl/8.3.0/lib/libcurl.a
bin/cppexample: /opt/homebrew/Cellar/spdlog/1.12.0/lib/libspdlog.1.12.0.dylib
bin/cppexample: /opt/homebrew/Cellar/openssl@1.1/1.1.1v/lib/libcrypto.a
bin/cppexample: /opt/homebrew/Cellar/openssl@1.1/1.1.1v/lib/libssl.a
bin/cppexample: /opt/homebrew/Cellar/fmt/10.1.1/lib/libfmt.a
bin/cppexample: examples/cpp/CMakeFiles/cppexample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/seunghyunoh/workplace/examplace/practice/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/cppexample"
	cd /Users/seunghyunoh/workplace/examplace/practice/cmake/examples/cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppexample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/cpp/CMakeFiles/cppexample.dir/build: bin/cppexample
.PHONY : examples/cpp/CMakeFiles/cppexample.dir/build

examples/cpp/CMakeFiles/cppexample.dir/clean:
	cd /Users/seunghyunoh/workplace/examplace/practice/cmake/examples/cpp && $(CMAKE_COMMAND) -P CMakeFiles/cppexample.dir/cmake_clean.cmake
.PHONY : examples/cpp/CMakeFiles/cppexample.dir/clean

examples/cpp/CMakeFiles/cppexample.dir/depend:
	cd /Users/seunghyunoh/workplace/examplace/practice/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/seunghyunoh/workplace/examplace/practice /Users/seunghyunoh/workplace/examplace/practice/examples/cpp /Users/seunghyunoh/workplace/examplace/practice/cmake /Users/seunghyunoh/workplace/examplace/practice/cmake/examples/cpp /Users/seunghyunoh/workplace/examplace/practice/cmake/examples/cpp/CMakeFiles/cppexample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/cpp/CMakeFiles/cppexample.dir/depend
