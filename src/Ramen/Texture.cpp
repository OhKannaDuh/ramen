#include "Texture.h"

#include "Ramen.h"
#include "Renderer.h"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_surface.h>

namespace Ramen
{
  Texture::Texture(std::shared_ptr<Ramen> ramen, std::string path) : ramen(ramen) {
    SDL_Surface *image = SDL_LoadBMP(path.c_str());
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

  void Texture::update(std::shared_ptr<Texture> texture, Rectangle source, Rectangle destination) {
    SDL_RenderTexture(this->ramen->getRenderer()->getSdlRenderer(), texture->getSdlTexture(), source.getSdlRect(), destination.getSdlRect());
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
