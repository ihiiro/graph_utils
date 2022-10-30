/*----------------------------------------------------------------------------------------*/
/*------------------------------------ INTERNAL API --------------------------------------*/
/*----------------------------------------------------------------------------------------*/

#pragma once

#define GLFW_INCLUDE_NONE // needed to prevent include errors
#include <GLFW/glfw3.h>

// for exporting symbols
#include <graph_utils_export.h>

namespace internal {
  class GUTILSproject {
    /*--------------------------------------------------------------------------------------*/
    /*------------------------------WINDOW AND RESIZING-------------------------------------*/
    /*--------------------------------------------------------------------------------------*/
  private:
    GLFWwindow* window;
  public:
    // getters
    GLFWwindow* getWindowObject() const;

    bool initializeGlfw();
    bool setGlfwWindowHints();
    bool createWindow(short width, short height, const char* title);
    bool setFramebufferSizeCallback();

    bool initializeGlad();

    /*--------------------------------------------------------------------------------------*/
    /*-----------------------------------GLOBAL---------------------------------------------*/
    /*--------------------------------------------------------------------------------------*/

    // cleanup
    GRAPH_UTILS_EXPORT ~GUTILSproject();
  };

}
