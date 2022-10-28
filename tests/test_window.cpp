/*-------------------------------------------------------------------------------------------------*/
/*----------------------------------window.cpp unit tests------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/


#include <iostream>
#include <shared/graph_utils.hpp>
#include <test_window.hpp>

#include <cassert>

void test_window(GUTILSproject* project) {
  std::cout << "TESTING window.cpp..." << "\n\n";

  assert(project->initializeGlfw() && "GLFW could not be initialized");
  assert(project->setGlfwWindowHints() && "GLFW window hints could not be set");
  assert(project->createWindow(500, 500, "test window") && "window could not be created");
  assert(project->setFramebufferSizeCallback() && "framebuffer size callback could not be set");

  std::cout << "\n\n";
}
