#pragma once

#include <cstdint>
#include <string>

namespace clio {
	typedef uint64_t TextureID;
	/**
	* The texture structure allows you to query information about the texture
	* itself.
	*/
	struct Texture {
	public:
		/** The ID associated with this texture.*/
		TextureID id;
		/** The width of the texture in pixels.*/
		int32_t width;
		/** The height of the texture in pixels.*/
		int32_t height;

		Texture(TextureID tid, int32_t w, int32_t h) : id(tid), width(w), height(h) {}

		bool operator<(const Texture& t) const {
			if (id < t.id) {
				return true;
			}

			return false;
		}
	};

	/**
	* A TextureClip specifies a clip region for a texture.
	*/
	struct TextureClip {
		Texture* texture;

		int32_t x;

		int32_t y;

		int32_t width;

		int32_t height;

		TextureClip(Texture* tex, int32_t xpos, int32_t ypos, int32_t w, int32_t h) :
			texture(tex), x(xpos), y(ypos), width(w), height(h) {}
	};
}