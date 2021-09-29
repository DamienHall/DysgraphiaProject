#include "vector2.h"
#include <cmath>

Vector2::Vector2() {
  this->x = 0;
  this->y = 0;
}

Vector2::Vector2(float x, float y) {
  this->x = x;
  this->y = y;
}

std::string Vector2::toString() {
  return "{x: " + std::to_string(this->x) + ", y: " + std::to_string(this->y) + "}";
}

float Vector2::getX() {
  return this->x;
}

float Vector2::getY() {
  return this->y;
}

void Vector2::setX(float x) {
  this->x = x;
}

void Vector2::setY(float y) {
  this->y = y;
}

void Vector2::set(float x, float y) {
  this->x = x;
  this->y = y;
}

Vector2 Vector2::add(Vector2 vec) {
  return Vector2(this->x+vec.getX(), this->y+vec.getY());
}

Vector2 Vector2::subtract(Vector2 vec) {
  return Vector2(this->x-vec.getX(), this->y-vec.getY());
}

Vector2 Vector2::scale(float scalar) {
  return Vector2(this->x*scalar, this->y*scalar);
}

float Vector2::getMagnitude() {
  return sqrt(pow(this->x,2)+pow(this->y,2));
}

float Vector2::distanceFrom(Vector2 vec) {
  Vector2 distanceVector = this->subtract(vec);
  return distanceVector.getMagnitude();
}
