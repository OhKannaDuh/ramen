#include "Vector2.h"

#include <cmath>

namespace Ramen
{
  Vector2::Vector2() {
  }

  Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
  }

  bool Vector2::operator==(Vector2 &other) {
    return this->x == other.x && this->y == other.y;
  }

  Vector2 Vector2::operator-(Vector2 &other) {
    return {this->x - other.x, this->y - other.y};
  }

  Vector2 Vector2::operator+(Vector2 &other) {
    return {this->x + other.x, this->y + other.y};
  }

  void Vector2::operator-=(Vector2 &other) {
    this->x -= other.x;
    this->y -= other.y;
  }

  float Vector2::mag() {
    return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
  }

  void Vector2::normalize() {
    float mag = this->mag();
    if (mag == 0) {
      return;
    }

    this->x /= mag;
    this->y /= mag;
  }

  float Vector2::distance(Vector2 &other) {
    return std::sqrt(std::pow(other.x - this->x, 2) + std::pow(other.y - this->y, 2));
  }

  Vector2 Vector2::from(Vector2 &other, float distance) {
    float actual = this->distance(other);
    float scale = actual / distance;

    return {other.x / scale, other.y / scale};
  }

  SDL_FPoint *Vector2::getSdlPoint() {
    this->point = {this->x, this->y};
    return &this->point;
  }
}; // namespace Ramen
