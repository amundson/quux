cmake_minimum_required(VERSION 3.0.0)
project(QUUX)
set(QUUX_VERSION_MAJOR 1)
set(QUUX_VERSION_MINOR 0)
set(QUUX_VERSION "${QUUX_VERSION_MAJOR}.${QUUX_VERSION_MINOR}")

find_package(Garply 1.0 EXACT REQUIRED CONFIG)
include_directories(${GARPLY_INCLUDE_DIR})
link_directories(${GARPLY_LIB_DIR})

set(INCLUDE_INSTALL_DIR include/ CACHE PATH "install directory")
set(LIB_INSTALL_DIR lib/ CACHE PATH "lib directory")

include_directories(${QUUX_SOURCE_DIR})
enable_testing()

include(CMakePackageConfigHelpers)

configure_package_config_file(QuuxConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfig.cmake
  INSTALL_DESTINATION ${LIB_INSTALL_DIR}/quux/cmake
  PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfigVersion.cmake
  VERSION ${QUUX_VERSION}
  COMPATIBILITY ExactVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfigVersion.cmake
        DESTINATION ${LIB_INSTALL_DIR}/quux/cmake)

add_subdirectory(quux)
add_subdirectory(tests)
