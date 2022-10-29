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

#include <internal/internal.hpp>

class GUTILSproject: public InternalGUTILSproject {
};

/*--------------------------------------------------------------------------------------*/
/*------------------------------------ PUBLIC API --------------------------------------*/
/*--------------------------------------------------------------------------------------*/
