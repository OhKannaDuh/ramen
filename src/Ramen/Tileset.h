#pragma once

#include <Eigen/Geometry>
#include <memory>

namespace Ramen
{
  class Texture;

  class Tileset {
    public:
      Tileset(std::shared_ptr<Texture> texture, int width, int height);
      Eigen::AlignedBox2i get(int id);
      std::shared_ptr<Texture> getTexture() const;
      int getWidthInTiles() const;
      int getHeightInTiles() const;

    private:
      std::shared_ptr<Texture> texture;
      int width;      // In tiles
      int height;     // In tiles
      int tileWidth;  // In pixels
      int tileHeight; // In pixels
  };
} // namespace Ramen
