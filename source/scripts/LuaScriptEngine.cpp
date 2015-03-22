#pragma once

#include "lua.hpp"

#include "LuaScriptEngine.h"

#include "game/Game.h"

using namespace lua;
using namespace luabridge;

ScriptEngine::ScriptEngine() : m_state(nullptr) {
}

ScriptEngine::~ScriptEngine() {
	if (m_state != nullptr) {
		lua_close(m_state);
	}
}

void ScriptEngine::initialize(tk4::Game* game) {
	m_state = luaL_newstate();
	luaL_openlibs(m_state);
}

void ScriptEngine::run(std::string script) {
	if (script.substr(script.find_last_of(".") + 1) == "lua") {
		luaL_dofile(m_state, script.c_str());
	} else {
		luaL_dostring(m_state, script.c_str());
	}
}

void ScriptEngine::registerFunctions() {

}