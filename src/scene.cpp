#include "scene.h"
#include <imgui.h>

SceneMain::SceneMain() : m_subscene(std::make_unique<Scene1>()) {}

void SceneMain::render_geometry(float screenWidth, float screenHeight, float zoom)
{
    m_grid.draw(screenWidth, screenHeight, zoom);
    m_subscene->render_geometry(screenWidth, screenHeight, zoom);
}

void SceneMain::create_gui() {
    ImGui::Begin("Scene select");
    ImGui::Combo("Scene Select", &m_subsceneIx, m_subsceneNames.data(), m_subsceneNames.size());
    ImGui::End();
    m_subscene->create_gui();
}

void Scene1::create_gui()
{
    ImGui::Begin("Ray controls");
    if (ImGui::DragFloat2("origin", &m_origin[0], 0.125f)) {
        m_gridMarchDrawable.set_point(m_origin);
    }
    if (ImGui::SliderFloat("rayAngle", &m_rayAngle, -M_PI, M_PI)) {
        float x = glm::cos(m_rayAngle);
        float y = glm::sin(m_rayAngle);
        m_gridMarchDrawable.set_direction(glm::vec2(x, y));
    }
    if (ImGui::Button("March")) {
        m_gridMarchDrawable.march();
        glm::vec2 direction = m_gridMarchDrawable.get_gridMarch().get_direction();
        m_rayAngle = glm::atan(direction.y / direction.x);
        m_origin = m_gridMarchDrawable.get_gridMarch().get_point();
    }
    ImGui::End();
}

void Scene1::render_geometry(float screenWidth, float screenHeight, float zoom)
{
    m_gridMarchDrawable.draw(screenWidth, screenHeight, zoom);
}