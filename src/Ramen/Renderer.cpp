#include "Renderer.h"

#include "Camera.h"
#include "Ramen.h"
#include "Rectangle.h"
#include "Texture.h"
#include "Window.h"

namespace Ramen
{
  Renderer::Renderer(std::shared_ptr<Ramen> ramen, uint32_t flags) : ramen(ramen) {
    this->renderer = SDL_CreateRenderer(this->ramen->getWindow()->getSdlWindow(), NULL, flags);
    if (!this->renderer) {
      Ramen::error(SDL_GetError());
    }

    SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
    SDL_SetHint("SDL_MOUSE_RELATIVE_SCALING", "1");

    this->camera = this->ramen->getCamera();
  }

  Renderer::~Renderer() {
    SDL_DestroyRenderer(this->renderer);
  }

  void Renderer::clear() {
    this->setRenderColor({32, 32, 32, 255});
    SDL_RenderClear(this->renderer);
  }

  void Renderer::present() {
    SDL_RenderPresent(this->renderer);
  }

  void Renderer::setDimensions(int width, int height) {
    SDL_SetRenderLogicalPresentation(this->renderer, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX, SDL_SCALEMODE_BEST);
    this->camera->resize();
  }

  void Renderer::setRenderColor(Color color) {
    SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
  }

  SDL_Renderer *Renderer::getSdlRenderer() {
    return this->renderer;
  }

  void Renderer::render(Rectangle *rectangle, RectangleMode mode) {
    switch (mode) {
      case RectangleMode::Outline:
        SDL_RenderRect(this->renderer, this->camera->transform(rectangle).getSdlRect());
        break;
      case RectangleMode::Fill:
        SDL_RenderFillRect(this->renderer, this->camera->transform(rectangle).getSdlRect());
        break;
    }
  }

  void Renderer::render(std::shared_ptr<Rectangle> rectangle, RectangleMode mode) {
    return this->render(rectangle.get(), mode);
  }

  void Renderer::render(std::shared_ptr<Texture> texture) {
    SDL_RenderTexture(this->renderer, texture->getSdlTexture(), NULL, NULL);
  }

  void Renderer::render(std::shared_ptr<Texture> texture, Rectangle *rectangle) {
    SDL_RenderTexture(this->renderer, texture->getSdlTexture(), NULL, this->camera->transform(rectangle).getSdlRect());
  }

  void Renderer::render(std::shared_ptr<Texture> texture, Rectangle *source, Rectangle *destination) {
    SDL_RenderTexture(this->renderer, texture->getSdlTexture(), source->getSdlRect(), this->camera->transform(destination).getSdlRect());
  }

  void Renderer::render(std::shared_ptr<Texture> texture, Rectangle *source, Rectangle *destination, SDL_RendererFlip flip) {
    SDL_RenderTextureRotated(this->renderer, texture->getSdlTexture(), source->getSdlRect(), this->camera->transform(destination).getSdlRect(), 0.f,
                             destination->getCenter().getSdlPoint(), flip);
  }

  void Renderer::drawGuides(int divisions) {
    Vector2 dimensions = this->ramen->getWindow()->getDimensions();
    float xStep = dimensions.x / (divisions + 1);
    float yStep = dimensions.y / (divisions + 1);

    for (float step = xStep; step < dimensions.x; step += xStep) {
      SDL_RenderLine(this->renderer, step, 0, step, dimensions.y);
    }

    for (float step = yStep; step < dimensions.y; step += yStep) {
      SDL_RenderLine(this->renderer, 0, step, dimensions.x, step);
    }
  }

}; // namespace Ramen
