#include "pointdrawable.h"
#include "grid.h"
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
    Scene1() = default;
    void create_gui() override;
    void render_geometry(float screenWidth, float screenHeight, float zoom) override;
    virtual ~Scene1() = default;
private:
    PointDrawable m_pointDrawable;
    float m_rayAngle;
};