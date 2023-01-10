#include <iostream>

#include <shared/graph_utils.hpp>

#include <GLFW/glfw3.h>

#include <test_rendering.hpp>

#include <cassert>

void testRendering(GUTILSproject* project) {
  std::cout << "TESTING rendering FILES..." << "\n\n";

  assert(project->initializeGlad());

  float points_rgb[] {.0f, .0f, 1.0f};
  float points[][2] { {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5} };
  int points_array_length = sizeof(points)/sizeof(points[0]);
  // true when quick testing/false for renderloop
  assert(project->scatterplot(points, points_rgb, points_array_length, false));

  float float_array[][2] { {1.2, 1.5}, {1.7, 2.7}, {2.2, 7.1} };
  int size = sizeof(float_array)/sizeof(float_array[0]);
  assert(GUTILSproject::max(float_array, size) == 7.1f && "max method does not return max number");

  // assert(project->useScatterplot(points, points_rgb, points_array_length));

  std::cout << "ok";
  std::cout << "\n\n";
}
