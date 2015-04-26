#include <SDL_image.h>

#include "common/Exception.hpp"
#include "graphics/TextureCache.hpp"

namespace rpgtoolkit {
	TextureCache::TextureCache(SDL_Renderer & renderer) : renderer_(renderer), texture_id_(Texture::INVALID_ID + 1) {
	}

	TextureCache::~TextureCache() {
		//TODO Cleanup
	}

	Texture const & TextureCache::LoadFromFile(std::string const & texture_file) {
		//Make sure the texture doesn't already exist
		auto exists = id_from_file_.find(texture_file);
		if (exists != id_from_file_.end()) {

			//If there are sharers, the texture is still in the cache
			if (textures_[exists->second]->sharers_ > 0) {
				//Add a new sharer
				textures_[exists->second]->sharers_++;

				return textures_[exists->second]->texture_;
			}
		}

		//Load the texture
		SDL_Texture * tex = IMG_LoadTexture(&renderer_, texture_file.c_str());
		if (tex == nullptr) {
			throw Exception(SDL_GetError());
		}

		//Add the filename-to-ID mapping
		id_from_file_[texture_file] = texture_id_;

		//Create the cached texture
		CachedTexture * cached_texture = new CachedTexture(tex);
		cached_texture->sharers_ = 1;

		//Update the texture struct's ID, width, height, and type
		SDL_QueryTexture(tex, nullptr, nullptr, &cached_texture->texture_.width, &cached_texture->texture_.height);
		cached_texture->texture_.id = texture_id_;
		cached_texture->texture_.type = TextureType::STATIC; //Assuming IMG_LoadTexture created a static texture

		//Save reference to CachedTexture
		textures_[texture_id_] = cached_texture;

		//Increment ID for the next load
		texture_id_++;

		return cached_texture->texture_;
	}

	void TextureCache::Unload(Texture const & texture) {
		auto exists = textures_.find(texture.id);
		if (exists != textures_.end()) {
			exists->second->sharers_--;

			if (exists->second->sharers_ == 0) {
				textures_.erase(exists);
			}
		}
		else {
			//Log
		}
	}
}