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
CMAKE_SOURCE_DIR = /home/ubuntu/linux_shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/linux_shell/build

# Include any dependencies generated for this target.
include CMakeFiles/linux_shell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linux_shell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linux_shell.dir/flags.make

CMakeFiles/linux_shell.dir/main.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/linux_shell.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/main.c.o   -c /home/ubuntu/linux_shell/main.c

CMakeFiles/linux_shell.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/main.c > CMakeFiles/linux_shell.dir/main.c.i

CMakeFiles/linux_shell.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/main.c -o CMakeFiles/linux_shell.dir/main.c.s

CMakeFiles/linux_shell.dir/src/queen.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/queen.c.o: ../src/queen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/linux_shell.dir/src/queen.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/queen.c.o   -c /home/ubuntu/linux_shell/src/queen.c

CMakeFiles/linux_shell.dir/src/queen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/queen.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/queen.c > CMakeFiles/linux_shell.dir/src/queen.c.i

CMakeFiles/linux_shell.dir/src/queen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/queen.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/queen.c -o CMakeFiles/linux_shell.dir/src/queen.c.s

CMakeFiles/linux_shell.dir/src/cat.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/cat.c.o: ../src/cat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/linux_shell.dir/src/cat.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/cat.c.o   -c /home/ubuntu/linux_shell/src/cat.c

CMakeFiles/linux_shell.dir/src/cat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/cat.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/cat.c > CMakeFiles/linux_shell.dir/src/cat.c.i

CMakeFiles/linux_shell.dir/src/cat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/cat.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/cat.c -o CMakeFiles/linux_shell.dir/src/cat.c.s

CMakeFiles/linux_shell.dir/src/cd.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/cd.c.o: ../src/cd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/linux_shell.dir/src/cd.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/cd.c.o   -c /home/ubuntu/linux_shell/src/cd.c

CMakeFiles/linux_shell.dir/src/cd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/cd.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/cd.c > CMakeFiles/linux_shell.dir/src/cd.c.i

CMakeFiles/linux_shell.dir/src/cd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/cd.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/cd.c -o CMakeFiles/linux_shell.dir/src/cd.c.s

CMakeFiles/linux_shell.dir/src/chmod.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/chmod.c.o: ../src/chmod.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/linux_shell.dir/src/chmod.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/chmod.c.o   -c /home/ubuntu/linux_shell/src/chmod.c

CMakeFiles/linux_shell.dir/src/chmod.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/chmod.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/chmod.c > CMakeFiles/linux_shell.dir/src/chmod.c.i

CMakeFiles/linux_shell.dir/src/chmod.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/chmod.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/chmod.c -o CMakeFiles/linux_shell.dir/src/chmod.c.s

CMakeFiles/linux_shell.dir/src/date.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/date.c.o: ../src/date.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/linux_shell.dir/src/date.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/date.c.o   -c /home/ubuntu/linux_shell/src/date.c

CMakeFiles/linux_shell.dir/src/date.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/date.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/date.c > CMakeFiles/linux_shell.dir/src/date.c.i

CMakeFiles/linux_shell.dir/src/date.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/date.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/date.c -o CMakeFiles/linux_shell.dir/src/date.c.s

CMakeFiles/linux_shell.dir/src/echo.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/echo.c.o: ../src/echo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/linux_shell.dir/src/echo.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/echo.c.o   -c /home/ubuntu/linux_shell/src/echo.c

CMakeFiles/linux_shell.dir/src/echo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/echo.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/echo.c > CMakeFiles/linux_shell.dir/src/echo.c.i

CMakeFiles/linux_shell.dir/src/echo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/echo.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/echo.c -o CMakeFiles/linux_shell.dir/src/echo.c.s

CMakeFiles/linux_shell.dir/src/exec.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/exec.c.o: ../src/exec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/linux_shell.dir/src/exec.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/exec.c.o   -c /home/ubuntu/linux_shell/src/exec.c

CMakeFiles/linux_shell.dir/src/exec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/exec.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/exec.c > CMakeFiles/linux_shell.dir/src/exec.c.i

CMakeFiles/linux_shell.dir/src/exec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/exec.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/exec.c -o CMakeFiles/linux_shell.dir/src/exec.c.s

CMakeFiles/linux_shell.dir/src/kill.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/kill.c.o: ../src/kill.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/linux_shell.dir/src/kill.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/kill.c.o   -c /home/ubuntu/linux_shell/src/kill.c

CMakeFiles/linux_shell.dir/src/kill.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/kill.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/kill.c > CMakeFiles/linux_shell.dir/src/kill.c.i

CMakeFiles/linux_shell.dir/src/kill.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/kill.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/kill.c -o CMakeFiles/linux_shell.dir/src/kill.c.s

CMakeFiles/linux_shell.dir/src/ls.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/ls.c.o: ../src/ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/linux_shell.dir/src/ls.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/ls.c.o   -c /home/ubuntu/linux_shell/src/ls.c

