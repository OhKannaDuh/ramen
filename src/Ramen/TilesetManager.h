#pragma once

#include <map>
#include <memory>
#include <string>

namespace Ramen
{
  class Ramen;
  class Tileset;

  class TilesetManager {
    public:
      TilesetManager(std::shared_ptr<Ramen> ramen);
      std::shared_ptr<Tileset> create(std::string key, std::string texture, int width, int height);
      bool has(std::string key) const;
      std::shared_ptr<Tileset> get(std::string key);

    private:
      std::shared_ptr<Ramen> ramen;
      std::map<std::string, std::shared_ptr<Tileset>> tilesets;
  };
} // namespace Ramen
