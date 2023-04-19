cmake_minimum_required(VERSION 3.0.0)
project(linux_shell VERSION 0.1.0  LANGUAGES C)

include(CTest)
enable_testing()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include_directories(
        ${PROJECT_SOURCE_DIR}/inc/
)
add_executable(linux_shell 
            main.c
            src/queen.c
            src/cat.c
            src/cd.c
            src/chmod.c
            src/date.c
            src/echo.c
            src/exec.c
            src/kill.c
            src/ls.c
            src/mkdir.c
            src/pwd.c
            src/rm.c
            src/rmdir.c
            src/wc.c
            src/who.c
            src/whoami.c
            src/error.c
            src/shell_function.c
            src/output.c
            src/string_helper.c
            src/shell_pipe.c
            src/help.c
)

include(CPack)
