#include <iostream>

#include <internal/internal.hpp>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <functional>
#include <vector>

bool internal::GUTILSproject::initializeGlad() {
  if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
    std::cerr << "ERROR: GLAD could not be initialized\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}

unsigned int createVertexShader(const char* vertex_shader_source) {
  int success;
  char info_log[internal::GUTILSproject::INFO_LOG_SIZE];

  unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
  glCompileShader(vertex_shader);
  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex_shader, internal::GUTILSproject::INFO_LOG_SIZE, NULL, info_log);
    std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info_log;
    std::cerr << "\n";
    glDeleteShader(vertex_shader);
    return 0;
  }

  return vertex_shader;
}

unsigned int createFragmentShader(const char* fragment_shader_source) {
  int success;
  char info_log[internal::GUTILSproject::INFO_LOG_SIZE];

  unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
  glCompileShader(fragment_shader);
  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment_shader, internal::GUTILSproject::INFO_LOG_SIZE, NULL, info_log);
    std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << info_log;
    std::cerr << "\n";
    glDeleteShader(fragment_shader);
    return 0;
  }

  return fragment_shader;
}

unsigned int createShaderProgram(unsigned int vertex_shader, unsigned int fragment_shader) {
  int success;
  char info_log[internal::GUTILSproject::INFO_LOG_SIZE];

  unsigned int ID = glCreateProgram();
  glAttachShader(ID, vertex_shader);
  glAttachShader(ID, fragment_shader);
  glLinkProgram(ID);
  glGetProgramiv(ID, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(ID, internal::GUTILSproject::INFO_LOG_SIZE, NULL, info_log);
    std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info_log;
    std::cerr << "\n";
    glDetachShader(ID, vertex_shader);
    glDeleteShader(vertex_shader);
    glDetachShader(ID, fragment_shader);
    glDeleteShader(fragment_shader);
    glDeleteProgram(ID);
    return 0;
  }

  glDetachShader(ID, vertex_shader);
  glDeleteShader(vertex_shader);
  glDetachShader(ID, fragment_shader);
  glDeleteShader(fragment_shader);

  return ID;
}

float internal::GUTILSproject::max(float array_of_floats[][2], int length_of_array) {
  std::vector<float> vector_1d;
  float temp;
  float max_number;

  for (int i = 0; i < length_of_array; i++) {
    float temp_x = array_of_floats[i][0];
    float temp_y = array_of_floats[i][1];

    temp = (temp_x > temp_y) ? temp_x : temp_y;
    vector_1d.push_back(temp);
  }

  max_number = *std::max_element(vector_1d.begin(), vector_1d.end());
  // this is for freeing vector from memory
  vector_1d.clear();
  vector_1d.shrink_to_fit();

  return max_number;
}

bool internal::GUTILSproject::scatterplot(float points[][2], float points_rgb[], int points_array_length, bool testing) {
  bool loop_entered = false;

  // configuration
  const char* VERTEX_SHADER_SOURCE = "#version 330 core\n"
                                     "layout (location = 0) in vec3 input_position;\n"
                                     "layout (location = 1) in vec3 input_color;\n"
                                     "out vec3 output_color;\n"
                                     "void main() {\n"
                                     " gl_Position = vec4(input_position, 1.0f);\n"
                                     " output_color = input_color;\n"
                                     "}\0";

  const char* FRAGMENT_SHADER_SOURCE = "#version 330 core\n"
                                       "out vec4 fragment_color;\n"
                                       "in vec3 output_color;\n"
                                       "void main() {\n"
                                       " fragment_color = vec4(output_color, 1.0f);\n"
                                       "}\0";

  unsigned int vertex_shader = createVertexShader(VERTEX_SHADER_SOURCE);
  unsigned int fragment_shader = createFragmentShader(FRAGMENT_SHADER_SOURCE);
  unsigned int shader_program = createShaderProgram(vertex_shader, fragment_shader);

  // vertices to draw the actual plane
  float plane_vertices[] {
    -.9f, .9f, .0f,   1.0f, 1.0f, 1.0f,
    -.9f, -.9f, .0f,  1.0f, 1.0f, 1.0f,
    .9f, -.9f, .0f,    1.0f, 1.0f, 1.0f,
    -.92f, .865f, .0f,  1.0f, 1.0f, 1.0f,
    -.88f, .865f, .0f, 1.0f, 1.0f, 1.0f,
    .88f, -.88f, .0f,  1.0f, 1.0f, 1.0f,
    .88f, -.92f, .0f, 1.0f, 1.0f, 1.0f,
  };
  unsigned short indices[] {
    0, 1, 2,
    1, 0, 3,
    0, 4, 2,
    5, 2, 6,
  };

  unsigned int VAO; // vertex array object
  unsigned int VBO; // vertex buffer object
  unsigned int EBO; // element buffer object

  // generate objects
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  // bind/configure objects
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(plane_vertices), plane_vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // for color vertex attributes
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // points
  std::vector<float> points_vertices;
  float coefficient = 1.755;
  // float uniform_distance = 1.8 / points_array_length;
  float max_coordinate = max(points, points_array_length);

  if (max_coordinate == 0) {
    std::cerr << "MAX COORDINATE IS 0\n";
    std::cerr << "\n";
    return false;
  }

  float x;
  float y;

  for (int i = 0; i < points_array_length; i++) {
    x = points[i][0];
    y = points[i][1];

    points_vertices.push_back(-.9+x/max_coordinate*coefficient);
    points_vertices.push_back(-.9+y/max_coordinate*coefficient);
    points_vertices.push_back(.0f);
    points_vertices.push_back(points_rgb[0]);
    points_vertices.push_back(points_rgb[1]);
    points_vertices.push_back(points_rgb[2]);
  }

  unsigned int VAO_points; // vertex array object
  unsigned int VBO_points; // vertex buffer object

  // generate objects
  glGenVertexArrays(1, &VAO_points);
  glGenBuffers(1, &VBO_points);

  // bind/configure objects
  glBindVertexArray(VAO_points);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_points);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * points_vertices.size(), &points_vertices[0], GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // for color vertex attributes
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);


  for (int i = 0, size = points_vertices.size(); i < size; i++) {
    std::cout << points_vertices[i];
    std::cout << "\n";
  }

  glPointSize(5.0f);
  // render loop
  while (!glfwWindowShouldClose(window)) {
    loop_entered = true;


    // process input
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, true);
    }

    // background color
    glClearColor(.0f, .0f, .0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // drawing segment
    glUseProgram(shader_program);
    glBindVertexArray(VAO);
    glDrawElements(GL_LINES, 12, GL_UNSIGNED_SHORT, 0);

    glBindVertexArray(VAO_points);
    glDrawArrays(GL_POINTS, 0, points_array_length);

    glfwSwapBuffers(window);
    glfwPollEvents();

    if (testing) {
      break;
    }
  }

  // cleanup
  glBindVertexArray(0);
  glDeleteVertexArrays(1, &VAO);
  glDeleteVertexArrays(1, &VAO_points);
  glDeleteBuffers(1, &EBO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &VBO_points);
  glDeleteProgram(shader_program);
  points_vertices.clear();
  points_vertices.shrink_to_fit();

  if (!loop_entered) {
    std::cerr << "ERROR: render loop could not be started\n";
    std::cerr << "\n";
    return false;
  }

  return true;
}
