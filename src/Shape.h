
#pragma once
#include <glm/glm.hpp>
#include <memory>

class Shape {
public:
  virtual bool isColliding(Shape* other) { return false; };
};

class Circle : public Shape {
  // constructor
public:
  Circle(float radius) : radius(radius) {}
  bool isColliding(Shape* other) override {
    return false;
  };
private:
  float radius;
};

class Rectangle : public Shape {
  // constructor
  Rectangle(float width, float height) : width(width), height(height) {}
public:
  bool isColliding(Shape* other) override {
    return false;
  };
private:
  float width;
  float height;
};