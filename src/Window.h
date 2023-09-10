#pragma once

#include <SDL3/SDL_video.h>
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
      SDL_Window *getSdlWindow();

    private:
      std::shared_ptr<Ramen> ramen;
      SDL_Window *window;
  };
} // namespace Ramen
