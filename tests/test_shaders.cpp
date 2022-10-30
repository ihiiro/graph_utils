#include <iostream>

#include <shared/graph_utils.hpp>

#include <test_shaders.hpp>

#include <cassert>

void testShaders(GUTILSproject* project) {
  std::cout << "TESTING shaders FILES..." << "\n\n";

  assert(project->initializeGlad());

  std::cout << "ok";
  std::cout << "\n\n";
}
