#include <SDL_image.h>

#include "common/Exception.h"
#include "graphics/Texture.h"
#include "SDL.h"
#include "SDLRenderer2D.h"

using namespace SDL;
using clio::Texture;
using clio::TextureClip;
using clio::TextureID;

Renderer2D::Renderer2D(SDL_Window* window) : m_log(new clio::Logger(clio::System::LOG)),
	m_renderer(nullptr), m_textureId(0), m_window(window) {
}

Renderer2D::~Renderer2D() {
	for (auto& t : m_sdlTextures) {
		delete t.first; //clio texture
		SDL_DestroyTexture(t.second);
	}
}

void Renderer2D::Initialize() {
	m_renderer.reset(SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED));

	if (m_renderer == nullptr) {
		LOG(m_log.get(), "%s", SDL_GetError());

		throw clio::Exception("Could not create renderer.");
	} else {
		LOG(m_log.get(), "Renderer created.");
	}
}

void Renderer2D::ClearScreen() {
	SDL_RenderClear(m_renderer.get());
}

void Renderer2D::RenderDraws() {
	SDL_RenderPresent(m_renderer.get());
}

Texture* Renderer2D::LoadTexture(std::string texture_file) {
	//Make sure the texture hasn't already been loaded
	auto exists = m_textures.find(texture_file);
	if (exists != m_textures.end()) {
		return exists->second;
	}

	//Attempt to load the texture
	SDL_Texture *tex = IMG_LoadTexture(m_renderer.get(), texture_file.c_str());
	if (tex == nullptr){
		LOG(m_log.get(), "%s", SDL_GetError());

		return nullptr;
	}

	//Retrieve information about the texture
	int w, h;
	SDL_QueryTexture(tex, nullptr, nullptr, &w, &h);

	//Create clio::Texture object
	Texture* texture = new Texture(m_textureId, w, h);

	//Save references to both clio::Texture and SDL's texture
	m_textures[texture_file] = texture;
	m_sdlTextures[texture] = tex;

	return texture;
}

void Renderer2D::FreeTexture(Texture* texture) {
	//Remove the SDL Texture from memory and map
	auto exists = m_sdlTextures.find(texture);
	if (exists != m_sdlTextures.end()) {
		SDL_DestroyTexture(exists->second);
		m_sdlTextures.erase(exists);
	}

	//Remove the clio Texture from map
	for (auto& t : m_textures) {
		if (t.second->id == texture->id) {
			m_textures.erase(t.first);
			break;
		}
	}

	//Delete Texture pointer
	delete texture;
}

void Renderer2D::DrawTexture(Texture* texture, int x, int y, int w, int h) {
	SDL_Texture *tex = m_sdlTextures[texture];
	if (tex == nullptr) {
		return;
	}

	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	if (w == 0 || h == 0) {
		dest.w = texture->width;
		dest.h = texture->height;
	} else {
		//Stretch or compress according to given width and height
		dest.w = w;
		dest.h = h;
	}

	SDL_RenderCopy(m_renderer.get(), tex, nullptr, &dest);
}

void Renderer2D::DrawTextureClip(TextureClip* textureClip, int x, int y, int w, int h) {
	SDL_Texture *tex = m_sdlTextures[textureClip->texture];
	if (tex == nullptr) {
		return;
	}

	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	if (w == 0 || h == 0) {
		dest.w = textureClip->width;
		dest.h = textureClip->height;
	} else {
		//Stretch or compress according to given width and height
		dest.w = w;
		dest.h = h;
	}

	SDL_Rect src;
	src.x = textureClip->x;
	src.y = textureClip->y;
	src.w = textureClip->width;
	src.h = textureClip->height;

	SDL_RenderCopy(m_renderer.get(), tex, &src, &dest);
}