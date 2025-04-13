cmake_minimum_required(VERSION 3.16)
project(VulkanAppTemplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(FetchContent)

# GLFW
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG latest
)
FetchContent_MakeAvailable(glfw)

# GLM
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 0.9.9.8
)
FetchContent_MakeAvailable(glm)

# ImGui
FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG docking  # use "master" if you don't want docking support
)
FetchContent_MakeAvailable(imgui)

# Vulkan
find_package(Vulkan REQUIRED)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    src/*.cpp
    include/*.hpp
)

add_executable(VulkanApp ${SRC_FILES})

target_include_directories(VulkanApp PRIVATE
    include
    ${imgui_SOURCE_DIR}
    ${glm_SOURCE_DIR}
)

target_link_libraries(VulkanApp PRIVATE
    glfw
    Vulkan::Vulkan
)
