#pragma once

#include "RectangleMode.h"
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <SDL3/SDL.h>
#include <memory>
#include <utility>

namespace Ramen
{
  class Rectangle;
  class Texture;
  class Renderer;

  enum class RenderMode {
    None,
    Texture,
    Point,
    Rectangle,
    Line,
  };

  class RenderPayload {
    private:
      friend Renderer;
      void render(Renderer *renderer);
      void renderTexture(Renderer *renderer);
      void renderPoint(Renderer *renderer);
      void renderRectangle(Renderer *renderer);
      void renderLine(Renderer *renderer);

    private:
      RenderMode mode = RenderMode::None;
      // Texture
      std::shared_ptr<Texture> texture;
      std::shared_ptr<Eigen::AlignedBox2f> source;
      std::shared_ptr<Eigen::AlignedBox2f> destination;
      SDL_FlipMode flip = SDL_FLIP_NONE;
      // Point
      Eigen::Vector2f point;
      float scale = 1.0f;
      // Rectangle
      Eigen::AlignedBox2f rectangle;
      RectangleMode rectangleMode = RectangleMode::Outline;
      // Line
      std::pair<Eigen::Vector2f, Eigen::Vector2f> linePoints;

    public:
      // Texture
      void setTexture(std::shared_ptr<Texture> texture);
      void setSource(std::shared_ptr<Eigen::AlignedBox2f> source);
      void setDestination(std::shared_ptr<Eigen::AlignedBox2f> destination);
      void setFlip(SDL_FlipMode flip);
      // Point
      void setPoint(Eigen::Vector2f point);
      void setScale(float scale);
      // Rectangle
      void setRectangle(Eigen::AlignedBox2f rectangle);
      void setRectangleMode(RectangleMode mode);
      // Line
      void setLinePoints(Eigen::Vector2f a, Eigen::Vector2f b);
  };
} // namespace Ramen
