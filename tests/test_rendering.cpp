#include <iostream>

#include <shared/graph_utils.hpp>

#include <GLFW/glfw3.h>

#include <test_rendering.hpp>

#include <cassert>

void testRendering(GUTILSproject* project) {
  std::cout << "TESTING rendering FILES..." << "\n\n";

  assert(project->initializeGlad());

  float background_rgb[3] {1, 0, 0};
  float points_rgb[3] {0, 1, 0};
  float points[] {1, 2, 3, 4};
  assert(project->startRenderLoop(background_rgb,
    project->scatterPlot,
    points,
    points_rgb,
    true)); // false when not testing

  std::cout << "ok";
  std::cout << "\n\n";
}
