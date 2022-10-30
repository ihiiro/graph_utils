#include <iostream>
#include <internal/internal.hpp>

internal::GUTILSproject::~GUTILSproject() {
  glfwTerminate();
}

bool internal::GUTILSproject::initializeGlfw() {
  if (glfwInit() == GLFW_FALSE) {
    std::cerr << "ERROR: GLFW could not be initialized\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}

bool internal::GUTILSproject::setGlfwWindowHints() {
  try {
    // preconfiguring glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }
  catch (...) {
    std::cerr << "ERROR: GLFW window hints could not be set\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}

bool internal::GUTILSproject::createWindow(short width, short height, const char* title) {
  try {
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL) {
      glfwTerminate();
      std::cerr << "ERROR: window could not be created due to:\n";
      std::cerr << "ERROR: window == NULL\n";
      std::cerr << "\n";

      return false;
    }

    glfwMakeContextCurrent(window);
  }
  catch (...) {
    std::cerr << "ERROR: window could not be created\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}

bool internal::GUTILSproject::setFramebufferSizeCallback() {
  try {
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
      glViewport(0, 0, width, height);
    });
  }
  catch (...) {
    std::cerr << "ERROR: framebuffer size callback could not be set\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}

GLFWwindow* internal::GUTILSproject::getWindowObject() const {
  if (window == NULL) {
    // this error is only relevant to the assertion in unit_tests.cpp
    std::cerr << "ERROR: `Project` object was not passed by address\n";
    std::cerr << "\n";
    return NULL; // always return NULL not false
  }

  return window;
}
