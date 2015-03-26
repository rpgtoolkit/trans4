/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "lua.hpp"
#include "LuaBridge.h"

#include "clio/graphics/Texture.hpp"
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
				.addFunction("quit", detail::QuitGame)
				.addFunction("loadTexture", detail::LoadTexture)
				.addFunction("freeTexture", detail::FreeTexture)
				.addFunction("drawTexture", detail::DrawTexture)
				.addFunction("drawClip", detail::DrawClip)
			.endNamespace();

		getGlobalNamespace(state_.get())
			.beginNamespace("tk")
				.beginClass<clio::Texture>("Texture")
					.addData("width", &clio::Texture::width)
					.addData("height", &clio::Texture::height)
				.endClass()
				.beginClass<clio::TextureClip>("TextureClip")
					.addConstructor <void(*) (clio::Texture*, int32_t, int32_t, int32_t, int32_t)>()
					.addData("texture", &clio::TextureClip::texture)
					.addData("x", &clio::TextureClip::x)
					.addData("y", &clio::TextureClip::y)
					.addData("height", &clio::TextureClip::height)
					.addData("width", &clio::TextureClip::width)
				.endClass()
			.endNamespace();
	}

}
