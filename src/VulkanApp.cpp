#include "VulkanApp.hpp"
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <glm/glm.hpp>
#include <iostream>

void VulkanApp::run() {
    initWindow();
    initVulkan();  // Just ImGui init for now
    mainLoop();
    cleanup();
}

void VulkanApp::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);

    window = glfwCreateWindow(WIDTH, HEIGHT, "ImGui Test (OpenGL backend)", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
}

void VulkanApp::initVulkan() {
    // Set up ImGui with OpenGL backend (no actual Vulkan yet)
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    // Just for sanity check that GLM is usable:
    glm::vec3 testVector(1.0f, 2.0f, 3.0f);
    float magnitude = glm::length(testVector);
    printf("GLM test vector length: %f\n", magnitude);
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void VulkanApp::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Example ImGui UI
        ImGui::Begin("Hello from ImGui");
        ImGui::Text("This is a test window using OpenGL backend.");
        static float f = 0.0f;
        ImGui::SliderFloat("Float Value", &f, 0.0f, 1.0f);
        ImGui::End();

        // Render ImGui
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }
}

void VulkanApp::cleanup() {
    // Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}
