#pragma once

#include <string>

namespace clio {
	struct Texture;
	struct TextureClip;

	class Renderer2D {
		friend class System;
	public:		
		/// Destructor.		
		virtual ~Renderer2D() {}
		
		/// Clear the screen.		
		virtual void ClearScreen() = 0;
		
		/// Render all draw calls since the last ClearScreen		
		virtual void RenderDraws() = 0;
		
		/// Load a texture from the file specified. The texture will be cached by the
		/// renderer for future use, or until freeTexture is called.
		///
		/// \param texture_file The file name and path (if applicable) to the texture.
		/// \return The loaded texture.		
		virtual Texture* LoadTexture(std::string texture_file) = 0;
		
		/// Remove a texture from the renderer's cache, freeing up memory.
		///
		/// \param texture The texture to be freed.		
		virtual void FreeTexture(Texture* texture) = 0;
		
		/// Draw the texture at an (x, y) location on the screen with a specified
		/// width and height. If 0 it defaults to the texture's original width and
		/// height
		///
		/// \param x The x coordinate to draw to
		/// \param y The y coordinate to draw to
		/// \param w The width of the drawn texture
		/// \param h The height to drawn texture		
		virtual void DrawTexture(Texture* texture, int x, int y, int w = 0, int h = 0) = 0;
		
		/// Draw the texture clip at an (x, y) location on the screen with a 
		/// specified width and height. If 0 it defaults to the clip's width
		/// and height.
		///
		/// \param x The x coordinate to draw to
		/// \param y The y coordinate to draw to
		/// \param w The width of the drawn texture
		/// \param h The height to drawn texture		
		virtual void DrawTextureClip(TextureClip* texture, int x, int y, int w = 0, int h = 0) = 0;
		
		/// No copying allowed.		
		Renderer2D(Renderer2D const&) = delete;
		
		/// No copying allowed.		
		Renderer2D & operator=(Renderer2D const&) = delete;
	protected:		
		/// Constructor.		
		Renderer2D() {}

		virtual void Initialize() = 0;
	};
}