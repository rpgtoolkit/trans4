/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <lua.hpp>
#include <LuaBridge.h>

#include <trans4/scripts/LuaScriptEngine.hpp>
#include <trans4/scripts/ScriptInterface.hpp>
#include <trans4/common/Rectangle.hpp>

namespace rpgtoolkit {

	LuaScriptEngine::LuaScriptEngine() : m_state(nullptr) {
	}

	LuaScriptEngine::~LuaScriptEngine() {
		if (m_state != nullptr) {
			lua_close(m_state);
		}
	}

	void LuaScriptEngine::initialize(Game* game, System* system) {
		m_state = luaL_newstate();
		luaL_openlibs(m_state);

		detail::setLuaInstance(m_state);
		detail::setSystemInstance(system);
		detail::setGameInstance(game);

		registerFunctions();
	}

	void LuaScriptEngine::run(std::string script) {
		if (script.substr(script.find_last_of(".") + 1) == "lua") {
			luaL_dofile(m_state, script.c_str());
		} else {
			luaL_dostring(m_state, script.c_str());
		}
	}

	void LuaScriptEngine::registerFunctions() {

		using namespace luabridge;

		getGlobalNamespace(m_state)
			.beginNamespace("tk")
				.addFunction("isKeyDown", detail::isKeyDown)
				.addFunction("changeState", detail::changeState)
				.addFunction("pushState", detail::pushState)
				.addFunction("popState", detail::popState)
				.addFunction("loadTexture", detail::loadTexture)
				.addFunction("drawTexture", detail::drawTexture)
				.addFunction("drawClip", detail::drawClip)
			.endNamespace();

		getGlobalNamespace(m_state)
			.beginNamespace("tk")
				.beginClass <Rectangle> ("Rectangle")
					.addConstructor<void (*) (int, int, int, int)> ()
					.addData("x", &Rectangle::x)
					.addData("y", &Rectangle::y)
					.addData("w", &Rectangle::width)
					.addData("h", &Rectangle::height)
				.endClass()
			.endNamespace();

	}

}
