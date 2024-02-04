#include "Ramen.h"

#include "Camera.h"
#include "Event.h"
#include "Renderer.h"
#include "TextureManager.h"
#include "TilesetManager.h"
#include "Timer.h"
#include "Window.h"
#include <SDL3/SDL.h>

static void ramen_error(std::string error) {
  throw std::runtime_error(error);
}

std::function<void(std::string)> Ramen::Ramen::errorCallback = ramen_error;

namespace Ramen
{
  void Ramen::setErrorcallback(std::function<void(std::string)> callback) {
    Ramen::errorCallback = callback;
  }

  void Ramen::error(std::string error) {
    Ramen::errorCallback(error);
  }

  Ramen::~Ramen() {
    IMG_Quit();
    SDL_Quit();
  }

  bool Ramen::init(uint32_t sdlFlags, uint32_t imgFlags) {
    if (SDL_Init(sdlFlags) != 0) {
      Ramen::error(SDL_GetError());
      return false;
    }

    SDL_HideCursor();

    if (IMG_Init(imgFlags) != imgFlags) {
      Ramen::error(IMG_GetError());
      return false;
    }

    return true;
  }

  std::shared_ptr<Camera> Ramen::createCamera() {
    return this->camera = std::make_shared<Camera>(shared_from_this());
  }

  std::shared_ptr<Camera> Ramen::getCamera() {
    return this->camera;
  }

  std::shared_ptr<Event> Ramen::createEvents() {
    return this->events = std::make_shared<Event>(shared_from_this());
  }

  std::shared_ptr<Event> Ramen::getEvents() {
    return this->events;
  }

  std::shared_ptr<Renderer> Ramen::createRenderer(uint32_t flags) {
    return this->renderer = std::make_shared<Renderer>(shared_from_this(), flags);
  }

  std::shared_ptr<Renderer> Ramen::getRenderer() {
    return this->renderer;
  }

  std::shared_ptr<TextureManager> Ramen::createTextureManager() {
    return this->textures = std::make_shared<TextureManager>(shared_from_this());
  }
  std::shared_ptr<TextureManager> Ramen::getTextureManager() {
    return this->textures;
  }

  std::shared_ptr<TilesetManager> Ramen::createTilesetManager() {
    return this->tilesets = std::make_shared<TilesetManager>(shared_from_this());
  }

  std::shared_ptr<TilesetManager> Ramen::getTilesetManager() {
    return this->tilesets;
  }

  std::shared_ptr<Timer> Ramen::createTimer() {
    return this->timer = std::make_shared<Timer>();
  }

  std::shared_ptr<Timer> Ramen::getTimer() {
    return this->timer;
  }

  std::shared_ptr<Window> Ramen::createWindow(std::string title, int width, int height, uint32_t flags) {
    return this->window = std::make_shared<Window>(shared_from_this(), title, width, height, flags);
  }

  std::shared_ptr<Window> Ramen::getWindow() {
    return this->window;
  }
} // namespace Ramen
