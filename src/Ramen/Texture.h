#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <SDL3/SDL.h>
#include <memory>
#include <string>

namespace Ramen
{
  class Ramen;

  class Texture {
    public:
      Texture(std::shared_ptr<Ramen> ramen, std::string path);
      Texture(std::shared_ptr<Ramen> ramen, int width, int height);
      void target();
      void untarget();
      void update(std::shared_ptr<Texture> texture, Eigen::AlignedBox2i source, Eigen::AlignedBox2i destination);
      SDL_Texture *getSdlTexture() const;
      int getWidth() const;
      int getHeight() const;

    private:
      std::shared_ptr<Ramen> ramen;
      SDL_Texture *texture;
      int width;
      int height;
  };
} // namespace Ramen
