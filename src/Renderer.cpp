#include "Renderer.h"

#include "Ramen.h"
#include "Window.h"

namespace Ramen
{
  Renderer::Renderer(std::shared_ptr<Ramen> ramen, std::string name, uint32_t flags) : ramen(ramen) {
    this->renderer = SDL_CreateRenderer(this->ramen->getWindow()->getSdlWindow(), name.c_str(), flags);
  }

  Renderer::~Renderer() {
    SDL_DestroyRenderer(this->renderer);
  }
}; // namespace Ramen
