# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/build

# Include any dependencies generated for this target.
include CMakeFiles/ShiftCipher.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ShiftCipher.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ShiftCipher.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ShiftCipher.dir/flags.make

CMakeFiles/ShiftCipher.dir/main.cpp.o: CMakeFiles/ShiftCipher.dir/flags.make
CMakeFiles/ShiftCipher.dir/main.cpp.o: /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/main.cpp
CMakeFiles/ShiftCipher.dir/main.cpp.o: CMakeFiles/ShiftCipher.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ShiftCipher.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ShiftCipher.dir/main.cpp.o -MF CMakeFiles/ShiftCipher.dir/main.cpp.o.d -o CMakeFiles/ShiftCipher.dir/main.cpp.o -c /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/main.cpp

CMakeFiles/ShiftCipher.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ShiftCipher.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/main.cpp > CMakeFiles/ShiftCipher.dir/main.cpp.i

CMakeFiles/ShiftCipher.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ShiftCipher.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/main.cpp -o CMakeFiles/ShiftCipher.dir/main.cpp.s

# Object files for target ShiftCipher
ShiftCipher_OBJECTS = \
"CMakeFiles/ShiftCipher.dir/main.cpp.o"

# External object files for target ShiftCipher
ShiftCipher_EXTERNAL_OBJECTS =

ShiftCipher: CMakeFiles/ShiftCipher.dir/main.cpp.o
ShiftCipher: CMakeFiles/ShiftCipher.dir/build.make
ShiftCipher: CMakeFiles/ShiftCipher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ShiftCipher"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ShiftCipher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ShiftCipher.dir/build: ShiftCipher
.PHONY : CMakeFiles/ShiftCipher.dir/build

CMakeFiles/ShiftCipher.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ShiftCipher.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ShiftCipher.dir/clean

CMakeFiles/ShiftCipher.dir/depend:
	cd /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2 /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2 /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/build /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/build /home/sin/repos/CPSC_370_Intro_To_Computer_Cryptology/Homework/Hands-on-2/build/CMakeFiles/ShiftCipher.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ShiftCipher.dir/depend

