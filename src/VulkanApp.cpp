#include "VulkanApp.hpp"
#include <stdexcept>

void VulkanApp::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void VulkanApp::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan Test App", nullptr, nullptr);
}

void VulkanApp::initVulkan() {
    // Vulkan init logic goes here
}

void VulkanApp::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void VulkanApp::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
