#include "Tileset.h"

#include "Texture.h"
#include <Eigen/Core>
#include <cmath>

#include <iostream>

namespace Ramen
{
  Tileset::Tileset(std::shared_ptr<Texture> texture, int width, int height) : texture(texture), width(width), height(height) {
    this->tileWidth = this->texture->getWidth() / this->width;
    this->tileHeight = this->texture->getHeight() / this->height;
  }

  Eigen::AlignedBox2i Tileset::get(int id) {
    int x = id % this->width;
    int y = std::floor(id / this->width);

    Eigen::Vector2i min = {x * this->tileWidth, y * this->tileHeight};
    Eigen::Vector2i dimensions = {this->tileWidth, this->tileHeight};

    return {min, min + dimensions};
  }

  std::shared_ptr<Texture> Tileset::getTexture() const {
    return this->texture;
  }
}; // namespace Ramen
