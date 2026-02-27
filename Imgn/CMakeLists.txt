cmake_minimum_required(VERSION 3.16)
project(Imgn LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# --------------------------------------------------
# Third-party libraries (git submodules)
# --------------------------------------------------

# GLAD
add_subdirectory(vendor/glad/cmake)
glad_add_library(glad STATIC
    API gl:core=4.6
)

# GLFW
add_subdirectory(vendor/glfw)

# GLM (header-only)
add_subdirectory(vendor/glm)

# spdlog
add_subdirectory(vendor/spdlog)

# ZLIB (Required for Assimp, forcing shared if possible)
set(ZLIB_USE_STATIC_LIBS OFF)
find_package(ZLIB REQUIRED)

# Assimp
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)
set(ASSIMP_NO_EXPORT ON CACHE BOOL "" FORCE)
add_subdirectory(vendor/assimp)

# ImGui (manual, correct way)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/vendor/imgui)

add_library(imgui STATIC
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

target_link_libraries(imgui PUBLIC glfw glad)

# --------------------------------------------------
# Engine library (DLL / SO)
# --------------------------------------------------

file(GLOB_RECURSE IMGN_SRC
    src/*.cpp
    src/*.c
)

add_library(Imgn SHARED ${IMGN_SRC})

target_precompile_headers(Imgn
    PRIVATE src/Imgnpch.h
)

target_include_directories(Imgn PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(Imgn PRIVATE
    Imgn_BUILD_DLL
    Imgn_DYNAMIC_LINK
)

target_link_libraries(Imgn PRIVATE
    glad
    glfw
    glm
    imgui
    spdlog::spdlog
    assimp
    ZLIB::ZLIB
)

# --------------------------------------------------
# OpenGL (platform safe)
# --------------------------------------------------

if (WIN32)
    target_link_libraries(Imgn PRIVATE opengl32)
elseif (APPLE)
    find_library(OpenGL_LIB OpenGL)
    target_link_libraries(Imgn PRIVATE ${OpenGL_LIB})
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(Imgn PRIVATE OpenGL::GL)
endif()