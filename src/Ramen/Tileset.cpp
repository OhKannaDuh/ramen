#include "Tileset.h"

#include "Texture.h"
#include <cmath>

namespace Ramen
{
  Tileset::Tileset(std::shared_ptr<Texture> texture, int width, int height) : texture(texture), width(width), height(height) {
    this->tileWidth = this->texture->getWidth() / this->width;
    this->tileHeight = this->texture->getHeight() / this->height;
  }

  Rectangle Tileset::get(int id) {
    int x = id % this->width;
    int y = std::floor(id / this->width);

    return {x * this->tileWidth, y * this->tileHeight, this->tileWidth, this->tileHeight};
  }

  std::shared_ptr<Texture> Tileset::getTexture() const {
    return this->texture;
  }
}; // namespace Ramen
