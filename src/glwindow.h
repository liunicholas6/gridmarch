#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>

class GlWindow {
private:
    GLFWwindow* m_window;
public:
    GlWindow();
    ~GlWindow();
    GLFWwindow* getContext() const { return m_window; };
    void render_loop(std::function<void()> geometry, std::function<void()> ui);
};