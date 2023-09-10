#include "SDL.h"

#include <SDL3/SDL.h>

namespace Ramen
{
  SDL::SDL(uint32_t flags) {
    if (SDL_Init(flags) != 0) {
    }
  }

  SDL::~SDL() {
    SDL_Quit();
  }
}; // namespace Ramen
