#include <iostream>

#include <shared/graph_utils.hpp>

#include <test_window.hpp>

#include <cassert>

int main() {
  std::cout << "UNIT TESTS\n\n";

  GUTILSproject Project;

  test_window(&Project);

  // to make sure that Project is always passed by address (so the tests can modify it)
  // always place the assertion under test_window(&Project)
  assert(Project.getWindowObject());

  return 0;
}
