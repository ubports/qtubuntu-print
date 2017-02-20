# Find packages
find_package(Qt5Core REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(PkgConfig REQUIRED)

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
    ${Qt5PrintSupport_INCLUDE_DIRS}
    ${Qt5PrintSupport_PRIVATE_INCLUDE_DIRS}
    ${LIBCONTENT_HUB_INCLUDE_DIRS}
)

# Setup the library sources and name
set(LIBNAME fakeprint)
set(
  fakeprint_SRC
  main.cpp
)

add_library(${LIBNAME} SHARED ${fakeprint_SRC})
qt5_use_modules(${LIBNAME} Core PrintSupport)

# Show files in QtC
file(GLOB QTC_FILES
     RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     *.cpp *.h *.json)

add_custom_target(fake_print_qtc_files DEPENDS main.cpp SOURCES ${QTC_FILES})


# Set variables for outside use
set(FAKEPRINT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
set(FAKEPRINT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)
set(FAKEPRINT_LIBNAME "lib${LIBNAME}" PARENT_SCOPE)
