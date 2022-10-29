/*----------------------------------------------------------------------------------------*/
/*------------------------------------ INTERNAL API --------------------------------------*/
/*----------------------------------------------------------------------------------------*/

#pragma once

#include <GLFW/glfw3.h>

class InternalGUTILSproject {
  /*--------------------------------------------------------------------------------------*/
  /*------------------------------window and resizing-------------------------------------*/
  /*--------------------------------------------------------------------------------------*/
private:
  GLFWwindow* window;
public:
  // getters
  GLFWwindow* getWindowObject() const;

  bool initializeGlfw();
  bool setGlfwWindowHints();
  bool createWindow(short x, short y, const char* title);
  bool setFramebufferSizeCallback();

  ~InternalGUTILSproject();
};
