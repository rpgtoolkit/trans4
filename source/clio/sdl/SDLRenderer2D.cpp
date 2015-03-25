#include <SDL_image.h>

#include "common/Exception.hpp"
#include "graphics/Texture.hpp"
#include "SDL.hpp"
#include "SDLRenderer2D.hpp"

namespace SDL {
	Renderer2D::Renderer2D(SDL_Window* window) : log_(new clio::Logger(clio::System::LOG)),
		renderer_(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)), texture_id_(0) {
	}

	Renderer2D::~Renderer2D() {
		for (auto& t : sdl_textures_) {
			delete t.first; //clio texture
			SDL_DestroyTexture(t.second);
		}
	}

	void Renderer2D::Initialize() {
		if (renderer_ == nullptr) {
			LOG(log_.get(), "%s", SDL_GetError());

			throw clio::Exception("Could not create renderer.");
		} else {
			LOG(log_.get(), "Renderer created.");
		}
	}

	void Renderer2D::ClearScreen() {
		SDL_RenderClear(renderer_.get());
	}

	void Renderer2D::RenderDraws() {
		SDL_RenderPresent(renderer_.get());
	}

	clio::Texture* Renderer2D::LoadTexture(std::string texture_file) {
		//Make sure the texture hasn't already been loaded
		auto exists = textures_.find(texture_file);
		if (exists != textures_.end()) {
			return exists->second;
		}

		//Attempt to load the texture
		SDL_Texture *tex = IMG_LoadTexture(renderer_.get(), texture_file.c_str());
		if (tex == nullptr){
			LOG(log_.get(), "%s", SDL_GetError());

			return nullptr;
		}

		//Retrieve information about the texture
		int w, h;
		SDL_QueryTexture(tex, nullptr, nullptr, &w, &h);

		//Create clio::Texture object
		clio::Texture* texture = new clio::Texture(texture_id_, w, h);

		//Save references to both clio::Texture and SDL's texture
		textures_[texture_file] = texture;
		sdl_textures_[texture] = tex;

		return texture;
	}

	void Renderer2D::FreeTexture(clio::Texture* texture) {
		//Remove the SDL Texture from memory and map
		auto exists = sdl_textures_.find(texture);
		if (exists != sdl_textures_.end()) {
			SDL_DestroyTexture(exists->second);
			sdl_textures_.erase(exists);
		}

		//Remove the clio Texture from map
		for (auto& t : textures_) {
			if (t.second->id == texture->id) {
				textures_.erase(t.first);
				break;
			}
		}

		//Delete Texture pointer
		delete texture;
	}

	void Renderer2D::DrawTexture(clio::Texture* texture, int x, int y, int w, int h) {
		SDL_Texture *tex = sdl_textures_[texture];
		if (tex == nullptr) {
			return;
		}

		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		if (w == 0 || h == 0) {
			dest.w = texture->width;
			dest.h = texture->height;
		}
		else {
			//Stretch or compress according to given width and height
			dest.w = w;
			dest.h = h;
		}

		SDL_RenderCopy(renderer_.get(), tex, nullptr, &dest);
	}

	void Renderer2D::DrawTextureClip(clio::TextureClip* textureClip, int x, int y, int w, int h) {
		SDL_Texture *tex = sdl_textures_[textureClip->texture];
		if (tex == nullptr) {
			return;
		}

		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		if (w == 0 || h == 0) {
			dest.w = textureClip->width;
			dest.h = textureClip->height;
		}
		else {
			//Stretch or compress according to given width and height
			dest.w = w;
			dest.h = h;
		}

		SDL_Rect src;
		src.x = textureClip->x;
		src.y = textureClip->y;
		src.w = textureClip->width;
		src.h = textureClip->height;

		SDL_RenderCopy(renderer_.get(), tex, &src, &dest);
	}
}