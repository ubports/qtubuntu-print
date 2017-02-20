include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

find_package(Qt5PrintSupport)
find_package(Qt5Test REQUIRED)

# Add the fakeprint plugin
add_subdirectory(fakeprint)

# Copy the library to a plugins folder
add_custom_target(unittest_copyFiles ALL
  COMMENT "Copying files: ${SRC_LIBNAME}.so and ${FAKEPRINT_LIBNAME}.so into separate PLUGIN/printsupport/lib.so folders"
  DEPENDS qtubuntu-print fakeprint)

add_custom_command(
  TARGET unittest_copyFiles
  COMMAND ${CMAKE_COMMAND} -E copy "${SRC_BINARY_DIR}/${SRC_LIBNAME}.so" "${CMAKE_CURRENT_BINARY_DIR}/qtubuntu-print/printsupport/${SRC_LIBNAME}.so"
  DEPENDS qtubuntu-print
  )
add_custom_command(
  TARGET unittest_copyFiles
  COMMAND ${CMAKE_COMMAND} -E copy "${FAKEPRINT_BINARY_DIR}/${FAKEPRINT_LIBNAME}.so" "${CMAKE_CURRENT_BINARY_DIR}/fakeprint/printsupport/${FAKEPRINT_LIBNAME}.so"
  DEPENDS fakeprint
  )

# Add the tests
add_executable(testFakePrinterInfo tst_fakeprinterinfo.cpp)
target_link_libraries(testFakePrinterInfo Qt5::Test Qt5::PrintSupport)
add_test(tst_fakeprinterInfo testFakePrinterInfo)

add_executable(testPrinterInfo tst_printerinfo.cpp)
target_link_libraries(testPrinterInfo Qt5::Test Qt5::PrintSupport)
add_test(tst_printerInfo testPrinterInfo)
