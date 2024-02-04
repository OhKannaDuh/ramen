#include "TilesetManager.h"

#include "Ramen.h"
#include "TextureManager.h"
#include "Tileset.h"

#include <iostream>

namespace Ramen
{
  TilesetManager::TilesetManager(std::shared_ptr<Ramen> ramen) : ramen(ramen) {
  }

  std::shared_ptr<Tileset> TilesetManager::create(std::string key, std::string texture, int width, int height) {
    return this->tilesets[key] = std::make_shared<Tileset>(this->ramen->getTextureManager()->get(texture), width, height);
  }

  bool TilesetManager::has(std::string key) const {
    return this->tilesets.count(key) > 0;
  }

  std::shared_ptr<Tileset> TilesetManager::get(std::string key) {
    if (!this->has(key)) {
      Ramen::error("Tileset not registered: " + key);
    }

    return this->tilesets[key];
  }
}; // namespace Ramen
