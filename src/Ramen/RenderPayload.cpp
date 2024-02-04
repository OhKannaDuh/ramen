#include "RenderPayload.h"

#include "Camera.h"
#include "Rectangle.h"
#include "Renderer.h"
#include "Texture.h"

#include <iostream>

namespace Ramen
{
  void RenderPayload::render(Renderer *renderer) {
    if (this->mode == RenderMode::Texture) {
      this->renderTexture(renderer);
    }

    if (this->mode == RenderMode::Point) {
      this->renderPoint(renderer);
    }

    if (this->mode == RenderMode::Rectangle) {
      this->renderRectangle(renderer);
    }

    if (this->mode == RenderMode::Line) {
      this->renderLine(renderer);
    }
  }

  void RenderPayload::renderTexture(Renderer *renderer) {

    // if (payload has textureMod)
    //   SDL_SetTextureColorMod

    bool hasSource = false;
    SDL_FRect source;
    if (this->source != nullptr) {
      hasSource = true;

      source = Rectangle::getSdlRect(*this->source);
    }

    bool hasDestination = false;
    SDL_FRect destination;
    if (this->destination != nullptr) {
      hasDestination = true;

      Eigen::AlignedBox2f box = renderer->getCamera()->transform(*this->destination);
      destination = Rectangle::getSdlRect(box);
    }

    if (this->flip == SDL_FLIP_NONE) {
      SDL_RenderTexture(                       //
          renderer->getSdlRenderer(),          //
          this->texture->getSdlTexture(),      //
          hasSource ? &source : NULL,          //
          hasDestination ? &destination : NULL //
      );

      return;
    }

    SDL_RenderTextureRotated(                 //
        renderer->getSdlRenderer(),           //
        this->texture->getSdlTexture(),       //
        hasSource ? &source : NULL,           //
        hasDestination ? &destination : NULL, //
        0.0f,                                 //
        NULL,                                 //
        this->flip                            //
    );
  }

  void RenderPayload::renderPoint(Renderer *renderer) {
    Eigen::Vector2f point = renderer->getCamera()->transform(this->point);
    point /= scale;

    SDL_SetRenderScale(renderer->getSdlRenderer(), scale, scale);
    SDL_RenderPoint(renderer->getSdlRenderer(), point.x(), point.y());
    SDL_SetRenderScale(renderer->getSdlRenderer(), 1.0f, 1.0f);
  }

  void RenderPayload::renderRectangle(Renderer *renderer) {
    Eigen::AlignedBox2f box = renderer->getCamera()->transform(this->rectangle);
    SDL_FRect rectangle = Rectangle::getSdlRect(box);

    switch (this->rectangleMode) {
      case RectangleMode::Outline:
        SDL_RenderRect(renderer->getSdlRenderer(), &rectangle);
        break;
      case RectangleMode::Fill:
        SDL_RenderFillRect(renderer->getSdlRenderer(), &rectangle);
        break;
    }
  }

  void RenderPayload::renderLine(Renderer *renderer) {
    Eigen::Vector2f a = renderer->getCamera()->transform(this->linePoints.first);
    Eigen::Vector2f b = renderer->getCamera()->transform(this->linePoints.second);

    SDL_RenderLine(renderer->getSdlRenderer(), a.x(), a.y(), b.x(), b.y());
  }

  // Texture
  void RenderPayload::setTexture(std::shared_ptr<Texture> texture) {
    this->mode = RenderMode::Texture;
    this->texture = texture;
  }

  void RenderPayload::setSource(std::shared_ptr<Eigen::AlignedBox2f> source) {
    this->source = source;
  }

  void RenderPayload::setDestination(std::shared_ptr<Eigen::AlignedBox2f> destination) {
    this->destination = destination;
  }

  void RenderPayload::setFlip(SDL_FlipMode flip) {
    this->flip = flip;
  }

  // Point
  void RenderPayload::setPoint(Eigen::Vector2f point) {
    this->mode = RenderMode::Point;
    this->point = point;
  }

  void RenderPayload::setScale(float scale) {
    this->scale = scale;
  }

  // Rectangle
  void RenderPayload::setRectangle(Eigen::AlignedBox2f rectangle) {
    this->mode = RenderMode::Rectangle;
    this->rectangle = rectangle;
  }

  void RenderPayload::setRectangleMode(RectangleMode mode) {
    this->rectangleMode = mode;
  }

  // Line

  void RenderPayload::setLinePoints(Eigen::Vector2f a, Eigen::Vector2f b) {
    this->mode = RenderMode::Line;
    this->linePoints.first = a;
    this->linePoints.second = b;
  }
}; // namespace Ramen
