/*

 VERSION: 0.1.0
 AUTHOR: ihiiro

*/

#pragma once

/*

this gives us the GRAPH_UTILS_EXPORT macro that we can use to explicitly
export symbols (needed for windows dlls)

*/
#include <graph_utils_export.h>
#include <GLFW/glfw3.h>
#include <string_view>

/*--------------------------------------------------------------------------------------*/
/*------------------------------------ PUBLIC API --------------------------------------*/
/*--------------------------------------------------------------------------------------*/

class GUTILSproject {

  /*--------------------------------------------------------------------------------------*/
  /*------------------------------window and resizing-------------------------------------*/
  /*--------------------------------------------------------------------------------------*/

public:
  GLFWwindow* window;

  void falsifyProperties();
  void initializeGlfw();
  void setGlfwWindowHints();
  void createWindow(short x, short y, const char* title);
  void setFramebufferSizeCallback();

  ~GUTILSproject();

  // indicators
  bool propertiesFalsified() const;
  bool glfw_initialized;
  bool window_hints_set;
  bool window_is_not_null;
  bool framebuffer_size_callback_set;
};

/*----------------------------------------------------------------------------------------*/
/*------------------------------------ INTERNAL API --------------------------------------*/
/*----------------------------------------------------------------------------------------*/
