#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include "scene.h"

class GlWindow {
private:
    GLFWwindow* m_window;
    float m_zoom = 100;
public:
    GlWindow();
    ~GlWindow();
    GLFWwindow* getContext() const { return m_window; };
    void render_loop(Scene &scene);
};