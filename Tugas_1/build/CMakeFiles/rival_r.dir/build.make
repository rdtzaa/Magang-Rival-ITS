# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/build

# Include any dependencies generated for this target.
include CMakeFiles/rival_r.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rival_r.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rival_r.dir/flags.make

CMakeFiles/rival_r.dir/src/game.cpp.o: CMakeFiles/rival_r.dir/flags.make
CMakeFiles/rival_r.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rival_r.dir/src/game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rival_r.dir/src/game.cpp.o -c /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/src/game.cpp

CMakeFiles/rival_r.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rival_r.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/src/game.cpp > CMakeFiles/rival_r.dir/src/game.cpp.i

CMakeFiles/rival_r.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rival_r.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/src/game.cpp -o CMakeFiles/rival_r.dir/src/game.cpp.s

CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.o: CMakeFiles/rival_r.dir/flags.make
CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.o: ../src/tangkap_permen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.o -c /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/src/tangkap_permen.cpp

CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/src/tangkap_permen.cpp > CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.i

CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/src/tangkap_permen.cpp -o CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.s

# Object files for target rival_r
rival_r_OBJECTS = \
"CMakeFiles/rival_r.dir/src/game.cpp.o" \
"CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.o"

# External object files for target rival_r
rival_r_EXTERNAL_OBJECTS =

rival_r: CMakeFiles/rival_r.dir/src/game.cpp.o
rival_r: CMakeFiles/rival_r.dir/src/tangkap_permen.cpp.o
rival_r: CMakeFiles/rival_r.dir/build.make
rival_r: /usr/local/lib/libopencv_gapi.so.4.10.0
rival_r: /usr/local/lib/libopencv_highgui.so.4.10.0
rival_r: /usr/local/lib/libopencv_ml.so.4.10.0
rival_r: /usr/local/lib/libopencv_objdetect.so.4.10.0
rival_r: /usr/local/lib/libopencv_photo.so.4.10.0
rival_r: /usr/local/lib/libopencv_stitching.so.4.10.0
rival_r: /usr/local/lib/libopencv_video.so.4.10.0
rival_r: /usr/local/lib/libopencv_videoio.so.4.10.0
rival_r: /usr/local/lib/libopencv_imgcodecs.so.4.10.0
rival_r: /usr/local/lib/libopencv_dnn.so.4.10.0
rival_r: /usr/local/lib/libopencv_calib3d.so.4.10.0
rival_r: /usr/local/lib/libopencv_features2d.so.4.10.0
rival_r: /usr/local/lib/libopencv_flann.so.4.10.0
rival_r: /usr/local/lib/libopencv_imgproc.so.4.10.0
rival_r: /usr/local/lib/libopencv_core.so.4.10.0
rival_r: CMakeFiles/rival_r.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable rival_r"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rival_r.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rival_r.dir/build: rival_r

.PHONY : CMakeFiles/rival_r.dir/build

CMakeFiles/rival_r.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rival_r.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rival_r.dir/clean

CMakeFiles/rival_r.dir/depend:
	cd /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1 /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1 /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/build /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/build /home/radityazhaa/Documents/Magang-Rival-ITS/Tugas_1/build/CMakeFiles/rival_r.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rival_r.dir/depend

