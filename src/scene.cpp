#include "scene.h"
#include <imgui.h>

void Scene1::create_gui()
{
    ImGui::Begin("Ray controls");
    ImGui::DragFloat2("origin", &m_pointDrawable.get_point()[0], 0.125f);
    ImGui::SliderFloat("rayAngle", &m_rayAngle, 0, M_PI * 2);
    ImGui::End();
}

void Scene1::render_geometry(float screenWidth, float screenHeight, float zoom)
{
    Scene::render_geometry(screenWidth, screenHeight, zoom);
    m_pointDrawable.draw(screenWidth, screenHeight, zoom);
}

void Scene::render_geometry(float screenWidth, float screenHeight, float zoom)
{
    m_grid.draw(screenWidth, screenHeight, zoom);
}
