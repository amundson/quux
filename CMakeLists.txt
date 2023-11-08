cmake_minimum_required(VERSION 3.5.0)
project(QUUX VERSION 3.0.0)

find_package(Garply 3.0.0 EXACT REQUIRED CONFIG)

include(GNUInstallDirs)

enable_testing()

add_subdirectory(quux)
add_subdirectory(tests)

include(CMakePackageConfigHelpers)

# * Versioning File (Same for Build/Install Trees)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfigVersion.cmake
  VERSION
  ${QUUX_VERSION}
  COMPATIBILITY
  ExactVersion)

# * Build Tree Config/Targets Files
set(QUUX_EXPORTED_INCLUDEDIR "${PROJECT_SOURCE_DIR}")
set(QUUX_EXPORTED_LIBDIR "${PROJECT_BINARY_DIR}/quux")

configure_package_config_file(QuuxConfig.cmake.in
                              ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfig.cmake
                              INSTALL_DESTINATION
                              ${CMAKE_CURRENT_BINARY_DIR}
                              INSTALL_PREFIX
                              ${CMAKE_CURRENT_BINARY_DIR}
                              PATH_VARS
                              QUUX_EXPORTED_INCLUDEDIR
                              QUUX_EXPORTED_LIBDIR)

# NB: must be called after EXPORT argument is defined, hence moving
# add_subdirectory earlier.
export(EXPORT QuuxTargets NAMESPACE quux::)

# * Install Tree Config/Targets Files
set(QUUX_EXPORTED_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}")
set(QUUX_EXPORTED_LIBDIR "${CMAKE_INSTALL_LIBDIR}")

configure_package_config_file(
  QuuxConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/QuuxConfig.cmake
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/cmake/quux
  PATH_VARS
  QUUX_EXPORTED_INCLUDEDIR
  QUUX_EXPORTED_LIBDIR)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/QuuxConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/QuuxConfigVersion.cmake
              DESTINATION
              ${CMAKE_INSTALL_LIBDIR}/cmake/quux)
install(EXPORT QuuxTargets
               NAMESPACE
               quux::
               DESTINATION
               ${CMAKE_INSTALL_LIBDIR}/cmake/quux)

# * Uninstall target
if(NOT TARGET uninstall)
  configure_file("${CMAKE_CURRENT_LIST_DIR}/uninstall.cmake.in"
                 "${CMAKE_BINARY_DIR}/uninstall.cmake" IMMEDIATE
                 @ONLY)

  add_custom_target(uninstall
                    COMMAND "${CMAKE_COMMAND}" -P
                            "${CMAKE_BINARY_DIR}/uninstall.cmake"
                    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()
