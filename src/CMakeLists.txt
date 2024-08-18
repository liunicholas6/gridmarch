cmake_minimum_required(VERSION 3.10)
project(better_minecraft_gridmarch)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

set(EXTERNAL ${CMAKE_SOURCE_DIR}/../external)
set(IMGUI_DIR ${EXTERNAL}/imgui)
set(GLAD_DIR ${EXTERNAL}/glad)
set(DRAWABLES_DIR drawables)

add_library(glad ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PUBLIC ${GLAD_DIR}/include)

# include_directories(${DRAWABLES_DIR})


# Source files
set(SOURCES
    main.cpp
    glwindow.cpp
    shader.cpp
    shaderprogram.cpp
    scene.cpp
    grid.cpp
    gridmarch.cpp
    ${DRAWABLES_DIR}/gridmarchdrawable.cpp
    ${DRAWABLES_DIR}/pointdrawable.cpp
    ${DRAWABLES_DIR}/raysdrawable.cpp
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# Include directories
include_directories(${DRAWABLES_DIR} ${IMGUI_DIR} ${IMGUI_DIR}/backends ${GL3W_DIR}/include)

# Platform-specific settings
if(UNIX AND NOT APPLE)
    message("Configuring for Linux")
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GLFW REQUIRED glfw3)
    set(LIBS ${GLFW_LIBRARIES} GL)
    include_directories(${GLFW_INCLUDE_DIRS})
    link_directories(${GLFW_LIBRARY_DIRS})

elseif(APPLE)
    message("Configuring for macOS")
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GLFW REQUIRED glfw3)
    set(LIBS
        ${GLFW_LIBRARIES}
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-L/usr/local/lib"
        "-L/opt/local/lib"
        "-L/opt/homebrew/lib"
    )
    include_directories(${GLFW_INCLUDE_DIRS} "/usr/local/include" "/opt/local/include" "/opt/homebrew/include")
    link_directories(${GLFW_LIBRARY_DIRS})

elseif(WIN32)
    message("Configuring for Windows")
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GLFW REQUIRED glfw3)
    set(LIBS ${GLFW_LIBRARIES} gdi32 opengl32 imm32)
    include_directories(${GLFW_INCLUDE_DIRS})
    link_directories(${GLFW_LIBRARY_DIRS})
endif()

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} ${LIBS})

# Compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -g -Wall -Wformat)
