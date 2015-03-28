#include "clio/graphics/Renderer2D.hpp"
#include "clio/graphics/Texture.hpp"

#include "scripts/Canvas.hpp"

namespace rpgtoolkit {
	Canvas::Canvas(clio::Renderer2D* renderer, size_t width, size_t height) : 
		renderer_(renderer), texture_(renderer_->CreateTarget(width, height)) {
	}

	Canvas::~Canvas() {
	}

	Canvas::Canvas(Canvas const& obj) : 
		renderer_(obj.renderer_), 
		texture_(renderer_->CreateTarget(obj.texture_->GetWidth(), obj.texture_->GetHeight())) {
	}

	Canvas & Canvas::operator=(Canvas const& rhs) {
		Canvas temp(rhs);
		std::swap(*this, temp);

		return *this;
	}

	void Canvas::Render(int x, int y) {
		renderer_->DrawTexture(texture_.get(), x, y);
	}

	void Canvas::DrawTexture(clio::Texture *texture, int x, int y, int w, int h) {
		renderer_->SetTarget(texture_.get());
		renderer_->DrawTexture(texture, x, y, w, h);
		renderer_->SetTarget(nullptr);
	}

	void Canvas::DrawTextureClip(clio::Texture* tex, int x, int y, int source_x, int source_y, int width, int height) {
		renderer_->SetTarget(texture_.get());
		clio::TextureClip clip(tex, source_x, source_y, width, height);
		renderer_->DrawTextureClip(&clip, x, y, width, height);
		renderer_->SetTarget(nullptr);
	}

	void Canvas::DrawPixel(int x, int y) {
		renderer_->SetTarget(texture_.get());
		renderer_->DrawPixel(x, y);
		renderer_->SetTarget(nullptr);
	}

	void Canvas::DrawLine(int x1, int y1, int x2, int y2) {
		renderer_->SetTarget(texture_.get());
		renderer_->DrawLine(x1, y1, x2, y2);
		renderer_->SetTarget(nullptr);
	}

	void Canvas::DrawRect(int x, int y, int width, int height) { 
		renderer_->SetTarget(texture_.get());
		renderer_->DrawRect(x, y, width, height);
		renderer_->SetTarget(nullptr);
	}

	void Canvas::FillRect(int x, int y, int width, int height) {
		renderer_->SetTarget(texture_.get());
		renderer_->FillRect(x, y, width, height);
		renderer_->SetTarget(nullptr);
	}
}