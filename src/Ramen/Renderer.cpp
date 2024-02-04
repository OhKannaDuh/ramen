#include "Renderer.h"

#include "Camera.h"
#include "Color.h"
#include "Ramen.h"
#include "Texture.h"
#include "Window.h"

#include <iostream>

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
    this->setRenderColor(Colors::clear);
    SDL_RenderClear(this->renderer);
  }

  void Renderer::present() {
    SDL_RenderPresent(this->renderer);
  }

  void Renderer::setRenderColor(Color color) {
    SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
  }

  void Renderer::setDimensions(int width, int height) {
    SDL_SetRenderLogicalPresentation(this->renderer, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX, SDL_SCALEMODE_BEST);
    this->camera->resize();
  }

  SDL_Renderer *Renderer::getSdlRenderer() {
    return this->renderer;
  }

  void Renderer::render(RenderPayload payload) {
    payload.render(this);
  }

  std::shared_ptr<Camera> Renderer::getCamera() const {
    return this->camera;
  }
}; // namespace Ramen
