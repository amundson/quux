configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/quux_version_h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/quux_version.h"
)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(quux SHARED quux.cc quux.h)

install(TARGETS quux DESTINATION ${LIB_INSTALL_DIR})
install(FILES
        quux.h
        DESTINATION ${INCLUDE_INSTALL_DIR}/quux)
