#include "VulkanApp.hpp"
#include <stdexcept>
#include <glm/glm.hpp>         // Test GLM
#include <imgui.h>             // Test ImGui
#include <backends/imgui_impl_glfw.h>  // Needed for integration
#include <backends/imgui_impl_vulkan.h> // Will be needed later for Vulkan ImGui


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
    // Minimal ImGui context creation (not Vulkan-specific yet)
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Just as a sanity check that GLM is usable:
    glm::vec3 testVector(1.0f, 2.0f, 3.0f);
    float magnitude = glm::length(testVector);
    printf("GLM test vector length: %f\n", magnitude);
}


void VulkanApp::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void VulkanApp::cleanup() {
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}

