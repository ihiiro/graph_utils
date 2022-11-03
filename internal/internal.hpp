/*----------------------------------------------------------------------------------------*/
/*------------------------------------ INTERNAL API --------------------------------------*/
/*----------------------------------------------------------------------------------------*/

#pragma once

#define GLFW_INCLUDE_NONE // needed to prevent include errors

#include <GLFW/glfw3.h>

// for exporting symbols
#include <graph_utils_export.h>

#include <functional>

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

    /*----------------------------------------------------------------------------------------*/
    /*------------------------------------RENDERING-------------------------------------------*/
    /*----------------------------------------------------------------------------------------*/
    bool initializeGlad();
    bool startRenderLoop(float background_color[3],
      std::function<bool (float*, float*)> graph,
      float points[],
      float points_rgb[3],
      bool testing);

    static bool scatterPlot(float points[], float points_rgb[3]); // static is required to prevent errors


    /*--------------------------------------------------------------------------------------*/
    /*-----------------------------------GLOBAL---------------------------------------------*/
    /*--------------------------------------------------------------------------------------*/

    // cleanup
    GRAPH_UTILS_EXPORT ~GUTILSproject();
  };

}
