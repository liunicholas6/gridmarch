#include "pointdrawable.h"
class Scene {

public:
    virtual void create_gui() = 0;
    virtual void render_geometry() = 0;
    virtual ~Scene() = default;
};

class Scene1 : Scene {
public:
    void create_gui() override;
    void render_geometry() override;
    virtual ~Scene1() = default;
private:
    PointDrawable m_point_drawable;
    
};