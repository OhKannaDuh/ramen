#include "Ramen.h"

#include "Renderer.h"
#include "Window.h"
#include <SDL3/SDL.h>

std::function<void(std::string)> Ramen::Ramen::errorCallback = ramen_error;

namespace Ramen
{
  void Ramen::setErrorcallback(std::function<void(std::string)> callback) {
    Ramen::errorCallback = callback;
  }

  void Ramen::error(std::string error) {
    Ramen::errorCallback(error);
  }

  bool Ramen::init(uint32_t flags) {
    if (SDL_Init(flags) != 0) {
      Ramen::error(SDL_GetError());
      return false;
    }

    this->initialised = true;
    return true;
  }

  std::shared_ptr<Window> Ramen::createWindow(std::string title, int width, int height, uint32_t flags) {
    if (!this->initialised) {
      Ramen::error("Cannot create window Ramen has not been initialised");
    }

    return this->window = std::make_shared<Window>(shared_from_this(), title, width, height, flags);
  }

  std::shared_ptr<Window> Ramen::getWindow() {
    return this->window;
  }

  std::shared_ptr<Renderer> Ramen::createRenderer(std::string name, uint32_t flags) {
    return this->renderer = std::make_shared<Renderer>(shared_from_this(), name, flags);
  }

  std::shared_ptr<Renderer> Ramen::getRenderer() {
    return this->renderer;
  }

}; // namespace Ramen
