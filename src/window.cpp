#include <iostream>
#include <shared/graph_utils.hpp>

bool GUTILSproject::init(short width, short height, const char* title) {
  if (!initializeGlfw()) {
    std::cerr << "ERROR: project could not be initialized due to:\n";
    std::cerr << "ERROR: GLFW could not be initialized\n";
    std::cerr << "\n";
    return false;
  }
  else if (!setGlfwWindowHints()) {
    std::cerr << "ERROR: project could not be initialized due to:\n";
    std::cerr << "ERROR: GLFW window hints could not be set\n";
    std::cerr << "\n";
    return false;
  }
  else if (!createWindow(width, height, title)) {
    std::cerr << "ERROR: project could not be initialized due to:\n";
    std::cerr << "ERROR: window could not be created\n";
    std::cerr << "\n";
    return false;
  }
  else if (!setFramebufferSizeCallback()) {
    std::cerr << "ERROR: project could not be initialized due to:\n";
    std::cerr << "ERROR: framebuffer size callback could not be set\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}
