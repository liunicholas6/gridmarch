#pragma once
#include <array>
#include <glm/glm.hpp>

namespace quad {
    std::array<glm::vec3, 4> vertices = {
            glm::vec3(-1, -1, 0),
            glm::vec3(-1, 1, 0),
            glm::vec3(1, 1, 0),
            glm::vec3(1, -1, 0)
    };

    std::array<unsigned int, 6> indices = {0, 1, 3, 1, 2, 3};
}