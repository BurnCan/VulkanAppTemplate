#include "VulkanApp.hpp"
#include <cstdlib>   // For EXIT_SUCCESS
#include <stdexcept> // For std::exception
int main() {
    VulkanApp app;
    try {
        app.run();
    } catch (const std::exception& e) {
        fprintf(stderr, "Fatal error: %s\n", e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
