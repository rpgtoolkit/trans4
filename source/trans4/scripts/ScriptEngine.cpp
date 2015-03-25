/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "scripts/ScriptEngine.hpp"
#include "scripts/LuaScriptEngine.hpp"

namespace rpgtoolkit {

	ScriptEngine::ScriptEngine() : scriptEngine_(nullptr) {
	}

	ScriptEngine::~ScriptEngine() {
	}

	void ScriptEngine::Initialize(Game * const game, clio::System * const system) {
		scriptEngine_.reset(new LuaScriptEngine());
		scriptEngine_->Initialize(game, system);
	}

	void ScriptEngine::Run(const std::string& script) {
		scriptEngine_->Run(script);
	}

}
