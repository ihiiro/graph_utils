#include <iostream>
#include <shared/graph_utils.hpp>

bool GUTILSproject::useScatterplot(float points[][2], float points_rgb[], int points_array_length) {
  if (!initializeGlad()) {
    return false;
  }
  else if (!scatterplot(points, points_rgb, points_array_length, false)) {
    return false;
  }

  return true;
}
