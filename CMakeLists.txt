cmake_minimum_required(VERSION 3.17)
project(more_clap_extensions LANGUAGES C CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(clap EXCLUDE_FROM_ALL)

add_library(more_clap_extensions INTERFACE)

target_include_directories(more_clap_extensions INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_include_directories(more_clap_extensions INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/clap/include>
  $<INSTALL_INTERFACE:clap/include>)

install(DIRECTORY include/more_clap_extensions DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(TARGETS more_clap_extensions EXPORT more_clap_extensions INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(EXPORT more_clap_extensions DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/more_clap_extensions" FILE "more_clap_extensions-config.cmake")