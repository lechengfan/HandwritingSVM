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
CMAKE_SOURCE_DIR = /root/HandwritingSVM/CLI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/HandwritingSVM/CLI

# Include any dependencies generated for this target.
include CMakeFiles/svm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/svm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/svm.dir/flags.make

CMakeFiles/svm.dir/main.cc.o: CMakeFiles/svm.dir/flags.make
CMakeFiles/svm.dir/main.cc.o: main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/HandwritingSVM/CLI/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/svm.dir/main.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/svm.dir/main.cc.o -c /root/HandwritingSVM/CLI/main.cc

CMakeFiles/svm.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/svm.dir/main.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/HandwritingSVM/CLI/main.cc > CMakeFiles/svm.dir/main.cc.i

CMakeFiles/svm.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/svm.dir/main.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/HandwritingSVM/CLI/main.cc -o CMakeFiles/svm.dir/main.cc.s

CMakeFiles/svm.dir/main.cc.o.requires:
.PHONY : CMakeFiles/svm.dir/main.cc.o.requires

CMakeFiles/svm.dir/main.cc.o.provides: CMakeFiles/svm.dir/main.cc.o.requires
	$(MAKE) -f CMakeFiles/svm.dir/build.make CMakeFiles/svm.dir/main.cc.o.provides.build
.PHONY : CMakeFiles/svm.dir/main.cc.o.provides

CMakeFiles/svm.dir/main.cc.o.provides.build: CMakeFiles/svm.dir/main.cc.o

# Object files for target svm
svm_OBJECTS = \
"CMakeFiles/svm.dir/main.cc.o"

# External object files for target svm
svm_EXTERNAL_OBJECTS =

svm: CMakeFiles/svm.dir/main.cc.o
svm: CMakeFiles/svm.dir/build.make
svm: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
svm: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
svm: CMakeFiles/svm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable svm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/svm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/svm.dir/build: svm
.PHONY : CMakeFiles/svm.dir/build

CMakeFiles/svm.dir/requires: CMakeFiles/svm.dir/main.cc.o.requires
.PHONY : CMakeFiles/svm.dir/requires

CMakeFiles/svm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/svm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/svm.dir/clean

CMakeFiles/svm.dir/depend:
	cd /root/HandwritingSVM/CLI && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/HandwritingSVM/CLI /root/HandwritingSVM/CLI /root/HandwritingSVM/CLI /root/HandwritingSVM/CLI /root/HandwritingSVM/CLI/CMakeFiles/svm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/svm.dir/depend

