/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <trans4/scripts/LuaScriptEngine.hpp>

namespace rpgtoolkit {

	ScriptEngine::ScriptEngine()
		: m_scriptEngine(nullptr) {

	}

	ScriptEngine::~ScriptEngine() {
		if (m_scriptEngine != nullptr) {
			delete m_scriptEngine;
		}
	}

	void ScriptEngine::initialize(Game* game, System* system) {
		m_scriptEngine = new ScriptEngine();
		m_scriptEngine->initialize(game, system);
	}

	void ScriptEngine::run(std::string script) {
		m_scriptEngine->run(script);
	}

}
