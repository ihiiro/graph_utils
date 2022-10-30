#include <iostream>

#include <shared/graph_utils.hpp>

#include <GLFW/glfw3.h>

#include <test_shaders.hpp>

#include <cassert>

void testShaders(GUTILSproject* project) {
  std::cout << "TESTING shaders FILES..." << "\n\n";

  assert(project->initializeGlad());
  assert(project->startRenderLoop(true)); // false when not testing

  std::cout << "ok";
  std::cout << "\n\n";
}
