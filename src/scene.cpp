#include "scene.h"
#include <imgui.h>

SceneMain::SceneMain() : m_subscene(std::make_unique<Scene1>()) {

}

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

Scene1::Scene1() {
    set_ray();
}

void Scene1::create_gui()
{
    ImGui::Begin("Ray controls");
    if (ImGui::DragFloat2("origin", &m_pointDrawable.get_point()[0], 0.125f)) {
        set_ray();
    }
    if (ImGui::SliderFloat("rayAngle", &m_rayAngle, 0, M_PI * 2)) {
        set_ray();
    }
    ImGui::End();
}

void Scene1::render_geometry(float screenWidth, float screenHeight, float zoom)
{
    m_pointDrawable.draw(screenWidth, screenHeight, zoom);
    m_raysDrawable.draw(screenWidth, screenHeight, zoom);
}

void Scene1::set_ray() {
    float x = glm::cos(m_rayAngle);
    float y = glm::sin(m_rayAngle);
    glm::vec2 origin = m_pointDrawable.get_point();
    std::vector<glm::vec2> polyline({origin, origin + glm::vec2(x, y)});
    m_raysDrawable.set_rays(polyline);
}
