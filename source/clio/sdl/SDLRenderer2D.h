#pragma once

#include <map>
#include <memory>
#include <cstdint>

#include "common/Logger.h"
#include "graphics/Renderer2D.h"
#include "graphics/Texture.h"
#include "system/System.h"

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

namespace SDL {
	struct RendererDeleter {
		void operator()(SDL_Renderer* renderer) {
			if (renderer != nullptr) {
				SDL_DestroyRenderer(renderer);
			}
		}
	};

	class Renderer2D : public clio::Renderer2D {
		friend class clio::System;
	public:
		~Renderer2D();

		void ClearScreen();

		void RenderDraws();

		clio::Texture* LoadTexture(std::string texture_file);

		void FreeTexture(clio::Texture* texture);

		void DrawTexture(clio::Texture* texture, int x, int y, int w = 0, int h = 0);

		void DrawTextureClip(clio::TextureClip* texture, int x, int y, int w = 0, int h = 0);
	protected:
		Renderer2D(SDL_Window* window);

		void Initialize();
	private:
		std::unique_ptr<clio::Logger> m_log;

		std::unique_ptr<SDL_Renderer, RendererDeleter> m_renderer;

		clio::TextureID m_textureId;

		std::map<std::string, clio::Texture*> m_textures;
		std::map<clio::Texture*, SDL_Texture*> m_sdlTextures;

		SDL_Window* m_window;
	};
}