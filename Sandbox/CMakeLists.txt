cmake_minimum_required(VERSION 3.10)

# Project name and language
project(Sandbox VERSION 1.0 LANGUAGES CXX C)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB_RECURSE SRC
    src/*.cpp 
    src/*.c
)

# Create the executable
add_executable(Sandbox ${SRC})

# Add Imgn include directories
target_include_directories(Sandbox PRIVATE 
    ${CMAKE_SOURCE_DIR}/../Imgn/src
    ${CMAKE_SOURCE_DIR}/../Imgn/vendor/spdlog/include
    ${CMAKE_SOURCE_DIR}/../Imgn/vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/../Imgn/vendor/glm
    ${CMAKE_SOURCE_DIR}/../Imgn/vendor/imgui
    ${CMAKE_SOURCE_DIR}/../Imgn/vendor/assimp/include
    ${CMAKE_SOURCE_DIR}/../Imgn/build/gladsources/glad/include
)

# Link Imgn library
if (WIN32)
    target_link_libraries(Sandbox PRIVATE ${CMAKE_SOURCE_DIR}/../Imgn/bin/alib/Debug/Imgn.lib)
    # Copy DLL to output directory
    add_custom_command(
        TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/../Imgn/bin/bin/Debug/Imgn.dll
            $<TARGET_FILE_DIR:Sandbox>
    )
else()
    target_link_libraries(Sandbox PRIVATE ${CMAKE_SOURCE_DIR}/../Imgn/build/libImgn.so)
    # Set RPATH so it finds the .so
    set_target_properties(Sandbox PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "${CMAKE_SOURCE_DIR}/../Imgn/build"
    )
    # Copy .so next to the executable
    add_custom_command(
        TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/../Imgn/build/libImgn.so
            $<TARGET_FILE_DIR:Sandbox>/libImgn.so
    )
endif()

# Add platform-specific macros
target_compile_definitions(Sandbox PRIVATE Imgn_DYNAMIC_LINK)