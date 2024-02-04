#pragma once

#include "Color.h"
#include "RectangleMode.h"
#include "RenderPayload.h"
#include <Eigen/Core>
#include <SDL3/SDL.h>
#include <memory>

namespace Ramen
{
  class Ramen;
  class Camera;

  class Renderer {
    public:
      Renderer(std::shared_ptr<Ramen> ramen, uint32_t flags);
      ~Renderer();
      void clear();
      void present();
      void setRenderColor(Color color);
      void setDimensions(int width, int height);
      SDL_Renderer *getSdlRenderer();

      void render(RenderPayload payload);
      std::shared_ptr<Camera> getCamera() const;

    private:
      std::shared_ptr<Ramen> ramen;
      SDL_Renderer *renderer;
      std::shared_ptr<Camera> camera;
  };
} // namespace Ramen
