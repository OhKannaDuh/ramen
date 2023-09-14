#pragma once

#include "Color.h"
#include <SDL3/SDL.h>
#include <memory>
#include <string>

namespace Ramen
{
  class Ramen;
  class Rectangle;
  class Texture;
  class Camera;

  enum RectangleMode {
    Outline,
    Fill,
  };

  class Renderer {
    public:
      Renderer(std::shared_ptr<Ramen> ramen, uint32_t flags);
      ~Renderer();
      void clear();
      void present();
      void setRenderColor(Color color);
      void setDimensions(int width, int height);
      SDL_Renderer *getSdlRenderer();

      void render(Rectangle *rectangle, RectangleMode mode = RectangleMode::Outline);
      void render(std::shared_ptr<Texture> texture);
      void render(std::shared_ptr<Texture> texture, Rectangle *rectangle);
      void render(std::shared_ptr<Texture> texture, Rectangle *source, Rectangle *destination);
      void render(std::shared_ptr<Texture> texture, Rectangle *source, Rectangle *destination, SDL_RendererFlip flip);

      void drawGuides(int divisions = 1);

    private:
      std::shared_ptr<Ramen> ramen;
      std::shared_ptr<Camera> camera;
      SDL_Renderer *renderer;
  };
} // namespace Ramen
