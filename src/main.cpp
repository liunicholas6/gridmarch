#include "imgui.h"
#include <glm/glm.hpp>
#include "glwindow.h"
#include "shaderprogram.h"
#include "grid.h"
#include <iostream>
#include <fstream>
#include "pointdrawable.h"

void imgui_window() {
    static float f = 0.0f;
    // bool showFigure = false;

    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)

    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

    // if (ImGui::Button("Button")) {                            // Buttons return true when clicked (most widgets return true when edited/activated)
    //     showFigure = true;
    // }

    ImGui::End();
}


int main(int argc, char** argv) {
    GlWindow window;
    Grid grid;

    glPointSize(10);
    // ShaderProgram pointShader("point.vert", "point.frag");
    // GLuint u_position = pointShader.get_uniform_location("u_position");

    // glm::vec2 origin = glm::vec2();

    PointDrawable pointDrawable;

    auto gui = [&](){
        ImGui::Begin("Controls");                          // Create a window called "Hello, world!" and append into it.
        ImGui::DragFloat2("origin", &pointDrawable.get_point()[0], 0.125f);
        // if (ImGui::Button("Button")) {                            // Buttons return true when clicked (most widgets return true when edited/activated)
        //     showFigure = true;
        // }

        ImGui::End();
    };

    glDisable(GL_DEPTH_TEST);

    auto render = [&] {
        int width;
        int height;
        glfwGetWindowSize(window.getContext(), &width, &height);
        grid.draw(width, height, 100);
        pointDrawable.draw(width, height);
        // pointShader.use_me();
        // glm::vec2 originNDC = origin * 100.f / glm::vec2(width, height);
        // glUniform2f(u_position, originNDC.x, originNDC.y);
        // glDrawArrays(GL_POINTS, 0, 1);
    };

    window.render_loop(std::function<void()>(render), std::function<void()>(gui));
}