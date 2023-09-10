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
  class Renderer;

  class Ramen : public std::enable_shared_from_this<Ramen> {
    public:
      static void setErrorcallback(std::function<void(std::string)> callback);
      static void error(std::string error);

      bool init(uint32_t flags);

      std::shared_ptr<Window> createWindow(std::string title, int width, int height, uint32_t flags);
      std::shared_ptr<Window> getWindow();
      std::shared_ptr<Renderer> createRenderer(std::string name, uint32_t flags);
      std::shared_ptr<Renderer> getRenderer();

    private:
      bool initialised = false;
      std::shared_ptr<Window> window;
      std::shared_ptr<Renderer> renderer;
      static std::function<void(std::string)> errorCallback;
  };
} // namespace Ramen
