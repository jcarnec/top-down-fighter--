
#pragma once
#include <memory>
#include <glm/vec2.hpp> // Assuming glm::vec2 is defined in this header
#include <string>

class Shape
{
public:
  // getters
  glm::vec2 getPosition() { return position; }
  glm::vec2 getWorldPosition() { return worldPosition; }
  // setters
  void setPosition(glm::vec2 position) { this->position = position; }
  void setWorldPosition(glm::vec2 worldPosition) { this->worldPosition = worldPosition; }

  virtual std::string getType() { return "SHAPE"; }

private:
  glm::vec2 position = glm::vec2(0.0f, 0.0f);
  glm::vec2 worldPosition = glm::vec2(0.0f, 0.0f);
};

class Circle : public Shape
{
public:
  // constructor
  Circle(float radius) : radius(radius) {}

  // getters
  float getRadius() { return radius; }
  // setters
  void setRadius(float radius) { this->radius = radius; }

  std::string getType() override { return "CIRCLE"; }

private:
  float radius;
};

class Rectangle : public Shape
{
public:
  // constructor
  Rectangle(float width, float height) : width(width), height(height) {}

  // getters
  float getWidth() { return width; }
  float getHeight() { return height; }
  // setters
  void setWidth(float width) { this->width = width; }
  void setHeight(float height) { this->height = height; }

  std::string getType() override { return "RECTANGLE"; }

private:
  float width;
  float height;
};