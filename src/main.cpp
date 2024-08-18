#include "imgui.h"
#include <glm/glm.hpp>
#include "glwindow.h"
#include "shaderprogram.h"
#include "grid.h"
#include <iostream>
#include <fstream>
#include "pointdrawable.h"

int main(int argc, char** argv) {
    GlWindow window;
    SceneMain sceneMain;

    window.render_loop(sceneMain);
}