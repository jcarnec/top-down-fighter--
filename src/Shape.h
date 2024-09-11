
#pragma once
#include <memory>
#include <glm/vec2.hpp> // Assuming glm::vec2 is defined in this header
#include <string>

class Shape
{
public:
  Shape() {}
  // getters
  glm::vec2 getPosition() const { return position; } // Marked as const
  std::string getType() const { return "SHAPE"; } // Marked as const
  float getRadius() const { return radius; } // Marked as const

  

private:
  // Position of the shape in local space
  glm::vec2 position = glm::vec2(0.0f, 0.0f);
  float radius = 50.0f;
};

