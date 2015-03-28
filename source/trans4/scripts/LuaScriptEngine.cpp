/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "lua.hpp"
#include "LuaBridge.h"

#include "clio/graphics/Texture.hpp"

#include "scripts/Canvas.hpp"
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
				.beginNamespace("input")
					.addFunction("isKeyDown", detail::IsKeyDown)
				.endNamespace()
				.beginNamespace("game")
					.addFunction("changeState", detail::ChangeState)
					.addFunction("pushState", detail::PushState)
					.addFunction("popState", detail::PopState)
					.addFunction("quit", detail::QuitGame)
				.endNamespace()
				.beginNamespace("graphics")
					.addFunction("loadTexture", detail::LoadTexture)
					.addFunction("freeTexture", detail::FreeTexture)
					.addFunction("drawTexture", detail::DrawTexture)
					.addFunction("drawClip", detail::DrawClip)
					.addFunction("setColor", detail::SetColor)
					.addFunction("drawPixel", detail::DrawPixel)
					.addFunction("drawLine", detail::DrawLine)
					.addFunction("drawRect", detail::DrawRect)
					.addFunction("fillRect", detail::FillRect)
					.addFunction("createCanvas", detail::CreateCanvas)
				.endNamespace()
			.endNamespace();

		getGlobalNamespace(state_.get())
			.beginNamespace("tk").beginNamespace("graphics")
				.beginClass<clio::Texture>("Texture")
					.addFunction("width", &clio::Texture::GetWidth)
					.addFunction("height", &clio::Texture::GetHeight)
				.endClass()
				.beginClass<rpgtoolkit::Canvas>("Canvas")
					.addFunction("drawTexture", &rpgtoolkit::Canvas::DrawTexture)
					.addFunction("drawClip", &rpgtoolkit::Canvas::DrawTextureClip)
					.addFunction("drawPixel", &rpgtoolkit::Canvas::DrawPixel)
					.addFunction("drawLine", &rpgtoolkit::Canvas::DrawLine)
					.addFunction("drawRect", &rpgtoolkit::Canvas::DrawRect)
					.addFunction("fillRect", &rpgtoolkit::Canvas::FillRect)
					.addFunction("render", &rpgtoolkit::Canvas::Render)
				.endClass()
			.endNamespace().endNamespace();
	}

}
