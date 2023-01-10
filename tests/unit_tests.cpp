#include <iostream>

#include <shared/graph_utils.hpp>

#include <test_window.hpp>
#include <test_rendering.hpp>

#include <cassert>

int main() {
  std::cout << "UNIT TESTS\n\n";

  GUTILSproject project(1000, 1000, "test window");

  testWindow(&project);

  // to make sure that project is always passed by address (so the tests can modify it)
  // always place the assertion under test_window(&project)
  assert(project.getWindowObject());

  testRendering(&project);

  return 0;
}
