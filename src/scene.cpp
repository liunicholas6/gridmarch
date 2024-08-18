#include "scene.h"
#include <imgui.h>

void Scene1::create_gui()
{
    ImGui::Begin("Controls");
    ImGui::DragFloat2("origin", &m_pointDrawable.get_point()[0], 0.125f);
    ImGui::End();
}

void Scene1::render_geometry(float screenWidth, float screenHeight, float zoom)
{
    Scene::render_geometry(screenWidth, screenHeight, zoom);
    m_pointDrawable.draw(screenWidth, screenHeight);
}

void Scene::render_geometry(float screenWidth, float screenHeight, float zoom)
{
    m_grid.draw(screenWidth, screenHeight, zoom);
}
