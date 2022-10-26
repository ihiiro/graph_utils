/*---------------------------------------------------------------------------------------------*/
/*----------------------------------window unit tests------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/


#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shared/graph_utils.hpp>
#include <test_window.hpp>
#include <tester.hpp>
#include <string.h>

void test_window() {
  tester::printCurrentFileName(__FILE__);

  GUTILSproject Project;

  Project.falsifyProperties();
  tester::boolTest("Project.propertiesFalsified()", Project.propertiesFalsified(), true);

  Project.initializeGlfw();
  tester::boolTest("Project.glfw_initialized", Project.glfw_initialized, true);

  Project.setGlfwWindowHints();
  tester::boolTest("Project.window_hints_set", Project.window_hints_set, true);

  int width;
  int height;
  int set_width = 500;
  int set_height = 500;
  Project.createWindow(set_width, set_height, "Some title");
  glfwGetWindowSize(Project.window, &width, &height);
  tester::intTest("set_width", set_width, width);
  tester::intTest("set_height", set_height, height);

  Project.setFramebufferSizeCallback();
  tester::boolTest("Project.framebuffer_size_callback_set", Project.framebuffer_size_callback_set, true);
}
