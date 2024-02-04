#include "Camera.h"

#include "Ramen.h"
#include "Window.h"
#include <cmath>

namespace Ramen
{
  Camera::Camera(std::shared_ptr<Ramen> ramen) : ramen(ramen) {
  }

  Camera::~Camera() {
  }

  void Camera::resize() {
    Eigen::Vector2f dimensions = ramen->getWindow()->getDimensions();

    this->offset[0] = dimensions.x() / 2;
    this->offset[1] = dimensions.y() / 2;
  }

  void Camera::tick(double delta) {
    if (this->bounds.volume() <= 0) {
      return;
    }

    this->position.x() = std::clamp(this->position.x(), this->bounds.min()[0] + this->offset.x(), this->bounds.max()[0] - this->offset.x());
    this->position.y() = std::clamp(this->position.y(), this->bounds.min()[1] + this->offset.y(), this->bounds.max()[1] - this->offset.y());
  }

  Eigen::AlignedBox2f Camera::transform(Eigen::AlignedBox2f source) {
    return source.translate(-(this->position - this->offset));
  }

  Eigen::AlignedBox2f Camera::untransform(Eigen::AlignedBox2f source) {
    return source.translate(this->position - this->offset);
  }

  Eigen::Vector2f Camera::transform(Eigen::Vector2f source) {
    return source - (this->position - this->offset);
  }

  Eigen::Vector2f Camera::untransform(Eigen::Vector2f source) {
    return source + (this->position - this->offset);
  }

  void Camera::setBounds(Eigen::AlignedBox2f bounds) {
    this->bounds = bounds;
  }

  Eigen::AlignedBox2f Camera::getBounds() const {
    return this->bounds;
  }

  void Camera::setPosition(Eigen::Vector2f position) {
    this->position = position;
  }

  Eigen::Vector2f Camera::getPosition() const {
    return this->position;
  }

  Eigen::Vector2f Camera::getOffset() const {
    return this->offset;
  }
}; // namespace Ramen
