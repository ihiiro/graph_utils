#include <internal/internal.hpp>

InternalGUTILSproject::~InternalGUTILSproject() {
  glfwTerminate();
}

bool InternalGUTILSproject::initializeGlfw() {
  if (glfwInit() == GLFW_FALSE) {
    return false;
  }

  return true;
}

bool InternalGUTILSproject::setGlfwWindowHints() {
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

bool InternalGUTILSproject::createWindow(short width, short height, const char* title) {
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

bool InternalGUTILSproject::setFramebufferSizeCallback() {
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

GLFWwindow* InternalGUTILSproject::getWindowObject() const {
  if (window == NULL) {
    return NULL;
  }

  return window;
}
