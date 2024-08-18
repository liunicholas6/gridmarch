#include "pointdrawable.h"
#include "grid.h"
#include "raysdrawable.h"
class Scene {
public:
    Scene() = default;
    virtual void create_gui() = 0;
    virtual void render_geometry(float screenWidth, float screenHeight, float zoom) = 0;
    virtual ~Scene() = default;
};

class SceneMain : public Scene {
public:
    SceneMain();
    void create_gui() override;
    void render_geometry(float screenWidth, float screenHeight, float zoom) override;
    virtual ~SceneMain() = default;
private:
    Grid m_grid;
    std::unique_ptr<Scene> m_subscene;
    std::vector<const char*> m_subsceneNames = {"Scene1", "Scene2"};
    int m_subsceneIx = 0;
};

class Scene1 : public Scene {
public:
    Scene1();
    void create_gui() override;
    void render_geometry(float screenWidth, float screenHeight, float zoom) override;
    virtual ~Scene1() = default;
private:
    PointDrawable m_pointDrawable;
    RaysDrawable m_raysDrawable;
    float m_rayAngle = 0;
    void set_ray();
};