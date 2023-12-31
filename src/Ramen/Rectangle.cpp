#include "Rectangle.h"

namespace Ramen
{
  Rectangle::Rectangle(float x, float y, float w, float h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
  }

  Rectangle::Rectangle(int x, int y, int w, int h) : Rectangle((float)x, (float)y, (float)w, (float)h) {
  }

  bool Rectangle::contains(Vector2 *point) {
    return SDL_PointInRectFloat(point->getSdlPoint(), this->getSdlRect());
    if (point->x < this->x || point->x > this->x + this->w) {
      return false;
    }

    if (point->y < this->y || point->y > this->y + this->y) {
      return false;
    }

    return true;
  }

  bool Rectangle::intersects(Rectangle *other) {
    return SDL_HasRectIntersectionFloat(other->getSdlRect(), this->getSdlRect());
  }

  Rectangle Rectangle::getIntersection(Rectangle *other) {
    SDL_FRect intersection;
    SDL_GetRectIntersectionFloat(other->getSdlRect(), this->getSdlRect(), &intersection);

    return {intersection.x, intersection.y, intersection.w, intersection.h};
  }

  Vector2 Rectangle::getCenter() {
    return {this->x + (this->w / 2.f), this->y + (this->h / 2.f)};
  }

  SDL_FRect *Rectangle::getSdlRect() {
    this->rect = {this->x, this->y, this->w, this->h};
    return &this->rect;
  }
}; // namespace Ramen
