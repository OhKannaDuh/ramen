#pragma once

#include <map>
#include <memory>
#include <string>

namespace Ramen
{
  class Ramen;
  class Texture;

  class TextureManager {
    public:
      TextureManager(std::shared_ptr<Ramen> ramen);
      std::shared_ptr<Texture> create(std::string key, std::string path);
      bool has(std::string key) const;
      std::shared_ptr<Texture> get(std::string key);

    private:
      std::shared_ptr<Ramen> ramen;
      std::map<std::string, std::shared_ptr<Texture>> textures;
  };
} // namespace Ramen
