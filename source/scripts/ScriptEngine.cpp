#include "lua.hpp"
#include "LuaScriptEngine.h"

using namespace tk4;

ScriptEngine::ScriptEngine() : m_game(nullptr), m_scriptEngine(nullptr) {

}

ScriptEngine::~ScriptEngine() {
	if (m_scriptEngine != nullptr) {
		delete m_scriptEngine;
	}
}

void ScriptEngine::initialize(Game* game) {
	m_game = game;

	m_scriptEngine = new lua::ScriptEngine();
	m_scriptEngine->initialize(game);
}

void ScriptEngine::run(std::string script) {
	m_scriptEngine->run(script);
}