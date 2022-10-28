#include <iostream>

#include <shared/graph_utils.hpp>

#include <test_window.hpp>

#include <cassert>

int main() {
  GUTILSproject Project;

  test_window(&Project);

  // to make sure that Project is always passed by address (so the tests can modify it)
  // always place the assertion under test_window(&Project)
  assert(Project.window && "`Project` object was not passed by address");

  return 0;
}
