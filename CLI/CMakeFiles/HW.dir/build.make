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
CMAKE_SOURCE_DIR = /root/Max/HandwritingSVM/CLI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Max/HandwritingSVM/CLI

# Include any dependencies generated for this target.
include CMakeFiles/HW.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW.dir/flags.make

CMakeFiles/HW.dir/newCLI.cc.o: CMakeFiles/HW.dir/flags.make
CMakeFiles/HW.dir/newCLI.cc.o: newCLI.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Max/HandwritingSVM/CLI/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/HW.dir/newCLI.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/HW.dir/newCLI.cc.o -c /root/Max/HandwritingSVM/CLI/newCLI.cc

CMakeFiles/HW.dir/newCLI.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW.dir/newCLI.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Max/HandwritingSVM/CLI/newCLI.cc > CMakeFiles/HW.dir/newCLI.cc.i

CMakeFiles/HW.dir/newCLI.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW.dir/newCLI.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Max/HandwritingSVM/CLI/newCLI.cc -o CMakeFiles/HW.dir/newCLI.cc.s

CMakeFiles/HW.dir/newCLI.cc.o.requires:
.PHONY : CMakeFiles/HW.dir/newCLI.cc.o.requires

CMakeFiles/HW.dir/newCLI.cc.o.provides: CMakeFiles/HW.dir/newCLI.cc.o.requires
	$(MAKE) -f CMakeFiles/HW.dir/build.make CMakeFiles/HW.dir/newCLI.cc.o.provides.build
.PHONY : CMakeFiles/HW.dir/newCLI.cc.o.provides

CMakeFiles/HW.dir/newCLI.cc.o.provides.build: CMakeFiles/HW.dir/newCLI.cc.o

CMakeFiles/HW.dir/mlp.cc.o: CMakeFiles/HW.dir/flags.make
CMakeFiles/HW.dir/mlp.cc.o: mlp.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Max/HandwritingSVM/CLI/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/HW.dir/mlp.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/HW.dir/mlp.cc.o -c /root/Max/HandwritingSVM/CLI/mlp.cc

CMakeFiles/HW.dir/mlp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW.dir/mlp.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Max/HandwritingSVM/CLI/mlp.cc > CMakeFiles/HW.dir/mlp.cc.i

CMakeFiles/HW.dir/mlp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW.dir/mlp.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Max/HandwritingSVM/CLI/mlp.cc -o CMakeFiles/HW.dir/mlp.cc.s

CMakeFiles/HW.dir/mlp.cc.o.requires:
.PHONY : CMakeFiles/HW.dir/mlp.cc.o.requires

CMakeFiles/HW.dir/mlp.cc.o.provides: CMakeFiles/HW.dir/mlp.cc.o.requires
	$(MAKE) -f CMakeFiles/HW.dir/build.make CMakeFiles/HW.dir/mlp.cc.o.provides.build
.PHONY : CMakeFiles/HW.dir/mlp.cc.o.provides

CMakeFiles/HW.dir/mlp.cc.o.provides.build: CMakeFiles/HW.dir/mlp.cc.o

CMakeFiles/HW.dir/data_store.cc.o: CMakeFiles/HW.dir/flags.make
CMakeFiles/HW.dir/data_store.cc.o: data_store.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Max/HandwritingSVM/CLI/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/HW.dir/data_store.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/HW.dir/data_store.cc.o -c /root/Max/HandwritingSVM/CLI/data_store.cc

CMakeFiles/HW.dir/data_store.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW.dir/data_store.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Max/HandwritingSVM/CLI/data_store.cc > CMakeFiles/HW.dir/data_store.cc.i

CMakeFiles/HW.dir/data_store.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW.dir/data_store.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Max/HandwritingSVM/CLI/data_store.cc -o CMakeFiles/HW.dir/data_store.cc.s

CMakeFiles/HW.dir/data_store.cc.o.requires:
.PHONY : CMakeFiles/HW.dir/data_store.cc.o.requires

CMakeFiles/HW.dir/data_store.cc.o.provides: CMakeFiles/HW.dir/data_store.cc.o.requires
	$(MAKE) -f CMakeFiles/HW.dir/build.make CMakeFiles/HW.dir/data_store.cc.o.provides.build
.PHONY : CMakeFiles/HW.dir/data_store.cc.o.provides

CMakeFiles/HW.dir/data_store.cc.o.provides.build: CMakeFiles/HW.dir/data_store.cc.o

CMakeFiles/HW.dir/svm.cc.o: CMakeFiles/HW.dir/flags.make
CMakeFiles/HW.dir/svm.cc.o: svm.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Max/HandwritingSVM/CLI/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/HW.dir/svm.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/HW.dir/svm.cc.o -c /root/Max/HandwritingSVM/CLI/svm.cc

CMakeFiles/HW.dir/svm.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW.dir/svm.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Max/HandwritingSVM/CLI/svm.cc > CMakeFiles/HW.dir/svm.cc.i

CMakeFiles/HW.dir/svm.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW.dir/svm.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Max/HandwritingSVM/CLI/svm.cc -o CMakeFiles/HW.dir/svm.cc.s

CMakeFiles/HW.dir/svm.cc.o.requires:
.PHONY : CMakeFiles/HW.dir/svm.cc.o.requires

