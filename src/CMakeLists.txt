# Find packages
find_package(Qt5Core)
find_package(Qt5DBus)
find_package(Qt5PrintSupport)
find_package(Qt5Widgets)
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
  constants.h
  i18n.cpp
  main.cpp
  qubuntuprintdevice.cpp
  qubuntuprintengine.cpp
  qubuntuprintsupport.cpp
)

add_library(${LIBNAME} SHARED ${qtubuntu_print_SRC})

qt5_use_modules(${LIBNAME} Core DBus PrintSupport Widgets)
target_link_libraries(${LIBNAME} content-hub)


# Install the plugin file
execute_process(
    COMMAND qmake -query QT_INSTALL_PLUGINS
            OUTPUT_VARIABLE QT_INSTALL_PLUGINS_DIR
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
install(TARGETS ${LIBNAME} DESTINATION ${QT_INSTALL_PLUGINS_DIR}/printsupport)


# Show files in QtC
file(GLOB QTC_FILES
     RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     *.cpp *.h *.json)

add_custom_target(qtubuntu_print_qtc_files DEPENDS main.cpp SOURCES ${QTC_FILES})


# Set variables for outside use
set(SRC_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
set(SRC_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)
set(SRC_LIBNAME "lib${LIBNAME}" PARENT_SCOPE)
