# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/saksham/Projects/Physics-Engine-2D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saksham/Projects/Physics-Engine-2D/build

# Include any dependencies generated for this target.
include CMakeFiles/Physics_Engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Physics_Engine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Physics_Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Physics_Engine.dir/flags.make

CMakeFiles/Physics_Engine.dir/main.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/main.cpp.o: /home/saksham/Projects/Physics-Engine-2D/main.cpp
CMakeFiles/Physics_Engine.dir/main.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Physics_Engine.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/main.cpp.o -MF CMakeFiles/Physics_Engine.dir/main.cpp.o.d -o CMakeFiles/Physics_Engine.dir/main.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/main.cpp

CMakeFiles/Physics_Engine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/main.cpp > CMakeFiles/Physics_Engine.dir/main.cpp.i

CMakeFiles/Physics_Engine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/main.cpp -o CMakeFiles/Physics_Engine.dir/main.cpp.s

CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.o: /home/saksham/Projects/Physics-Engine-2D/sourceCode/Math2D.cpp
CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.o -MF CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.o.d -o CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/sourceCode/Math2D.cpp

CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/sourceCode/Math2D.cpp > CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.i

CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/sourceCode/Math2D.cpp -o CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.s

CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.o: /home/saksham/Projects/Physics-Engine-2D/sourceCode/objects.cpp
CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.o -MF CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.o.d -o CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/sourceCode/objects.cpp

CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/sourceCode/objects.cpp > CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.i

CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/sourceCode/objects.cpp -o CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.s

CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.o: /home/saksham/Projects/Physics-Engine-2D/sourceCode/Rigidbody.cpp
CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.o -MF CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.o.d -o CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/sourceCode/Rigidbody.cpp

CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/sourceCode/Rigidbody.cpp > CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.i

CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/sourceCode/Rigidbody.cpp -o CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.s

CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.o: /home/saksham/Projects/Physics-Engine-2D/sourceCode/SceneManager.cpp
CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.o -MF CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.o.d -o CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/sourceCode/SceneManager.cpp

CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/sourceCode/SceneManager.cpp > CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.i

CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/sourceCode/SceneManager.cpp -o CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.s

CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.o: /home/saksham/Projects/Physics-Engine-2D/sourceCode/utils.cpp
CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.o -MF CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.o.d -o CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/sourceCode/utils.cpp

CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/sourceCode/utils.cpp > CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.i

CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/sourceCode/utils.cpp -o CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.s

CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.o: /home/saksham/Projects/Physics-Engine-2D/sourceCode/Renderer.cpp
CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.o -MF CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.o.d -o CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/sourceCode/Renderer.cpp

CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/sourceCode/Renderer.cpp > CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.i

CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/sourceCode/Renderer.cpp -o CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.s

CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.o: /home/saksham/Projects/Physics-Engine-2D/sourceCode/Collision.cpp
CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.o -MF CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.o.d -o CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/sourceCode/Collision.cpp

CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/sourceCode/Collision.cpp > CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.i

CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/sourceCode/Collision.cpp -o CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.s

CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.o: /home/saksham/Projects/Physics-Engine-2D/sourceCode/engine.cpp
CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.o -MF CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.o.d -o CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/sourceCode/engine.cpp

CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/sourceCode/engine.cpp > CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.i

CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/sourceCode/engine.cpp -o CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.s

CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.o: CMakeFiles/Physics_Engine.dir/flags.make
CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.o: /home/saksham/Projects/Physics-Engine-2D/sourceCode/Application.cpp
CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.o: CMakeFiles/Physics_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.o -MF CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.o.d -o CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.o -c /home/saksham/Projects/Physics-Engine-2D/sourceCode/Application.cpp

CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saksham/Projects/Physics-Engine-2D/sourceCode/Application.cpp > CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.i

CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saksham/Projects/Physics-Engine-2D/sourceCode/Application.cpp -o CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.s

# Object files for target Physics_Engine
Physics_Engine_OBJECTS = \
"CMakeFiles/Physics_Engine.dir/main.cpp.o" \
"CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.o" \
"CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.o" \
"CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.o" \
"CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.o" \
"CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.o" \
"CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.o" \
"CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.o" \
"CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.o" \
"CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.o"

# External object files for target Physics_Engine
Physics_Engine_EXTERNAL_OBJECTS =

Physics_Engine: CMakeFiles/Physics_Engine.dir/main.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/sourceCode/Math2D.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/sourceCode/objects.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/sourceCode/Rigidbody.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/sourceCode/SceneManager.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/sourceCode/utils.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/sourceCode/Renderer.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/sourceCode/Collision.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/sourceCode/engine.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/sourceCode/Application.cpp.o
Physics_Engine: CMakeFiles/Physics_Engine.dir/build.make
Physics_Engine: /usr/lib/x86_64-linux-gnu/libSDL2.so
Physics_Engine: CMakeFiles/Physics_Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Physics_Engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Physics_Engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Physics_Engine.dir/build: Physics_Engine
.PHONY : CMakeFiles/Physics_Engine.dir/build

CMakeFiles/Physics_Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Physics_Engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Physics_Engine.dir/clean

CMakeFiles/Physics_Engine.dir/depend:
	cd /home/saksham/Projects/Physics-Engine-2D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saksham/Projects/Physics-Engine-2D /home/saksham/Projects/Physics-Engine-2D /home/saksham/Projects/Physics-Engine-2D/build /home/saksham/Projects/Physics-Engine-2D/build /home/saksham/Projects/Physics-Engine-2D/build/CMakeFiles/Physics_Engine.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Physics_Engine.dir/depend

