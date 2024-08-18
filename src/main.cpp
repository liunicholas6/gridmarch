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
    Scene1 scene1;
    window.render_loop(scene1);
}