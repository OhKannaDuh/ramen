#pragma once

#include <Eigen/Core>
#include <SDL3/SDL.h>
#include <memory>
#include <stdint.h>
#include <string>

namespace Ramen
{
  class Ramen;

  class Window {
    public:
      Window(std::shared_ptr<Ramen> ramen, std::string title, int width, int height, uint32_t flags);
      ~Window();
      Eigen::Vector2f getDimensions();
      SDL_Window *getSdlWindow();

    private:
      std::shared_ptr<Ramen> ramen;
      SDL_Window *window;
  };
} // namespace Ramen
