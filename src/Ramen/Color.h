#pragma once

#include <stdint.h>

namespace Ramen
{
  struct Color {
      uint8_t r;
      uint8_t g;
      uint8_t b;
      uint8_t a;
  };

  namespace Colors
  {
    static Color red = {255, 0, 0, 255};
    static Color green = {0, 255, 0, 255};
    static Color blue = {0, 0, 255, 255};
    static Color clear = {32, 32, 32, 255};
  } // namespace Colors

} // namespace Ramen
