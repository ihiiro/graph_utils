#include <iostream>

#include <shared/graph_utils.hpp>

#include <GLFW/glfw3.h>

#include <test_rendering.hpp>

#include <cassert>

void testRendering(GUTILSproject* project) {
  std::cout << "TESTING rendering FILES..." << "\n\n";

  assert(project->initializeGlad());

  float points_rgb[] {1, 0, 0};
  float points[][2] { {0, 0}, {1, 0}, {34, 34}, {900000, 2} };
  int points_array_length = sizeof(points)/sizeof(points[0]);
  assert(project->startRenderLoop(project->scatterPlot,
    points,
    points_array_length,
    points_rgb,
    true)); // true when quick testing/false for renderloop

  std::cout << "ok";
  std::cout << "\n\n";
}
