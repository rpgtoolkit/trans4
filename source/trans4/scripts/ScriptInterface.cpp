/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <string>
#include <memory>

#include "scripts/ScriptInterface.hpp"
#include "scripts/LuaGameState.hpp"
#include "game/Game.hpp"
#include "game/GameState.hpp"
#include "game/GameStateStack.hpp"
#include "graphics/Renderer2D.hpp"
#include "system/System.hpp"
#include "input/Input.hpp"
#include "input/Keyboard.hpp"
#include "input/Key.hpp"

namespace rpgtoolkit {

	static lua_State* L;
	static clio::System* sys;
	static clio::Renderer2D* renderer;
	static Game* game;

	void detail::SetLuaInstance(lua_State * const lua) {
		L = lua;
	}

	void detail::SetSystemInstance(clio::System * const system) {
		sys = system;
		renderer = sys->GetRenderer();
	}

	void detail::SetGameInstance(Game * const g) {
		game = g;
	}

	bool detail::IsKeyDown(std::string key) {
		return sys->GetInput()->GetKeyboard()->isKeyDown(clio::StringToKey(key));
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

	unsigned int detail::LoadTexture(std::string texture_file) {
		return 0;
	}

	void detail::DrawTexture(int textureId, int x, int y) {
	}

	void detail::DrawClip(int textureId, int x, int y, int tx, int ty, int tw, int th) {
	}

}
