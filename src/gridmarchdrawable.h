#pragma once
#include "gridmarch.h"
#include "pointdrawable.h"
#include "raysdrawable.h"

class GridMarchDrawable {
public:
    GridMarchDrawable();
    const GridMarch& get_gridMarch() {return m_gridMarch; }
    void set_point(glm::vec2 point);
    void set_direction(glm::vec2 direction);
    void march();
    void draw(float screenWidth, float screenHeight, float zoom);
private:
    GridMarch m_gridMarch;
    PointDrawable m_pointDrawable;
    RaysDrawable m_raysDrawable;
    void set_render_data();
};