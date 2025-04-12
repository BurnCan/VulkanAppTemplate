
# VulkanAppTemplate

## Introduction
A template project for Vulkan-based applications with cross-platform support, designed to be compiled and built using various tools.

---

## Prerequisites
Ensure you have the following software installed depending on your operating system:

### Common Dependencies:
1. **Git**: Install [Git](https://git-scm.com/downloads) for version control and to fetch dependencies.
2. **CMake**: Install [CMake](https://cmake.org/download/) to configure the project.
3. **Vulkan SDK**: Download the Vulkan SDK from [LunarG](https://vulkan.lunarg.com/sdk/home) and set up environment variables.

---

## OS-Specific Dependencies

### Windows
1. **Visual Studio 2022+**
   - Download and install [Visual Studio 2022](https://visualstudio.microsoft.com/downloads/).
   - Ensure that you install the **Desktop development with C++** workload, which includes the **MSVC compiler**, **CMake**, and **Windows SDK**.
   - **Git**: You will also need [Git](https://git-scm.com/download/win) to manage repositories and dependencies.
   
2. **MSYS2/MinGW** (if you choose to use MinGW or a different build toolchain)
   - Download and install [MSYS2](https://www.msys2.org/).
   - Update package database: 
     ```bash
     pacman -Sy
     ```
   - Install necessary build tools (e.g., `gcc`, `make`, etc.):
     ```bash
     pacman -S base-devel mingw-w64-x86_64-toolchain
     ```

### macOS
1. **Xcode Command Line Tools**
   - Install **Xcode Command Line Tools** with the following command:
     ```bash
     xcode-select --install
     ```
   - This will install essential tools like `clang`, `git`, and `make`.

2. **Homebrew**
   - Install [Homebrew](https://brew.sh/), a package manager for macOS:
     ```bash
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
     ```
   - Then install dependencies such as `git`, `cmake`, and `ninja` using:
     ```bash
     brew install cmake git ninja
     ```

### Linux (Ubuntu/Debian)
1. **Package Manager**
   - Update your package list and install dependencies:
     ```bash
     sudo apt update
     sudo apt install build-essential cmake git ninja-build libvulkan-dev
     ```
   - You might also need to install `clang` or `gcc` depending on your system.

2. **Vulkan SDK**
   - Download the Vulkan SDK from [LunarG](https://vulkan.lunarg.com/sdk/home).
   - Follow the setup instructions specific to your distribution (typically extracting the SDK and setting environment variables).

---

## Building the Project

### Windows
#### Method 1: Visual Studio 2022+
1. Open **x64 Native Tools Command Prompt** (VS).
   - You can open it by searching for **"x64 Native Tools Command Prompt for VS 2022"** in the Start menu.
   
2. Run the following commands:
   ```bash
   cmake -B build -G "Visual Studio 17 2022" -A x64
   cmake --build build --config Release
   ```

   The binary will be located at:
   ```
   build\Release\VulkanApp.exe
   ```

#### Method 2: Using MSYS2/MinGW
1. Open **MSYS2 shell** and install the necessary dependencies:
   ```bash
   pacman -Sy
   pacman -S base-devel mingw-w64-x86_64-toolchain
   ```

2. Run CMake to configure and build the project:
   ```bash
   cmake -B build -G "MinGW Makefiles"
   cmake --build build --config Release
   ```

---

### macOS

1. **Install Dependencies**:
   ```bash
   brew install cmake git ninja
   ```

2. **Build Project**:
   ```bash
   cmake -B build -G "Unix Makefiles"
   cmake --build build --config Release
   ```

---

### Linux

1. **Install Dependencies**:
   ```bash
   sudo apt update
   sudo apt install build-essential cmake git ninja-build libvulkan-dev
   ```

2. **Build Project**:
   ```bash
   cmake -B build -G "Unix Makefiles"
   cmake --build build --config Release
   ```

---

## Running the Project
After building, the executable will be in the `build/Release/` folder. You can run it with:
```bash
./VulkanApp
```

---

## Notes
- If you run into any issues, ensure that all dependencies are installed correctly and that your environment variables are properly set.
