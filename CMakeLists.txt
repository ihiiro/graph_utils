cmake_minimum_required(VERSION 3.24)

project(graph_utils_DEV VERSION 0.1.0 LANGUAGES C CXX)

# remove 'lib' prefix for shared/static libs on windows
if (WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "")
  set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif()

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
# hide all symbols
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)
# add library with source and header files
add_library(graph_utils
  SHARED
  ${CMAKE_SOURCE_DIR}/include/graph_utils_export.h
  ${CMAKE_SOURCE_DIR}/src/window.cpp
)

# tell compiler where to find public headers
target_include_directories(graph_utils
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
  # for dependencies
  ${CMAKE_SOURCE_DIR}/deps
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# this executable is for development
add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)

if (WIN32)
  target_link_libraries(${PROJECT_NAME}
    PRIVATE
    graph_utils
    ${CMAKE_SOURCE_DIR}/deps/glad/glad.lib
    ${CMAKE_SOURCE_DIR}/deps/GLFW/glfw3.lib
    GL
    X11
    pthread
    dl
  )
else()
  target_link_libraries(${PROJECT_NAME}
    PRIVATE
    graph_utils
    ${CMAKE_SOURCE_DIR}/deps/glad/libglad.a
    ${CMAKE_SOURCE_DIR}/deps/GLFW/libglfw3.a
    GL
    X11
    pthread
    dl
  )
endif()
