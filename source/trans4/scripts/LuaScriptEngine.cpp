/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "lua.hpp"
#include "LuaBridge.h"

#include "scripts/LuaScriptEngine.hpp"
#include "scripts/ScriptInterface.hpp"

namespace rpgtoolkit {

	LuaScriptEngine::LuaScriptEngine() : state_(luaL_newstate()) {
	}

	LuaScriptEngine::~LuaScriptEngine() {
	}

	void LuaScriptEngine::Initialize(Game * const game, clio::System * const system) {
		luaL_openlibs(state_.get());

		detail::SetLuaInstance(state_.get());
		detail::SetSystemInstance(system);
		detail::SetGameInstance(game);

		RegisterFunctions();
	}

	void LuaScriptEngine::Run(const std::string& script) {
		if (script.substr(script.find_last_of(".") + 1) == "lua") {
			luaL_dofile(state_.get(), script.c_str());
		} else {
			luaL_dostring(state_.get(), script.c_str());
		}
	}

	void LuaScriptEngine::RegisterFunctions() {
		using namespace luabridge;

		getGlobalNamespace(state_.get())
			.beginNamespace("tk")
				.addFunction("isKeyDown", detail::IsKeyDown)
				.addFunction("changeState", detail::ChangeState)
				.addFunction("pushState", detail::PushState)
				.addFunction("popState", detail::PopState)
				.addFunction("loadTexture", detail::LoadTexture)
				.addFunction("drawTexture", detail::DrawTexture)
				.addFunction("drawClip", detail::DrawClip)
			.endNamespace();
	}

}
