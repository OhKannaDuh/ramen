#pragma once

#include <SDL3/SDL_render.h>
#include <memory>
#include <string>

namespace Ramen
{
  class Ramen;

  class Renderer {
    public:
      Renderer(std::shared_ptr<Ramen> ramen, std::string name, uint32_t flags);
      ~Renderer();

    private:
      std::shared_ptr<Ramen> ramen;
      SDL_Renderer *renderer;
  };
} // namespace Ramen
