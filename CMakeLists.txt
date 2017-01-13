project(qtubuntu-print)
cmake_minimum_required(VERSION 2.8.9)

# Load translation tools
find_program(INTLTOOL_MERGE intltool-merge)
if(NOT INTLTOOL_MERGE)
    message(FATAL_ERROR "Could not find intltool-merge, please install the intltool package")
endif()

find_program(INTLTOOL_EXTRACT intltool-extract)
if(NOT INTLTOOL_EXTRACT)
    message(FATAL_ERROR "Could not find intltool-extract, please install the intltool package")
endif()

# Set the vars
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")

# Find packages
find_package(Qt5Core)
find_package(Qt5DBus)
find_package(Qt5PrintSupport)
find_package(PkgConfig REQUIRED)
pkg_check_modules(CONTENTHUB REQUIRED libcontent-hub)

# Replicate qmake CONFIG += plugin
add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_NO_DEBUG)
add_definitions(-DQT_SHARED)

# Disable use of cups in Qt print support
add_definitions(-DQT_NO_CUPS)

# Setup include directories
include(GNUInstallDirs)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Core_PRIVATE_INCLUDE_DIRS}
    ${Qt5DBus_INCLUDE_DIRS}
    ${Qt5PrintSupport_INCLUDE_DIRS}
    ${Qt5PrintSupport_PRIVATE_INCLUDE_DIRS}
    ${LIBCONTENT_HUB_INCLUDE_DIRS}
)

# Setup the library sources and name
set(LIBNAME qtubuntu-print)

set(
  qtubuntu_print_SRC
  i18n.cpp
  main.cpp
  qubuntuprintdevice.cpp
  qubuntuprintengine.cpp
  qubuntuprintsupport.cpp
)

add_library(${LIBNAME} SHARED ${qtubuntu_print_SRC})

qt5_use_modules(${LIBNAME} Core DBus PrintSupport)
target_link_libraries(${LIBNAME} content-hub)


# Install the plugin file
execute_process(
    COMMAND qmake -query QT_INSTALL_PLUGINS
            OUTPUT_VARIABLE QT_INSTALL_PLUGINS_DIR
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
install(TARGETS ${LIBNAME} DESTINATION ${QT_INSTALL_PLUGINS_DIR}/printsupport)


# Setup gettext defs and include po directory
set(GETTEXT_PACKAGE "qtubuntu-print")
add_definitions(-DI18N_DOMAIN="${GETTEXT_PACKAGE}")

add_subdirectory(po)


# Show files in QtC
file(GLOB QTC_FILES
     RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     *.cpp *.h *.json)

add_custom_target(qtubuntu_print_qtc_files DEPENDS main.cpp SOURCES ${QTC_FILES})
