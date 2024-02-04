#include "Window.h"

#include "Ramen.h"
#include "Renderer.h"

namespace Ramen
{
  Window::Window(std::shared_ptr<Ramen> ramen, std::string title, int width, int height, uint32_t flags) : ramen(ramen) {
    this->window = SDL_CreateWindow(title.c_str(), width, height, flags);
    if (!this->window) {
      Ramen::error(SDL_GetError());
    }
  }

  Window::~Window() {
    SDL_DestroyWindow(this->window);
  }

  Eigen::Vector2f Window::getDimensions() {
    int width;
    int height;

    SDL_GetRenderLogicalPresentation(this->ramen->getRenderer()->getSdlRenderer(), &width, &height, nullptr, nullptr);

    return {(float)width, (float)height};
  }

  SDL_Window *Window::getSdlWindow() {
    return this->window;
  }
}; // namespace Ramen
