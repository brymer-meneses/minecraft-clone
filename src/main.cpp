
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <optional>

auto initialize_window(const int height, const int width, const char* title) -> std::optional<GLFWwindow*> {
  if (!glfwInit()) {
    printf("Failed to initialize GLFW.");
    return std::nullopt;
  }

  // set opengl version to 4.6
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

  // core profile means that we will not bother with deprecated functions
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (!window) {
    printf("Failed to create GLFW window\n");
    glfwTerminate();
    return std::nullopt;
  }

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress) ) {
    printf("Failed to initialize Glad.\n");
    return std::nullopt;
  }

  glViewport(0, 0, width, height);
  return window;
}

auto main(void) -> int {

  constexpr int window_height = 600;
  constexpr int window_width  = 600;
  constexpr const char* window_title  = "Minecraft: Low Budget Edition";

  auto result = initialize_window(window_height, window_width, window_title);
  if (!result)
    return -1;

  GLFWwindow* window = result.value();

  glfwSetKeyCallback(window,
      [](GLFWwindow *window, int key, int scandcode, int action, int mods) { 
        if (key == GLFW_KEY_E && action == GLFW_PRESS)
           printf("You pressed e\n");
      }
  );

  while (!glfwWindowShouldClose(window)) {
    glClearColor(250.0f/255.0f, 119.0f/255.0f, 110.0f/255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
