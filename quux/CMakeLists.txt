configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/quux_version_h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/quux_version.h"
)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(quux SHARED quux.cc quux.h)
target_link_libraries(quux garply::garply)

install(TARGETS quux DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES
        quux.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/quux)
