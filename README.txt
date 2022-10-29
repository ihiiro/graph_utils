NOTE: DIRECTORY TREE MUST BE CHANGED LATER

make deps/ -> add the following inside the deps/ directory:
 1) a new directory named "glad"
 2) a new directory named "GLFW"
 3) go to this website https://glad.dav1d.de/
    -- select Core profile, and gl version no earlier than 3.3 and language C/C++
      specification OpenGL
    -- click generate
    -- download the zip file
4) unzip
5) put include/glad/ inside src/
6) modify glad.c: #include <glad/glad.h> --> #include "glad/glad.h"
7) run: clang -c -fPIE glad.c
8) run: ar rcs libglad.a glad.o
9) put libglad.a and glad.h inside "glad" directory

10) go to this website https://www.glfw.org/download.html
11) click on source package
12) unzip and go into resulting directory
13) make directory build  take resulting static library libglfw3.a and
14) go into it, and run "cmake .." then "make"
15) put build/src/libglfw3.a and include/glfw3.h inside directory "GLFW"
if successful the directory tree should look something like this:
.
├── CMakeLists.txt
├── deps
│   ├── glad
│   │   ├── glad.h
│   │   └── libglad.a
│   └── GLFW
│       ├── glfw3.h
│       └── libglfw3.a
├── include
│   ├── graph_utils_export.h
│   └── shared
│       └── graph_utils.hpp
├── README.txt
├── src
│   ├── graph_utils.cpp
│   └── main.cpp
└── tests
    ├── someunittest.cpp
    ├── someunittest.hpp
    └── unit_tests.cpp

Now go to directory root and make a "build" directory:
  go inside it and run: cmake .. then make
  library should be in a directory named lib/ and public headers in include/


to use the library:
  use include/
  use lib/
  use deps/