CMakeFiles/HW.dir/svm.cc.o.provides: CMakeFiles/HW.dir/svm.cc.o.requires
	$(MAKE) -f CMakeFiles/HW.dir/build.make CMakeFiles/HW.dir/svm.cc.o.provides.build
.PHONY : CMakeFiles/HW.dir/svm.cc.o.provides

CMakeFiles/HW.dir/svm.cc.o.provides.build: CMakeFiles/HW.dir/svm.cc.o

CMakeFiles/HW.dir/rf.cc.o: CMakeFiles/HW.dir/flags.make
CMakeFiles/HW.dir/rf.cc.o: rf.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Max/HandwritingSVM/CLI/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/HW.dir/rf.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/HW.dir/rf.cc.o -c /root/Max/HandwritingSVM/CLI/rf.cc

CMakeFiles/HW.dir/rf.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW.dir/rf.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Max/HandwritingSVM/CLI/rf.cc > CMakeFiles/HW.dir/rf.cc.i

CMakeFiles/HW.dir/rf.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW.dir/rf.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Max/HandwritingSVM/CLI/rf.cc -o CMakeFiles/HW.dir/rf.cc.s

CMakeFiles/HW.dir/rf.cc.o.requires:
.PHONY : CMakeFiles/HW.dir/rf.cc.o.requires

CMakeFiles/HW.dir/rf.cc.o.provides: CMakeFiles/HW.dir/rf.cc.o.requires
	$(MAKE) -f CMakeFiles/HW.dir/build.make CMakeFiles/HW.dir/rf.cc.o.provides.build
.PHONY : CMakeFiles/HW.dir/rf.cc.o.provides

CMakeFiles/HW.dir/rf.cc.o.provides.build: CMakeFiles/HW.dir/rf.cc.o

CMakeFiles/HW.dir/knn.cc.o: CMakeFiles/HW.dir/flags.make
CMakeFiles/HW.dir/knn.cc.o: knn.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Max/HandwritingSVM/CLI/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/HW.dir/knn.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/HW.dir/knn.cc.o -c /root/Max/HandwritingSVM/CLI/knn.cc

CMakeFiles/HW.dir/knn.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW.dir/knn.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Max/HandwritingSVM/CLI/knn.cc > CMakeFiles/HW.dir/knn.cc.i

CMakeFiles/HW.dir/knn.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW.dir/knn.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Max/HandwritingSVM/CLI/knn.cc -o CMakeFiles/HW.dir/knn.cc.s

CMakeFiles/HW.dir/knn.cc.o.requires:
.PHONY : CMakeFiles/HW.dir/knn.cc.o.requires

CMakeFiles/HW.dir/knn.cc.o.provides: CMakeFiles/HW.dir/knn.cc.o.requires
	$(MAKE) -f CMakeFiles/HW.dir/build.make CMakeFiles/HW.dir/knn.cc.o.provides.build
.PHONY : CMakeFiles/HW.dir/knn.cc.o.provides

CMakeFiles/HW.dir/knn.cc.o.provides.build: CMakeFiles/HW.dir/knn.cc.o

# Object files for target HW
HW_OBJECTS = \
"CMakeFiles/HW.dir/newCLI.cc.o" \
"CMakeFiles/HW.dir/mlp.cc.o" \
"CMakeFiles/HW.dir/data_store.cc.o" \
"CMakeFiles/HW.dir/svm.cc.o" \
"CMakeFiles/HW.dir/rf.cc.o" \
"CMakeFiles/HW.dir/knn.cc.o"

# External object files for target HW
HW_EXTERNAL_OBJECTS =

HW: CMakeFiles/HW.dir/newCLI.cc.o
HW: CMakeFiles/HW.dir/mlp.cc.o
HW: CMakeFiles/HW.dir/data_store.cc.o
HW: CMakeFiles/HW.dir/svm.cc.o
HW: CMakeFiles/HW.dir/rf.cc.o
HW: CMakeFiles/HW.dir/knn.cc.o
HW: CMakeFiles/HW.dir/build.make
HW: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
HW: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
HW: CMakeFiles/HW.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable HW"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW.dir/build: HW
.PHONY : CMakeFiles/HW.dir/build

CMakeFiles/HW.dir/requires: CMakeFiles/HW.dir/newCLI.cc.o.requires
CMakeFiles/HW.dir/requires: CMakeFiles/HW.dir/mlp.cc.o.requires
CMakeFiles/HW.dir/requires: CMakeFiles/HW.dir/data_store.cc.o.requires
CMakeFiles/HW.dir/requires: CMakeFiles/HW.dir/svm.cc.o.requires
CMakeFiles/HW.dir/requires: CMakeFiles/HW.dir/rf.cc.o.requires
CMakeFiles/HW.dir/requires: CMakeFiles/HW.dir/knn.cc.o.requires
.PHONY : CMakeFiles/HW.dir/requires

CMakeFiles/HW.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW.dir/clean

CMakeFiles/HW.dir/depend:
	cd /root/Max/HandwritingSVM/CLI && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Max/HandwritingSVM/CLI /root/Max/HandwritingSVM/CLI /root/Max/HandwritingSVM/CLI /root/Max/HandwritingSVM/CLI /root/Max/HandwritingSVM/CLI/CMakeFiles/HW.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW.dir/depend

