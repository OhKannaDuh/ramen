#include "Event.h"

#include "Ramen.h"

namespace Ramen
{
  Event::Event(std::shared_ptr<Ramen> ramen) : ramen(ramen) {
  }

  int Event::poll(SDL_Event *event) {
    return SDL_PollEvent(event);
  }
}; // namespace Ramen
