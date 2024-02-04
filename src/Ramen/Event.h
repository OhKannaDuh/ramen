#pragma once

#include <SDL3/SDL_events.h>
#include <memory>

namespace Ramen
{
  class Ramen;

  class Event {
    public:
      Event(std::shared_ptr<Ramen> ramen);
      int poll(SDL_Event *event);

    private:
      std::shared_ptr<Ramen> ramen;
  };
} // namespace Ramen
