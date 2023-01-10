/*-------------------------------------------------------------------------------------------------*/
/*----------------------------------window.cpp unit tests------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/


#include <iostream>
#include <shared/graph_utils.hpp>

#include <test_window.hpp>

#include <cassert>

void testWindow(GUTILSproject* project) {
  std::cout << "TESTING window FILES..." << "\n\n";

  // testing internal API
  assert(project->initializeGlfw());
  assert(project->setGlfwWindowHints());
  assert(project->createWindow(1000, 1000, "test window"));
  assert(project->setFramebufferSizeCallback());

  std::cout << "ok";
  std::cout << "\n\n";
}
