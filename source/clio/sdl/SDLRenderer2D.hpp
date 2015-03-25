#pragma once

#include <map>
#include <memory>
#include <cstdint>

#include "common/Logger.hpp"
#include "graphics/Renderer2D.hpp"
#include "graphics/Texture.hpp"
#include "system/System.hpp"

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
		std::unique_ptr<clio::Logger> log_;

		std::unique_ptr<SDL_Renderer, RendererDeleter> renderer_;

		clio::TextureID texture_id_;

		std::map<std::string, clio::Texture*> textures_;

		std::map<clio::Texture*, SDL_Texture*> sdl_textures_;
	};
}