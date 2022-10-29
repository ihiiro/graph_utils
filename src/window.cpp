#include <shared/graph_utils.hpp>

bool GUTILSproject::init(short width, short height, const char* title) {
  if (!initializeGlfw()) {
    return false;
  }
  else if (!setGlfwWindowHints()) {
    return false;
  }
  else if (!createWindow(width, height, title)) {
    return false;
  }
  else if (!setFramebufferSizeCallback()) {
    return false;
  }

  return true;
}
