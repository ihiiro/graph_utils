#include <iostream>

#include <internal/internal.hpp>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

bool internal::GUTILSproject::initializeGlad() {
  if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
    std::cerr << "ERROR: GLAD could not be initialized\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}
