/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <map>
#include <string>

#include <trans4/scripts/ScriptInterface.hpp>
#include <trans4/scripts/LuaGameState.hpp>
#include <trans4/common/Rectangle.hpp>
#include <trans4/game/Game.hpp>
#include <trans4/graphics/Renderer.hpp>
#include <trans4/system/System.hpp>
#include <trans4/input/Input.hpp>
#include <trans4/input/Keyboard.hpp>
#include <trans4/input/Key.hpp>

namespace rpgtoolkit {

	static lua_State* L;
	static System* sys;
	static Renderer* renderer;
	static Game* game;

	void detail::setLuaInstance(lua_State* lua) {
		L = lua;
	}

	void detail::setSystemInstance(System* system) {
		sys = system;
		renderer = sys->getRenderer();
	}

	void detail::setGameInstance(Game* g) {
		game = g;
	}

	bool detail::isKeyDown(std::string key) {
		return sys->getInput()->getKeyboard()
			->isKeyDown(stringToKey(key));
	}

	void detail::changeState(std::string state) {
		game->changeState(new LuaGameState(L, state));
	}

	void detail::pushState(std::string state) {
		game->pushState(new LuaGameState(L, state));
	}

	void detail::popState() {
		game->popState();
	}

	unsigned int detail::loadTexture(std::string texture_file) {
		return renderer->loadTexture(texture_file);
	}

	void detail::drawTexture(int textureId, int x, int y) {
		renderer->drawTexture(textureId, x, y);
	}

	void detail::drawClip(int textureId, int x, int y, int tx, int ty, int tw, int th) {
		Rectangle rect(tx, ty, tw, th);
		renderer->drawTexture(textureId, x, y, &rect);
	}

}
