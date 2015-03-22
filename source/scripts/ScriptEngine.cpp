#include "lua.hpp"
#include "LuaScriptEngine.h"

using namespace tk4;

ScriptEngine::ScriptEngine() : m_scriptEngine(nullptr) {

}

ScriptEngine::~ScriptEngine() {
	if (m_scriptEngine != nullptr) {
		delete m_scriptEngine;
	}
}

void ScriptEngine::initialize(Game* game, System* system) {
	m_scriptEngine = new lua::ScriptEngine();
	m_scriptEngine->initialize(game, system);
}

void ScriptEngine::run(std::string script) {
	m_scriptEngine->run(script);
}