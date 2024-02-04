#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <memory>

namespace Ramen
{
  class Ramen;

  class Camera {
    public:
      Camera(std::shared_ptr<Ramen> ramen);
      ~Camera();
      void resize();
      void tick(double delta);
      Eigen::AlignedBox2f transform(Eigen::AlignedBox2f source);
      Eigen::AlignedBox2f untransform(Eigen::AlignedBox2f source);
      Eigen::Vector2f transform(Eigen::Vector2f source);
      Eigen::Vector2f untransform(Eigen::Vector2f source);
      void setBounds(Eigen::AlignedBox2f bounds);
      Eigen::AlignedBox2f getBounds() const;
      void setPosition(Eigen::Vector2f position);
      Eigen::Vector2f getPosition() const;
      Eigen::Vector2f getOffset() const;

    private:
      std::shared_ptr<Ramen> ramen;
      Eigen::Vector2f offset;
      Eigen::Vector2f position;
      Eigen::AlignedBox2f bounds;
  };
} // namespace Ramen
