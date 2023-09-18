#include "Camera.h"

#include "Ramen.h"
#include "Window.h"
#include <cmath>

#include <iostream>

namespace Ramen
{
  Camera::Camera(std::shared_ptr<Ramen> ramen) : ramen(ramen) {
    this->centerCallback = []() {
      return Vector2();
    };
  }

  void Camera::resize() {
    Vector2 dimensions = ramen->getWindow()->getDimensions();

    this->width = dimensions.x;
    this->height = dimensions.y;

    this->offset.x = this->width / 2;
    this->offset.y = this->height / 2;
  }

  Rectangle Camera::transform(Rectangle *source) {
    return {
        source->x - (this->position.x - this->offset.x),
        source->y - (this->position.y - this->offset.y),
        source->w,
        source->h,
    };
  }

  Vector2 Camera::transform(Vector2 *source) {
    return {
        source->x - (this->position.x - this->offset.x),
        source->y - (this->position.y - this->offset.y),
    };
  }

  void Camera::tick(double delta) {
    this->position = this->centerCallback();

    if (this->bounds.w <= 0 || this->bounds.h <= 0) {
      return;
    }

    float x2 = this->bounds.x + this->bounds.w;
    float y2 = this->bounds.y + this->bounds.h;

    this->position.x = std::clamp(this->position.x, this->bounds.x + this->offset.x, x2 - this->offset.x);
    this->position.y = std::clamp(this->position.y, this->bounds.y + this->offset.y, y2 - this->offset.y);
  }

  void Camera::setBounds(Rectangle bounds) {
    this->bounds = bounds;
  }

  void Camera::setCenterCallback(std::function<Vector2()> centerCallback) {
    this->centerCallback = centerCallback;
  }

}; // namespace Ramen
