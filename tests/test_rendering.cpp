#include <iostream>

#include <shared/graph_utils.hpp>

#include <GLFW/glfw3.h>

#include <test_rendering.hpp>

#include <cassert>

void testRendering(GUTILSproject* project) {
  std::cout << "TESTING shaders FILES..." << "\n\n";

  assert(project->initializeGlad());

  float rgb[3] {1, 0, 0};
  assert(project->startRenderLoop(rgb, true)); // false when not testing

  std::cout << "ok";
  std::cout << "\n\n";
}
