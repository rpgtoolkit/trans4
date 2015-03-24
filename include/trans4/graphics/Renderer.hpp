/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_GRAPHICS_RENDERER_INCLUDED
#define RPGTOOLKIT_TRANS4_GRAPHICS_RENDERER_INCLUDED

#include <string>

namespace rpgtoolkit {

	typedef unsigned int TextureID;
	const TextureID INVALID_TEXTURE = 0;

	struct Rectangle;

	/**
	* The Renderer interface allows for drawing textures to the screen.
	*/
	class Renderer {
		/** Only the System class can create a Renderer.*/
		friend class System;

	public:
		/**
		* Load a texture from the file specified. A TextureID will be given
		* so that it an be used with the renderer's draw functions in the
		* future. If INVALID_TEXTURE is returned then the texture was not
		* loaded successfully.
		*
		* @param texture_file The file name and path (if applicable) to the texture
		* @return An ID that the renderer will remember for this texture.
		*/
		virtual TextureID loadTexture(std::string texture_file) = 0;

		/**
		* Draw a loaded texture onto the screen at a given (x,y) coordinate.
		* If only a portion of the loaded texture is to be drawn, then a clip
		* rectangle should be specified. This is useful when drawing a tile from
		* a tileset.
		*
		* @param x The x coordinate to draw to
		* @param y The y coordinate to draw to
		* @param clip The region of the texture to be drawing. nullptr draws all of it.
		*/
		virtual void drawTexture(TextureID textureId, int x, int y, Rectangle* clip = nullptr) = 0;

		/**
		* Clear the screen of all past renders.
		*/
		virtual void clearScreen() = 0;

		/**
		* Send all draw calls that have been issued since the last clearScreen() to
		* the screen.
		*/
		virtual void renderScreen() = 0;

		virtual ~Renderer() {}

		/**
		* No copying allowed.
		*/
		Renderer(Renderer const&) = delete;

		/**
		* No copying allowed.
		*/
		Renderer & operator=(Renderer const&) = delete;
	protected:
		Renderer() {}

		virtual void initialize() = 0;
	};
}

#endif
