#include "lua.hpp"
#include "LuaBridge.h"

#include "LuaScriptEngine.h"
#include "ScriptInterface.h"

#include "common/Rectangle.h"

using namespace lua;

ScriptEngine::ScriptEngine() : m_state(nullptr) {
}

ScriptEngine::~ScriptEngine() {
	if (m_state != nullptr) {
		lua_close(m_state);
	}
}

void ScriptEngine::initialize(tk4::Game* game, tk4::System* system) {
	m_state = luaL_newstate();
	luaL_openlibs(m_state);
	
	tk4::wrapper::setLuaInstance(m_state);
	tk4::wrapper::setSystemInstance(system);
	tk4::wrapper::setGameInstance(game);

	registerFunctions();
}

void ScriptEngine::run(std::string script) {
	if (script.substr(script.find_last_of(".") + 1) == "lua") {
		luaL_dofile(m_state, script.c_str());
	} else {
		luaL_dostring(m_state, script.c_str());
	}
}

void ScriptEngine::registerFunctions() {
	using namespace luabridge;

	getGlobalNamespace(m_state)
		.beginNamespace("tk")
			.addFunction("isKeyDown", tk4::wrapper::isKeyDown)
			.addFunction("changeState", tk4::wrapper::changeState)
			.addFunction("pushState", tk4::wrapper::pushState)
			.addFunction("popState", tk4::wrapper::popState)
			.addFunction("loadTexture", tk4::wrapper::loadTexture)
			.addFunction("drawTexture", tk4::wrapper::drawTexture)
			.addFunction("drawClip", tk4::wrapper::drawClip)
		.endNamespace();

	getGlobalNamespace(m_state)
		.beginNamespace("tk")
			.beginClass <tk4::Rectangle> ("Rectangle")
				.addConstructor<void (*) (int, int, int, int)> ()
				.addData("x", &tk4::Rectangle::x)
				.addData("y", &tk4::Rectangle::y)
				.addData("w", &tk4::Rectangle::width)
				.addData("h", &tk4::Rectangle::height)
			.endClass()
		.endNamespace();
}