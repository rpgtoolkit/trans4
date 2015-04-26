/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_GRAPHICS_TEXTURECACHE_INCLUDED
#define RPGTOOLKIT_TRANS4_GRAPHICS_TEXTURECACHE_INCLUDED

#include <SDL.h>

#include <memory>
#include <string>
#include <unordered_map>

#include "graphics/Texture.hpp"

namespace rpgtoolkit {

	struct TextureCache {
		TextureCache(SDL_Renderer & renderer);

		virtual ~TextureCache();

		/// Load a texture from the file specified. The texture will be cached until it
		/// is unloaded by all who hold a reference to it.
		///
		/// \param texture_file The file name and path (if applicable) to the texture.
		/// \return The loaded texture.
		Texture const & LoadFromFile(std::string const & texture_file);

		/// Indicate that the texture is no longer needed. If the number of references
		/// to this texture is 0, the texture will be removed from the cache.
		///
		/// \param texture The texture to unload
		virtual void Unload(Texture const & texture);
	private:
		SDL_Renderer & renderer_;

		struct TextureDeleter {
			void operator()(SDL_Texture * handle) {
				SDL_DestroyTexture(handle);
			}
		};

		struct CachedTexture {
		public:
			std::unique_ptr<SDL_Texture, TextureDeleter> sdl_texture_;
			Texture texture_;
			int sharers_;

			CachedTexture(SDL_Texture* tex) : sdl_texture_(tex), sharers_(0) {}
		};

		TextureID texture_id_;

		std::unordered_map<TextureID, CachedTexture*> textures_;

		std::unordered_map<std::string, TextureID> id_from_file_;
	};
}

#endif