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
CMAKE_SOURCE_DIR = /root/HandwritingSVM/file_io

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/HandwritingSVM/file_io

# Include any dependencies generated for this target.
include CMakeFiles/centroid.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/centroid.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/centroid.dir/flags.make

CMakeFiles/centroid.dir/centroid.cc.o: CMakeFiles/centroid.dir/flags.make
CMakeFiles/centroid.dir/centroid.cc.o: centroid.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/HandwritingSVM/file_io/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/centroid.dir/centroid.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/centroid.dir/centroid.cc.o -c /root/HandwritingSVM/file_io/centroid.cc

CMakeFiles/centroid.dir/centroid.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/centroid.dir/centroid.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/HandwritingSVM/file_io/centroid.cc > CMakeFiles/centroid.dir/centroid.cc.i

CMakeFiles/centroid.dir/centroid.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/centroid.dir/centroid.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/HandwritingSVM/file_io/centroid.cc -o CMakeFiles/centroid.dir/centroid.cc.s

CMakeFiles/centroid.dir/centroid.cc.o.requires:
.PHONY : CMakeFiles/centroid.dir/centroid.cc.o.requires

CMakeFiles/centroid.dir/centroid.cc.o.provides: CMakeFiles/centroid.dir/centroid.cc.o.requires
	$(MAKE) -f CMakeFiles/centroid.dir/build.make CMakeFiles/centroid.dir/centroid.cc.o.provides.build
.PHONY : CMakeFiles/centroid.dir/centroid.cc.o.provides

CMakeFiles/centroid.dir/centroid.cc.o.provides.build: CMakeFiles/centroid.dir/centroid.cc.o

# Object files for target centroid
centroid_OBJECTS = \
"CMakeFiles/centroid.dir/centroid.cc.o"

# External object files for target centroid
centroid_EXTERNAL_OBJECTS =

centroid: CMakeFiles/centroid.dir/centroid.cc.o
centroid: CMakeFiles/centroid.dir/build.make
centroid: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
centroid: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
centroid: CMakeFiles/centroid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable centroid"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/centroid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/centroid.dir/build: centroid
.PHONY : CMakeFiles/centroid.dir/build

CMakeFiles/centroid.dir/requires: CMakeFiles/centroid.dir/centroid.cc.o.requires
.PHONY : CMakeFiles/centroid.dir/requires

CMakeFiles/centroid.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/centroid.dir/cmake_clean.cmake
.PHONY : CMakeFiles/centroid.dir/clean

CMakeFiles/centroid.dir/depend:
	cd /root/HandwritingSVM/file_io && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/HandwritingSVM/file_io /root/HandwritingSVM/file_io /root/HandwritingSVM/file_io /root/HandwritingSVM/file_io /root/HandwritingSVM/file_io/CMakeFiles/centroid.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/centroid.dir/depend

