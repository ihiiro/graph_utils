#include <iostream>

#include <shared/graph_utils.hpp>

#include <test_window.hpp>
#include <test_shaders.hpp>

#include <cassert>

int main() {
  std::cout << "UNIT TESTS\n\n";

  GUTILSproject project;

  testWindow(&project);

  // to make sure that project is always passed by address (so the tests can modify it)
  // always place the assertion under test_window(&project)
  assert(project.getWindowObject());

  testShaders(&project);

  return 0;
}
