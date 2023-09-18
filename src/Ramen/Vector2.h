#pragma once

#include <SDL3/SDL_rect.h>

namespace Ramen
{
  class Vector2 {
    public:
      float x = 0;
      float y = 0;

      Vector2();
      Vector2(float x, float y);
      bool operator==(Vector2 &other);
      Vector2 operator-(Vector2 &other);
      Vector2 operator+(Vector2 &other);
      void operator-=(Vector2 &other);
      float mag();
      void normalize();
      float distance(Vector2 &other);
      Vector2 from(Vector2 &other, float distance);
      SDL_FPoint *getSdlPoint();

    private:
      SDL_FPoint point;
  };
} // namespace Ramen
