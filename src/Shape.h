
#pragma once
#include <memory>
#include <glm/vec2.hpp> // Assuming glm::vec2 is defined in this header
#include <string>
#include <GL/gl.h>
#include <cmath>
#include <iostream>

class Shape
{
public:
  Shape() {}
  // getters
  glm::vec2 getPosition() const { return position; } // Marked as const
  std::string getType() const { return "SHAPE"; } // Marked as const
  float getRadius() const { return radius; } // Marked as const

  // setters
  void setPosition(glm::vec2 position) { this->position = position; }
  void setRadius(float radius) { this->radius = radius; }
  void setGlobalPosition(glm::vec2 globalPosition) { this->globalPosition = globalPosition; }


  void draw() const
  {
    // draw a circle with the current position and radius
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); // Set line color to red
    glTranslatef(globalPosition.x, globalPosition.y, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
      float degInRad = i * M_PI / 180;
      // get cirlce radius from player with casting
      glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
    }
    glEnd();
    glPopMatrix();
  }

  

private:
  // Position of the shape in local space
  glm::vec2 position = glm::vec2(0.0f, 0.0f);
  glm::vec2 globalPosition = glm::vec2(0.0f, 0.0f);
  float radius = 50.0f;
};

