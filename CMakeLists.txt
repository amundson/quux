cmake_minimum_required(VERSION 3.0.0)
project(QUUX VERSION 2.0.0)

find_package(Garply 2.0.0 EXACT REQUIRED CONFIG)

include(GNUInstallDirs)

include_directories(BEFORE ${QUUX_SOURCE_DIR})
enable_testing()

include(CMakePackageConfigHelpers)

configure_package_config_file(QuuxConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/quux
  PATH_VARS CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfigVersion.cmake
  VERSION ${QUUX_VERSION}
  COMPATIBILITY ExactVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfigVersion.cmake
              DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/quux)

add_subdirectory(quux)
add_subdirectory(tests)
