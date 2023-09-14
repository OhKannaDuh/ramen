#pragma once

#include "Vector2.h"
#include <SDL3/SDL_rect.h>

namespace Ramen
{
  class Rectangle {
    public:
      float x = 0;
      float y = 0;
      float w = 0;
      float h = 0;

      Rectangle(float x = 0, float y = 0, float w = 0, float h = 0);
      Rectangle(int x, int y, int w, int h);
      bool contains(Vector2 *point);
      bool intersects(const Rectangle *other);
      Vector2 getCenter();
      SDL_FRect *getSdlRect();

    private:
      SDL_FRect rect;
  };
} // namespace Ramen
