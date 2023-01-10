#include <iostream>
#include <shared/graph_utils.hpp>

int main() {
  GUTILSproject project(1000, 1000, "test window");

  float points[][2] { {0, 0}, {1, 1} };
  float points_rgb[] {.0f, .0f, 1.0f};
  float points_array_size { sizeof(points)/sizeof(points[0]) };

  project.useScatterplot(points, points_rgb, points_array_size);

  return 0;
}