CMakeFiles/linux_shell.dir/src/ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/ls.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/ls.c > CMakeFiles/linux_shell.dir/src/ls.c.i

CMakeFiles/linux_shell.dir/src/ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/ls.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/ls.c -o CMakeFiles/linux_shell.dir/src/ls.c.s

CMakeFiles/linux_shell.dir/src/mkdir.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/mkdir.c.o: ../src/mkdir.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/linux_shell.dir/src/mkdir.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/mkdir.c.o   -c /home/ubuntu/linux_shell/src/mkdir.c

CMakeFiles/linux_shell.dir/src/mkdir.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/mkdir.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/mkdir.c > CMakeFiles/linux_shell.dir/src/mkdir.c.i

CMakeFiles/linux_shell.dir/src/mkdir.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/mkdir.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/mkdir.c -o CMakeFiles/linux_shell.dir/src/mkdir.c.s

CMakeFiles/linux_shell.dir/src/pwd.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/pwd.c.o: ../src/pwd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/linux_shell.dir/src/pwd.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/pwd.c.o   -c /home/ubuntu/linux_shell/src/pwd.c

CMakeFiles/linux_shell.dir/src/pwd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/pwd.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/pwd.c > CMakeFiles/linux_shell.dir/src/pwd.c.i

CMakeFiles/linux_shell.dir/src/pwd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/pwd.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/pwd.c -o CMakeFiles/linux_shell.dir/src/pwd.c.s

CMakeFiles/linux_shell.dir/src/rm.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/rm.c.o: ../src/rm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/linux_shell.dir/src/rm.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/rm.c.o   -c /home/ubuntu/linux_shell/src/rm.c

CMakeFiles/linux_shell.dir/src/rm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/rm.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/rm.c > CMakeFiles/linux_shell.dir/src/rm.c.i

CMakeFiles/linux_shell.dir/src/rm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/rm.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/rm.c -o CMakeFiles/linux_shell.dir/src/rm.c.s

CMakeFiles/linux_shell.dir/src/rmdir.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/rmdir.c.o: ../src/rmdir.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/linux_shell.dir/src/rmdir.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/rmdir.c.o   -c /home/ubuntu/linux_shell/src/rmdir.c

CMakeFiles/linux_shell.dir/src/rmdir.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/rmdir.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/rmdir.c > CMakeFiles/linux_shell.dir/src/rmdir.c.i

CMakeFiles/linux_shell.dir/src/rmdir.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/rmdir.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/rmdir.c -o CMakeFiles/linux_shell.dir/src/rmdir.c.s

CMakeFiles/linux_shell.dir/src/wc.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/wc.c.o: ../src/wc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/linux_shell.dir/src/wc.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/wc.c.o   -c /home/ubuntu/linux_shell/src/wc.c

CMakeFiles/linux_shell.dir/src/wc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/wc.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/wc.c > CMakeFiles/linux_shell.dir/src/wc.c.i

CMakeFiles/linux_shell.dir/src/wc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/wc.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/wc.c -o CMakeFiles/linux_shell.dir/src/wc.c.s

CMakeFiles/linux_shell.dir/src/who.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/who.c.o: ../src/who.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/linux_shell.dir/src/who.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/who.c.o   -c /home/ubuntu/linux_shell/src/who.c

CMakeFiles/linux_shell.dir/src/who.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/who.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/who.c > CMakeFiles/linux_shell.dir/src/who.c.i

CMakeFiles/linux_shell.dir/src/who.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/who.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/who.c -o CMakeFiles/linux_shell.dir/src/who.c.s

CMakeFiles/linux_shell.dir/src/whoami.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/whoami.c.o: ../src/whoami.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/linux_shell.dir/src/whoami.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/whoami.c.o   -c /home/ubuntu/linux_shell/src/whoami.c

CMakeFiles/linux_shell.dir/src/whoami.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/whoami.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/whoami.c > CMakeFiles/linux_shell.dir/src/whoami.c.i

CMakeFiles/linux_shell.dir/src/whoami.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/whoami.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/whoami.c -o CMakeFiles/linux_shell.dir/src/whoami.c.s

CMakeFiles/linux_shell.dir/src/error.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/error.c.o: ../src/error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/linux_shell.dir/src/error.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/error.c.o   -c /home/ubuntu/linux_shell/src/error.c

CMakeFiles/linux_shell.dir/src/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/error.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/error.c > CMakeFiles/linux_shell.dir/src/error.c.i

CMakeFiles/linux_shell.dir/src/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/error.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/error.c -o CMakeFiles/linux_shell.dir/src/error.c.s

CMakeFiles/linux_shell.dir/src/shell_function.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/shell_function.c.o: ../src/shell_function.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/linux_shell.dir/src/shell_function.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/shell_function.c.o   -c /home/ubuntu/linux_shell/src/shell_function.c

CMakeFiles/linux_shell.dir/src/shell_function.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/shell_function.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/shell_function.c > CMakeFiles/linux_shell.dir/src/shell_function.c.i

CMakeFiles/linux_shell.dir/src/shell_function.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/shell_function.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/shell_function.c -o CMakeFiles/linux_shell.dir/src/shell_function.c.s

