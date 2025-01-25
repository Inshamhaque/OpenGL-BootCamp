#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Function for handling window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Function to initialize and create a GLFW window
GLFWwindow* initializeWindow(int width, int height, const char* title) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return nullptr;
    }

    // Configure GLFW for OpenGL version 3.3 Core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    // Make the OpenGL context current and set the viewport
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return nullptr;
    }

    return window;
}

// Your rendering logic goes here
void renderLogic() {
    // Example: Clear the screen with a specific color
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f); // Set clear color (dark blue-ish)
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    // Add custom OpenGL rendering commands here
    // Example: Draw shapes, render objects, etc.
}

int main() {
    // Initialize window with desired dimensions and title
    GLFWwindow* window = initializeWindow(800, 600, "OpenGL Window");
    if (!window) return -1;

    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        // Process input
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        // Call your custom rendering logic
        renderLogic();

        // Swap buffers and poll for events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

