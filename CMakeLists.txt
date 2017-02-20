project(qtubuntu-print)
cmake_minimum_required(VERSION 2.8.9)

# Set the global vars
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")


# Load translation tools
find_program(INTLTOOL_MERGE intltool-merge)
if(NOT INTLTOOL_MERGE)
    message(FATAL_ERROR "Could not find intltool-merge, please install the intltool package")
endif()

find_program(INTLTOOL_EXTRACT intltool-extract)
if(NOT INTLTOOL_EXTRACT)
    message(FATAL_ERROR "Could not find intltool-extract, please install the intltool package")
endif()

# Setup code
add_subdirectory(src)

# Setup gettext defs and include po directory
set(GETTEXT_PACKAGE "qtubuntu-print")
add_definitions(-DI18N_DOMAIN="${GETTEXT_PACKAGE}")

add_subdirectory(po)

# Setup tests
enable_testing()

add_subdirectory(tests)
