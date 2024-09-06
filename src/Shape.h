
#pragma once
#include <glm/glm.hpp>
#include <memory>

class Shape {
public:
};

class Circle : public Shape {
  // constructor
public:
  Circle(float radius) : radius(radius) {}
private:
  float radius;
};

class Rectangle : public Shape {
  // constructor
  Rectangle(float width, float height) : width(width), height(height) {}
public:
private:
  float width;
  float height;
};