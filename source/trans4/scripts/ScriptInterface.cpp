/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <map>
#include <string>
#include <memory>

#include "scripts/ScriptInterface.hpp"
#include "scripts/LuaGameState.hpp"
#include "game/Game.hpp"
#include "game/GameState.h"
#include "game/GameStateStack.h"
#include "graphics/Renderer2D.h"
#include "system/System.h"
#include "input/Input.h"
#include "input/Keyboard.h"
#include "input/Key.h"

namespace rpgtoolkit {

	static lua_State* L;
	static clio::System* sys;
	static clio::Renderer2D* renderer;
	static Game* game;

	void detail::setLuaInstance(lua_State* lua) {
		L = lua;
	}

	void detail::setSystemInstance(clio::System* system) {
		sys = system;
		renderer = sys->GetRenderer();
	}

	void detail::setGameInstance(Game* g) {
		game = g;
	}

	bool detail::isKeyDown(std::string key) {
		return sys->GetInput()->GetKeyboard()
			->isKeyDown(clio::StringToKey(key));
	}

	void detail::changeState(std::string state) {
		game->GetStateStack()->ChangeState(std::unique_ptr<clio::GameState>(new LuaGameState(L, state)));
	}

	void detail::pushState(std::string state) {
		game->GetStateStack()->PushState(std::unique_ptr<clio::GameState>(new LuaGameState(L, state)));
	}

	void detail::popState() {
		game->GetStateStack()->PopState();
	}

	unsigned int detail::loadTexture(std::string texture_file) {
		return 0;
	}

	void detail::drawTexture(int textureId, int x, int y) {
	}

	void detail::drawClip(int textureId, int x, int y, int tx, int ty, int tw, int th) {
	}

}
