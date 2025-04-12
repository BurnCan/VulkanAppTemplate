cmake_minimum_required(VERSION 3.16)
project(VulkanAppTemplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(FetchContent)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG latest
)
FetchContent_MakeAvailable(glfw)

find_package(Vulkan REQUIRED)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    src/*.cpp
    include/*.hpp
)

add_executable(VulkanApp ${SRC_FILES})
target_include_directories(VulkanApp PRIVATE include)
target_link_libraries(VulkanApp PRIVATE glfw Vulkan::Vulkan)
