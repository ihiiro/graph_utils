#include <iostream>

#include <internal/internal.hpp>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <functional>

bool internal::GUTILSproject::initializeGlad() {
  if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
    std::cerr << "ERROR: GLAD could not be initialized\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}

bool internal::GUTILSproject::startRenderLoop(float background_color[3],
  std::function<bool (float*, float*)> graph,
  float points[],
  float points_rgb[],
  bool testing) {
  bool loop_entered = false;

  while (!glfwWindowShouldClose(window)) {
    loop_entered = true;


    // process input
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, true);
    }

    // graph
    graph(points, points_rgb);

    // make window white
    glClearColor(background_color[0], background_color[1], background_color[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();

    if (testing) {
      break;
    }
  }

  if (!loop_entered) {
    std::cerr << "ERROR: render loop could not be started\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}

bool internal::GUTILSproject::scatterPlot(float points[], float points_rgb[]) {
  return 0;
}
