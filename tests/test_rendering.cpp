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

  float float_array[][2] { {1.2, 1.5}, {1.7, 2.7}, {2.2, 7.1} };
  int size = sizeof(float_array)/sizeof(float_array[0]);
  assert(GUTILSproject::max(float_array, size) == 7.1f && "max method does not return max number");

  std::cout << "ok";
  std::cout << "\n\n";
}
