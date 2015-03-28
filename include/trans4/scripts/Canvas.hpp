/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_CANVAS_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_CANVAS_INCLUDED

#include <cstdint>
#include <memory>

namespace clio {
	struct Texture;
	struct TextureClip;
	struct Renderer2D;
}

namespace rpgtoolkit {
	struct Canvas {
	public:
		Canvas(clio::Renderer2D* renderer, size_t width, size_t height);

		~Canvas();

		void Render();

		void DrawTexture(clio::Texture *texture, int x, int y, int w = 0, int h = 0);

		void DrawTextureClip(clio::TextureClip *texture, int x, int y, int w = 0, int h = 0);

		void DrawPixel(int x, int y);

		void DrawLine(int x1, int y1, int x2, int y2);

		void DrawRect(int x, int y, int width, int height);

		void FillRect(int x, int y, int width, int height);

		Canvas(Canvas const&);

		Canvas & operator=(Canvas const&);
	private:		
		clio::Renderer2D* renderer_;

		std::unique_ptr<clio::Texture> texture_;
	};
}

#endif