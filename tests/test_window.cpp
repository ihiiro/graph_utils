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
  assert(project->createWindow(500, 500, "test window"));
  assert(project->setFramebufferSizeCallback());

  // testing public API
  assert(project->init(500, 500, "test window"));


  std::cout << "ok";
  std::cout << "\n\n";
}
