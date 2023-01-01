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
    static const short INFO_LOG_SIZE = 512;

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
    bool startRenderLoop(std::function<bool (float points[][2], float points_rgb[], int points_array_length)> graph,
      float points[][2],
      int points_array_length,
      float points_rgb[],
      bool testing);

    static bool scatterPlot(float points[][2], float points_rgb[], int points_array_length); // static is required to prevent errors
    static float max(float array_of_floats[][2], int length_of_array);

    /*--------------------------------------------------------------------------------------*/
    /*-----------------------------------GLOBAL---------------------------------------------*/
    /*--------------------------------------------------------------------------------------*/

    // cleanup
    GRAPH_UTILS_EXPORT ~GUTILSproject();
  };

}