CMakeFiles/linux_shell.dir/src/output.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/output.c.o: ../src/output.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object CMakeFiles/linux_shell.dir/src/output.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/output.c.o   -c /home/ubuntu/linux_shell/src/output.c

CMakeFiles/linux_shell.dir/src/output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/output.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/output.c > CMakeFiles/linux_shell.dir/src/output.c.i

CMakeFiles/linux_shell.dir/src/output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/output.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/output.c -o CMakeFiles/linux_shell.dir/src/output.c.s

CMakeFiles/linux_shell.dir/src/string_helper.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/string_helper.c.o: ../src/string_helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building C object CMakeFiles/linux_shell.dir/src/string_helper.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/string_helper.c.o   -c /home/ubuntu/linux_shell/src/string_helper.c

CMakeFiles/linux_shell.dir/src/string_helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/string_helper.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/string_helper.c > CMakeFiles/linux_shell.dir/src/string_helper.c.i

CMakeFiles/linux_shell.dir/src/string_helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/string_helper.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/string_helper.c -o CMakeFiles/linux_shell.dir/src/string_helper.c.s

CMakeFiles/linux_shell.dir/src/shell_pipe.c.o: CMakeFiles/linux_shell.dir/flags.make
CMakeFiles/linux_shell.dir/src/shell_pipe.c.o: ../src/shell_pipe.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building C object CMakeFiles/linux_shell.dir/src/shell_pipe.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linux_shell.dir/src/shell_pipe.c.o   -c /home/ubuntu/linux_shell/src/shell_pipe.c

CMakeFiles/linux_shell.dir/src/shell_pipe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linux_shell.dir/src/shell_pipe.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/linux_shell/src/shell_pipe.c > CMakeFiles/linux_shell.dir/src/shell_pipe.c.i

CMakeFiles/linux_shell.dir/src/shell_pipe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linux_shell.dir/src/shell_pipe.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/linux_shell/src/shell_pipe.c -o CMakeFiles/linux_shell.dir/src/shell_pipe.c.s

# Object files for target linux_shell
linux_shell_OBJECTS = \
"CMakeFiles/linux_shell.dir/main.c.o" \
"CMakeFiles/linux_shell.dir/src/queen.c.o" \
"CMakeFiles/linux_shell.dir/src/cat.c.o" \
"CMakeFiles/linux_shell.dir/src/cd.c.o" \
"CMakeFiles/linux_shell.dir/src/chmod.c.o" \
"CMakeFiles/linux_shell.dir/src/date.c.o" \
"CMakeFiles/linux_shell.dir/src/echo.c.o" \
"CMakeFiles/linux_shell.dir/src/exec.c.o" \
"CMakeFiles/linux_shell.dir/src/kill.c.o" \
"CMakeFiles/linux_shell.dir/src/ls.c.o" \
"CMakeFiles/linux_shell.dir/src/mkdir.c.o" \
"CMakeFiles/linux_shell.dir/src/pwd.c.o" \
"CMakeFiles/linux_shell.dir/src/rm.c.o" \
"CMakeFiles/linux_shell.dir/src/rmdir.c.o" \
"CMakeFiles/linux_shell.dir/src/wc.c.o" \
"CMakeFiles/linux_shell.dir/src/who.c.o" \
"CMakeFiles/linux_shell.dir/src/whoami.c.o" \
"CMakeFiles/linux_shell.dir/src/error.c.o" \
"CMakeFiles/linux_shell.dir/src/shell_function.c.o" \
"CMakeFiles/linux_shell.dir/src/output.c.o" \
"CMakeFiles/linux_shell.dir/src/string_helper.c.o" \
"CMakeFiles/linux_shell.dir/src/shell_pipe.c.o"

# External object files for target linux_shell
linux_shell_EXTERNAL_OBJECTS =

linux_shell: CMakeFiles/linux_shell.dir/main.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/queen.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/cat.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/cd.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/chmod.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/date.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/echo.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/exec.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/kill.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/ls.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/mkdir.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/pwd.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/rm.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/rmdir.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/wc.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/who.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/whoami.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/error.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/shell_function.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/output.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/string_helper.c.o
linux_shell: CMakeFiles/linux_shell.dir/src/shell_pipe.c.o
linux_shell: CMakeFiles/linux_shell.dir/build.make
linux_shell: CMakeFiles/linux_shell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/linux_shell/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Linking C executable linux_shell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linux_shell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linux_shell.dir/build: linux_shell

.PHONY : CMakeFiles/linux_shell.dir/build

CMakeFiles/linux_shell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linux_shell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linux_shell.dir/clean

CMakeFiles/linux_shell.dir/depend:
	cd /home/ubuntu/linux_shell/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/linux_shell /home/ubuntu/linux_shell /home/ubuntu/linux_shell/build /home/ubuntu/linux_shell/build /home/ubuntu/linux_shell/build/CMakeFiles/linux_shell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linux_shell.dir/depend

