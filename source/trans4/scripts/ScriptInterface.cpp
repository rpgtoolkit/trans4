/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <string>
#include <memory>

#include "clio/game/GameStateStack.hpp"
#include "clio/graphics/Renderer2D.hpp"
#include "clio/graphics/Texture.hpp"
#include "clio/graphics/TextureLoader.hpp"
#include "clio/input/Input.hpp"
#include "clio/input/Keyboard.hpp"
#include "clio/input/Key.hpp"

#include "Engine.hpp"
#include "scripts/ScriptInterface.hpp"
#include "scripts/LuaGameState.hpp"

namespace rpgtoolkit {

    static lua_State *L;

    static clio::System *sys;

    static Game *game;

    void detail::SetLuaInstance(lua_State *const lua) {
        L = lua;
    }

    void detail::SetSystemInstance(clio::System *const system) {
        sys = system;
    }

    void detail::SetGameInstance(Game *const g) {
        game = g;
    }

    bool detail::IsKeyDown(std::string key) {
        return sys->GetInput()->GetKeyboard()->IsKeyDown(clio::StringToKey(key));
    }

    void detail::ChangeState(std::string state) {
        game->GetStateStack()->ChangeState(std::unique_ptr<clio::GameState>(new LuaGameState(L, state)));
    }

    void detail::PushState(std::string state) {
        game->GetStateStack()->PushState(std::unique_ptr<clio::GameState>(new LuaGameState(L, state)));
    }

    void detail::PopState() {
        game->GetStateStack()->PopState();
    }

    void detail::QuitGame() {
        game->GetStateStack()->ClearAllStates();
    }

    clio::Texture *detail::LoadTexture(std::string texture_file) {

        AssetDescriptor descriptor(0x00, "file://" + texture_file);

        /// If the asset is a legacy tileset then intervene and load
        /// a tileset asset, create a texture, and upload the tileset
        /// image data to the texture...

        if (descriptor.GetExtension() == "tst") {

            auto & assets = Engine::GetInstance().GetAssets();
            auto tileset = assets.Load<Tileset>(descriptor.GetURI());

            // TODO: Determine optimal POT texture size and fill the
            // texture with tiles.

            if (tileset) {
                auto texture =
                    sys->GetTextureLoader()->CreateTexture(descriptor.GetURI(),
                        tileset->GetTileDimensions() * tileset->GetCount(),
                        tileset->GetTileDimensions());
                if (texture) {
                    texture->Update(tileset->GetImageBuffer());
                }
                return texture;
            }

        }

		return sys->GetTextureLoader()->LoadTexture(texture_file);
    }

    void detail::FreeTexture(clio::Texture *texture) {
		return sys->GetTextureLoader()->FreeTexture(texture);
    }

    void detail::DrawTexture(clio::Texture *texture, int x, int y) {
        sys->GetRenderer()->DrawTexture(texture, x, y);
    }

	void detail::DrawClip(clio::Texture* tex, int x, int y, int source_x, int source_y, int width, int height) {
		clio::TextureClip clip(tex, source_x, source_y, width, height);
		sys->GetRenderer()->DrawTextureClip(&clip, x, y);
	}

	void detail::SetColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
		sys->GetRenderer()->SetColor(red, green, blue, alpha);
	}

	void detail::DrawPixel(int x, int y) {
		sys->GetRenderer()->DrawPixel(x, y);
	}

	void detail::DrawLine(int x1, int y1, int x2, int y2) {
		sys->GetRenderer()->DrawLine(x1, y1, x2, y2);
	}

	void detail::DrawRect(int x, int y, int width, int height) {
		sys->GetRenderer()->DrawRect(x, y, width, height);
	}

	void detail::FillRect(int x, int y, int width, int height) {
		sys->GetRenderer()->FillRect(x, y, width, height);
	}

	rpgtoolkit::Canvas detail::CreateCanvas(size_t width, size_t height) {
		return Canvas(sys->GetRenderer(), width, height);
	}
}
