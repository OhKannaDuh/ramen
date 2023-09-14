#pragma once

#include <functional>
#include <memory>
#include <stdexcept>
#include <stdint.h>
#include <string>

static void ramen_error(std::string error) {
  throw std::runtime_error(error);
}

namespace Ramen
{
  class Window;
  class Camera;
  class Renderer;
  class Event;
  class TextureManager;
  class JoystickManager;
  class Timer;

  class Ramen : public std::enable_shared_from_this<Ramen> {
    public:
      static void setErrorcallback(std::function<void(std::string)> callback);
      static void error(std::string error);

      bool init(uint32_t flags);

      std::shared_ptr<Window> createWindow(std::string title, int width, int height, uint32_t flags);
      std::shared_ptr<Window> getWindow();
      std::shared_ptr<Camera> createCamera();
      std::shared_ptr<Camera> getCamera();
      std::shared_ptr<Renderer> createRenderer(uint32_t flags);
      std::shared_ptr<Renderer> getRenderer();
      std::shared_ptr<Event> createEvents();
      std::shared_ptr<Event> getEvents();
      std::shared_ptr<TextureManager> createTextureManager();
      std::shared_ptr<TextureManager> getTextureManager();
      std::shared_ptr<JoystickManager> createJoystickManager();
      std::shared_ptr<JoystickManager> getJoystickManager();
      std::shared_ptr<Timer> createTimer();
      std::shared_ptr<Timer> getTimer();

    private:
      std::shared_ptr<Window> window;
      std::shared_ptr<Camera> camera;
      std::shared_ptr<Renderer> renderer;
      std::shared_ptr<Event> events;
      std::shared_ptr<TextureManager> textures;
      std::shared_ptr<JoystickManager> joysticks;
      std::shared_ptr<Timer> timer;
      static std::function<void(std::string)> errorCallback;
  };
} // namespace Ramen
