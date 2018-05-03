configure_file("${CMAKE_CURRENT_SOURCE_DIR}/quux_version_h.in"
               "${CMAKE_CURRENT_BINARY_DIR}/quux_version.h")

add_library(quux SHARED quux.cc quux.h)
target_include_directories(quux
                           BEFORE
                           PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                           PRIVATE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_link_libraries(quux garply::garply)

add_executable(quuxifier quuxifier.cc)
target_include_directories(quux
                           BEFORE
                           PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                           PRIVATE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_link_libraries(quuxifier quux)

install(TARGETS quux quuxifier
        EXPORT QuuxTargets DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES quux.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/quux)
