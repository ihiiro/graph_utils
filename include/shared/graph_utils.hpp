/*

 VERSION: 0.1.0
 AUTHOR: ihiiro

*/

#pragma once

// this gives us the GRAPH_UTILS_EXPORT macro that we can use to explicitly
// export symbols (needed for windows dlls)
#include <graph_utils_export.h>

// #include <string.h>

/* window and resizing */
class GUTILSproject {
protected: // NOTE: add unit test to make sure that protected symbols are protected
  bool project_initialized;
  bool glfw_initialized;
  bool window_hints_set;
  bool window_is_not_null;
  bool framebuffer_size_callback_set;
private:
  GLFWwindow* window;
public:
  void init();
  void initializeGlfw();
  void setGlfwWindowHints();
  void createWindow(short x, short y, std::string_view);
  void setFramebufferSizeCallback();
};
