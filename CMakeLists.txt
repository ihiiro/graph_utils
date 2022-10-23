cmake_minimum_required(VERSION 3.24)

project(graph_utils VERSION 0.1.0 LANGUAGES C CXX)

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
add_library(${PROJECT_NAME}
  SHARED
  ${CMAKE_SOURCE_DIR}/include/shared/graph_utils.hpp
  ${CMAKE_SOURCE_DIR}/src/graph_utils.cpp
)

# tell compiler where to find public headers
target_include_directories(${PROJECT_NAME}
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
  # for dependencies
  ${CMAKE_SOURCE_DIR}/deps
  # for unit tests
  ${CMAKE_SOURCE_DIR}/tests
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(DEV_EXECUTABLE_NAME ${PROJECT_NAME}_DEV)

# this executable is for development
add_executable(${DEV_EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)

# this executable is for unit tests
set(TESTS_EXECUTABLE_NAME ${PROJECT_NAME}_TESTS)
add_executable(${TESTS_EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/tests/unit_tests.cpp)

if (WIN32)
  target_link_libraries(${TESTS_EXECUTABLE_NAME}
    PRIVATE
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/deps/glad/glad.lib
    ${CMAKE_SOURCE_DIR}/deps/GLFW/glfw3.lib
    GL
    X11
    pthread
    dl
  )

  target_link_libraries(${DEV_EXECUTABLE_NAME}
    PRIVATE
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/deps/glad/glad.lib
    ${CMAKE_SOURCE_DIR}/deps/GLFW/glfw3.lib
    GL
    X11
    pthread
    dl
  )
else()
  target_link_libraries(${TESTS_EXECUTABLE_NAME}
    PRIVATE
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/deps/glad/libglad.a
    ${CMAKE_SOURCE_DIR}/deps/GLFW/libglfw3.a
    GL
    X11
    pthread
    dl
  )

  target_link_libraries(${DEV_EXECUTABLE_NAME}
    PRIVATE
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/deps/glad/libglad.a
    ${CMAKE_SOURCE_DIR}/deps/GLFW/libglfw3.a
    GL
    X11
    pthread
    dl
  )
endif()
