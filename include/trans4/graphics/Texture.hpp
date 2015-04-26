/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_GRAPHICS_TEXTURE_INCLUDED
#define RPGTOOLKIT_TRANS4_GRAPHICS_TEXTURE_INCLUDED

#include <cstdint>
#include <memory>
#include <string>

namespace rpgtoolkit {
	typedef uint32_t TextureID;

	enum class TextureType : int {
		UNKNOWN,
		STATIC,		///< Texture data changes rarely (or never)
		STREAMING,	///< Texture data changes frequently
		TARGET		///< Texture can be rendered to off the screen
	};

	struct Texture {
	public:
		static const TextureID INVALID_ID = 0;

		Texture() : id(INVALID_ID), width(0), height(0), type(TextureType::UNKNOWN) {}

		virtual ~Texture() {}

		TextureID id;

		int width;

		int height;

		TextureType type;		
	};
}

#endif