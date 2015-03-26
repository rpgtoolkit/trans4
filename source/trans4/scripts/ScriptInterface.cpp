/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <string>
#include <memory>

#include "scripts/ScriptInterface.hpp"
#include "scripts/LuaGameState.hpp"
#include "game/Game.hpp"
#include "clio/game/GameState.hpp"
#include "clio/game/GameStateStack.hpp"
#include "clio/graphics/Renderer2D.hpp"
#include "clio/graphics/Texture.hpp"
#include "clio/system/System.hpp"
#include "clio/input/Input.hpp"
#include "clio/input/Keyboard.hpp"
#include "clio/input/Key.hpp"

namespace rpgtoolkit {

	static lua_State* L;
	static clio::System* sys;
	static Game* game;

	void detail::SetLuaInstance(lua_State * const lua) {
		L = lua;
	}

	void detail::SetSystemInstance(clio::System * const system) {
		sys = system;
	}

	void detail::SetGameInstance(Game * const g) {
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

	clio::Texture* detail::LoadTexture(std::string texture_file) {
		return sys->GetRenderer()->LoadTexture(texture_file);
	}

	void detail::DrawTexture(clio::Texture* texture, int x, int y) {
		sys->GetRenderer()->DrawTexture(texture, x, y);
	}

	void detail::DrawClip(clio::TextureClip* clip, int x, int y) {
		sys->GetRenderer()->DrawTextureClip(clip, x, y);
	}
}
