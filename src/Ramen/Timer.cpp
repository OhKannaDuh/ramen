#include "Timer.h"

#include <chrono>
#include <thread>

#include <iostream>

namespace Ramen
{
  void Timer::start() {
    this->current = this->getTime();
  }

  double Timer::getDelta() {
    this->previous = this->current;
    this->current = this->getTime();

    return (double)(this->current - this->previous) / 1000.f;
  }

  void Timer::wait(uint64_t time) {
    std::this_thread::sleep_for(std::chrono::nanoseconds(time));
  }

  int Timer::add(uint32_t interval, SDL_TimerCallback callback, void *param) {
    return SDL_AddTimer(interval, callback, param);
  }

  uint32_t Timer::getTime() {
    return SDL_GetTicks();
  }

}; // namespace Ramen
