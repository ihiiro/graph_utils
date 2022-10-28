/*-------------------------------------------------------------------------------------------------*/
/*----------------------------------window.cpp unit tests------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/


#include <iostream>
#include <shared/graph_utils.hpp>
#include <test_window.hpp>

#include <cassert>

void test_window() {
  GUTILSproject Project;

  std::cout << "TESTING window.cpp..." << "\n\n";

  assert(Project.initializeGlfw() && "GLFW could not be initialized");
  assert(Project.setGlfwWindowHints() && "GLFW window hints could not be set");
  assert(Project.createWindow(500, 500, "test window") && "window could not be created");
  assert(Project.setFramebufferSizeCallback() && "framebuffer size callback could not be set");

  std::cout << "\n\n";
}
