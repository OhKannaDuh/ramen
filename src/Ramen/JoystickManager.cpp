#include "JoystickManager.h"

#include <SDL3/SDL.h>

namespace Ramen
{

  JoystickManager::JoystickManager(std::shared_ptr<Ramen> ramen) : ramen(ramen) {
  }

  void JoystickManager::add(uint32_t id) {
    this->count++;
    this->assignment[id] = -1;
  }

  void JoystickManager::remove(uint32_t id) {
    this->count--;
    this->assignment.erase(id);
  }

  int JoystickManager::getCount() const {
    return this->count;
  }

  std::map<uint32_t, int> JoystickManager::getAssignment() const {
    return this->assignment;
  }

}; // namespace Ramen
