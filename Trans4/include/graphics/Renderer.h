#pragma once

#include <string>

namespace tk4 {
	typedef int TextureID;
	const TextureID INVALID_TEXTURE = 0;

	class Renderer {
		friend class System;

	public:
		virtual void clearScreen() = 0;

		virtual TextureID loadTexture(std::string texture_file) = 0;

		virtual void drawTexture(TextureID textureId, int x, int y) = 0;

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