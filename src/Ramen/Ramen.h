#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <functional>
#include <memory>

namespace Ramen
{
  class Camera;
  class Event;
  class Renderer;
  class TextureManager;
  class TilesetManager;
  class Timer;
  class Window;

  class Ramen : public std::enable_shared_from_this<Ramen> {
    public:
      static void setErrorcallback(std::function<void(std::string)> callback);
      static void error(std::string error);

      ~Ramen();

      bool init(uint32_t sdlFlags, uint32_t imgFlags = IMG_INIT_PNG);

      std::shared_ptr<Camera> createCamera();
      std::shared_ptr<Camera> getCamera();
      std::shared_ptr<Event> createEvents();
      std::shared_ptr<Event> getEvents();
      std::shared_ptr<Renderer> createRenderer(uint32_t flags);
      std::shared_ptr<Renderer> getRenderer();
      std::shared_ptr<TextureManager> createTextureManager();
      std::shared_ptr<TextureManager> getTextureManager();
      std::shared_ptr<TilesetManager> createTilesetManager();
      std::shared_ptr<TilesetManager> getTilesetManager();
      std::shared_ptr<Timer> createTimer();
      std::shared_ptr<Timer> getTimer();
      std::shared_ptr<Window> createWindow(std::string title, int width, int height, uint32_t flags);
      std::shared_ptr<Window> getWindow();

    private:
      static std::function<void(std::string)> errorCallback;
      std::shared_ptr<Camera> camera;
      std::shared_ptr<Event> events;
      std::shared_ptr<Renderer> renderer;
      std::shared_ptr<TextureManager> textures;
      std::shared_ptr<TilesetManager> tilesets;
      std::shared_ptr<Timer> timer;
      std::shared_ptr<Window> window;
  };
} // namespace Ramen
