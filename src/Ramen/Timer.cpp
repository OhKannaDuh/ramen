#include "Timer.h"

namespace Ramen
{
  void Timer::start() {
    this->current = this->getTime();
  }

  double Timer::getDelta() {
    this->previous = this->current;
    this->current = this->getTime();

    return (double)(this->current - this->previous) / 1000.f;

    // return (double)(this->current - this->previous) * 1000 / this->getFrequency();
    // return (double)(this->current - this->previous);
  }

  int Timer::add(uint32_t interval, SDL_TimerCallback callback, void *param) {
    return SDL_AddTimer(interval, callback, param);
  }

  uint32_t Timer::getTime() {
    return SDL_GetTicks();
  }

}; // namespace Ramen
