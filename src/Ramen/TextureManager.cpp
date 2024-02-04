#include "TextureManager.h"

#include "Ramen.h"
#include "Texture.h"

namespace Ramen
{
  TextureManager::TextureManager(std::shared_ptr<Ramen> ramen) : ramen(ramen) {
  }

  std::shared_ptr<Texture> TextureManager::create(std::string key, std::string path) {
    return this->textures[key] = std::make_shared<Texture>(this->ramen, path);
  }

  bool TextureManager::has(std::string key) const {
    return this->textures.count(key) > 0;
  }

  std::shared_ptr<Texture> TextureManager::get(std::string key) {
    if (!this->has(key)) {
      Ramen::error("Texture not registered: " + key);
    }
    return this->textures[key];
  }
}; // namespace Ramen
