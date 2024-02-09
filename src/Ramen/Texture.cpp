#include "Texture.h"

#include "Ramen.h"
#include "Rectangle.h"
#include "Renderer.h"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>

#include <iostream>

namespace Ramen
{
  Texture::Texture(std::shared_ptr<Ramen> ramen, std::string path) : ramen(ramen) {
    SDL_Surface *image = IMG_Load(path.c_str());
    if (!image) {
      Ramen::error(SDL_GetError());
    }

    this->texture = SDL_CreateTextureFromSurface(ramen->getRenderer()->getSdlRenderer(), image);
    if (!this->texture) {
      Ramen::error(SDL_GetError());
    }

    SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height);

    SDL_DestroySurface(image);
  }

  Texture::Texture(std::shared_ptr<Ramen> ramen, int width, int height) : ramen(ramen), width(width), height(height) {
    this->texture = SDL_CreateTexture(ramen->getRenderer()->getSdlRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    if (!this->texture) {
      Ramen::error(SDL_GetError());
    }
  }

  void Texture::target() {
    SDL_SetRenderTarget(this->ramen->getRenderer()->getSdlRenderer(), this->texture);
  }

  void Texture::untarget() {
    SDL_SetRenderTarget(this->ramen->getRenderer()->getSdlRenderer(), NULL);
  }

  void Texture::update(std::shared_ptr<Texture> texture, Eigen::AlignedBox2i source, Eigen::AlignedBox2i destination) {

    SDL_SetTextureBlendMode(this->getSdlTexture(), SDL_BLENDMODE_BLEND);

    SDL_Rect sourceRect = Rectangle::getSdlRect(source);
    SDL_Rect destinationRect = Rectangle::getSdlRect(destination);

    SDL_FRect sRect = {sourceRect.x, sourceRect.y, sourceRect.w, sourceRect.h};
    SDL_FRect dRect = {destinationRect.x, destinationRect.y, destinationRect.w, destinationRect.h};

    SDL_RenderTexture(this->ramen->getRenderer()->getSdlRenderer(), texture->getSdlTexture(), &sRect, &dRect);
  }

  SDL_Texture *Texture::getSdlTexture() const {
    return this->texture;
  }

  int Texture::getWidth() const {
    return this->width;
  }

  int Texture::getHeight() const {
    return this->height;
  }

}; // namespace Ramen
