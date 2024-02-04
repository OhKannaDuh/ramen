#pragma once

#include <map>
#include <memory>

namespace Ramen
{
  class Ramen;

  class JoystickManager {
    public:
      JoystickManager(std::shared_ptr<Ramen> ramen);
      void add(uint32_t id);
      void remove(uint32_t id);
      int getCount() const;
      std::map<uint32_t, int> getAssignment() const;

    private:
      std::shared_ptr<Ramen> ramen;
      int count = 0;
      std::map<uint32_t, int> assignment;
  };
} // namespace Ramen
