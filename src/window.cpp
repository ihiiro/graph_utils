#include <shared/graph_utils.hpp>
#include <GLFW/glfw3.h>


GUTILSproject::~GUTILSproject() {
  glfwTerminate();
}

bool GUTILSproject::initializeGlfw() {
  if (glfwInit() == GLFW_FALSE) {
    return false;
  }

  return true;
}

bool GUTILSproject::setGlfwWindowHints() {
  try {
    // preconfiguring glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }
  catch (...) {
    return false;
  }

  return true;
}

bool GUTILSproject::createWindow(short width, short height, const char* title) {
  try {
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL) {
      glfwTerminate();
      return false;
    }

    glfwMakeContextCurrent(window);
  }
  catch (...) {
    return false;
  }

  return true;
}

bool GUTILSproject::setFramebufferSizeCallback() {
  try {
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
      glViewport(0, 0, width, height);
    });
  }
  catch (...) {
    return false;
  }

  return true;
}
