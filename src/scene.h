#include "pointdrawable.h"
#include "grid.h"
#include "raysdrawable.h"
class Scene {
public:
    Scene() = default;
    virtual void create_gui() = 0;
    virtual void render_geometry(float screenWidth, float screenHeight, float zoom);
    virtual ~Scene() = default;
private:
    Grid m_grid;
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