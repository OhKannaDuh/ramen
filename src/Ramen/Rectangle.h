#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <SDL3/SDL_rect.h>
#include <memory>

namespace Ramen
{
  class Rectangle {
    public:
      static Eigen::AlignedBox2f createBoxFromDimensions(Eigen::Vector2f origin, Eigen::Vector2f dimensions) {
        return {origin, origin + dimensions};
      }

      static Eigen::AlignedBox2f createBoxFromDimensions(float x, float y, float w, float h) {
        return Rectangle::createBoxFromDimensions(Eigen::Vector2f(x, y), Eigen::Vector2f(w, h));
      }
      static Eigen::AlignedBox2i createBoxFromDimensions(Eigen::Vector2i origin, Eigen::Vector2i dimensions) {
        return {origin, origin + dimensions};
      }

      static Eigen::AlignedBox2i createBoxFromDimensions(int x, int y, int w, int h) {
        return Rectangle::createBoxFromDimensions(Eigen::Vector2i(x, y), Eigen::Vector2i(w, h));
      }

      static SDL_FRect getSdlRect(Eigen::AlignedBox2f box) {
        return {box.min()[0], box.min()[1], box.sizes()[0], box.sizes()[1]};
      }

      static SDL_Rect getSdlRect(Eigen::AlignedBox2i box) {
        return {box.min()[0], box.min()[1], box.sizes()[0], box.sizes()[1]};
      }

      static void moveTo(std::shared_ptr<Eigen::AlignedBox2f> box, Eigen::Vector2f destination) {
        destination -= box->min();
        box->translate(destination);
      }

      static void moveTo(std::shared_ptr<Eigen::AlignedBox2f> box, float x, float y) {
        Rectangle::moveTo(box, Eigen::Vector2f(x, y));
      }

      static void moveTo(Eigen::AlignedBox2f *box, Eigen::Vector2f destination) {
        destination -= box->min();
        box->translate(destination);
      }

      static void moveTo(Eigen::AlignedBox2f *box, float x, float y) {
        Rectangle::moveTo(box, Eigen::Vector2f(x, y));
      }
  };
} // namespace Ramen
