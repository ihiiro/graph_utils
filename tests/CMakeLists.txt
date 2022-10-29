cmake_minimum_required(VERSION 3.24)

project(graph_utils_TEST VERSION 0.1.0 LANGUAGES C CXX)


# this executable is for unit tests
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../bin)
add_executable(${PROJECT_NAME}
  ./unit_tests.cpp
  ./test_window.cpp
  ../internal/internal_window.cpp
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
  .
  ..
  ../include
  ../deps
)

if (WIN32)
  target_link_libraries(${PROJECT_NAME}
    PRIVATE
    /home/hiro/projects/graph_utils/lib/graph_utils.dll
    /home/hiro/projects/graph_utils/deps/glad/glad.lib
    /home/hiro/projects/graph_utils/deps/GLFW/glfw3.lib
    GL
    X11
    pthread
    dl
  )
else()
  target_link_libraries(${PROJECT_NAME}
    PRIVATE
    /home/hiro/projects/graph_utils/lib/libgraph_utils.so
    /home/hiro/projects/graph_utils/deps/glad/libglad.a
    /home/hiro/projects/graph_utils/deps/GLFW/libglfw3.a
    GL
    X11
    pthread
    dl
  )
endif()
