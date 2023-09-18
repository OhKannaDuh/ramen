#pragma once

#include "Rectangle.h"
#include "Vector2.h"
#include <functional>
#include <memory>

namespace Ramen
{
  class Ramen;

  class Camera {
    public:
      Camera(std::shared_ptr<Ramen> ramen);
      void resize();
      void tick(double delta);
      Rectangle transform(Rectangle *source);
      Vector2 transform(Vector2 *source);
      void setBounds(Rectangle bounds);
      void setCenterCallback(std::function<Vector2()> centerCallback);

    private:
      std::shared_ptr<Ramen> ramen;
      int width;
      int height;
      Vector2 position;
      double timeFollowing = 0;
      Vector2 offset;
      Rectangle bounds;
      std::function<Vector2()> centerCallback;
  };
} // namespace Ramen
