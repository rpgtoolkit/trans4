#pragma once

#include "lua.hpp"
#include "LuaBridge.h"

#include "LuaScriptEngine.h"
#include "ScriptInterface.h"

#include "game/Game.h"

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

	tk4::wrapper::setSystemInstance(system);
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
		.endNamespace();
}