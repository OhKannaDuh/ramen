#pragma once

#include <SDL3/SDL_timer.h>
#include <stdint.h>

namespace Ramen
{
  class Timer {
    public:
      void start();
      double getDelta();
      int add(uint32_t interval, SDL_TimerCallback callback, void *param);
      void wait(uint64_t time);

    private:
      uint32_t current = 0;
      uint32_t previous = 0;
      uint32_t getTime();
  };
} // namespace Ramen
