#include <shared/graph_utils.hpp>
#include <GLFW/glfw3.h>


GUTILSproject::~GUTILSproject() {
  glfwTerminate();
}

bool GUTILSproject::propertiesFalsified() const {
  if ( !glfw_initialized && !window_hints_set && !window_is_not_null && !framebuffer_size_callback_set ) {
    return true;
  }
  return false;
}

/*

initializes the boolean properties to false to avoid undefined behaviour bugs
when comparing

*/
void GUTILSproject::falsifyProperties() {
  glfw_initialized = false;
  window_hints_set = false;
  window_is_not_null = false;
  framebuffer_size_callback_set = false;
}

void GUTILSproject::initializeGlfw() {
  if (!propertiesFalsified()) {
    falsifyProperties();
  }

  if (glfwInit() == GLFW_FALSE) {
    glfw_initialized = false;
    return;
  }

  glfw_initialized = true;
}

void GUTILSproject::setGlfwWindowHints() {
  if (!glfw_initialized) {
    return;
  }

  if (!glfw_initialized) {
    window_hints_set = false;
    return;
  }

  // preconfiguring glfw
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window_hints_set = true;
}

void GUTILSproject::createWindow(short width, short height, const char* title) {
  if (!window_hints_set) {
    return;
  }

  if (!window_hints_set) {
    window_is_not_null = false;
    return;
  }

  window = glfwCreateWindow(width, height, title, NULL, NULL);
  if (window == NULL) {
    window_is_not_null = false;
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);
  window_is_not_null = true;
}

void GUTILSproject::setFramebufferSizeCallback() {
  if (!window_is_not_null) {
    return;
  }

  if (window_is_not_null == false) {
    framebuffer_size_callback_set = false;
    return;
  }

  glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
  });
  framebuffer_size_callback_set = true;
}
