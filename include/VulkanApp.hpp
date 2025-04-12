#pragma once
#include <GLFW/glfw3.h>

class VulkanApp {
public:
    void run();

private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

    GLFWwindow* window = nullptr;
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;
};
