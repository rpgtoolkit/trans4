#pragma once

namespace tk4 {
	class Renderer {
		friend class System;

	public:
		virtual void clearScreen() = 0;

		virtual void draw(int x, int y, int textureId, int clipId) = 0;

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