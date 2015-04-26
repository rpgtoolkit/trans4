/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "lua.hpp"
#include "LuaBridge.h"

#include "Settings.hpp"
#include "graphics/Colour.hpp"
#include "graphics/Texture.hpp"
#include "scripts/ScriptEngine.hpp"
#include "scripts/ScriptInterface.hpp"

namespace rpgtoolkit {

	ScriptEngine::ScriptEngine() : state_(luaL_newstate()) {
		luaL_openlibs(state_.get());

		RegisterFunctions();
	}

	ScriptEngine::~ScriptEngine() {
	}

	void ScriptEngine::Run(const std::string& script) {
		if (script.substr(script.find_last_of(".") + 1) == "lua") {
			luaL_dofile(state_.get(), script.c_str());
		}
		else {
			luaL_dostring(state_.get(), script.c_str());
		}
	}

	void ScriptEngine::RegisterFunctions() {
		using namespace luabridge;

		getGlobalNamespace(state_.get())
			.beginNamespace("tk")
				.beginNamespace("input")
					.addFunction("isKeyDown", detail::IsKeyDown)
				.endNamespace()
				.beginNamespace("graphics")
					.addFunction("renderDraws", detail::RenderDraws)
					.addFunction("clearScreen", detail::ClearScreen)
					.addFunction("setColour", detail::SetColour)
					.addFunction("drawPixel", detail::DrawPixel)
					.addFunction("drawLine", detail::DrawLine)
					.addFunction("drawRect", detail::DrawRect)
					.addFunction("fillRect", detail::FillRect)
				.endNamespace()
			.endNamespace();

		getGlobalNamespace(state_.get())
			.beginNamespace("tk")
				.beginNamespace("game")
					.beginClass<WindowSettings>("WindowSettings")
						.addConstructor <void(*) (void)>()
						.addData("width", &WindowSettings::width)
						.addData("height", &WindowSettings::height)
						.addData("title", &WindowSettings::title)
						.addData("fullscreen", &WindowSettings::fullscreen)
					.endClass()
					.beginClass<GameSettings>("GameSettings")
						.addConstructor <void(*) (void)>()
						.addData("width", &GameSettings::width)
						.addData("height", &GameSettings::height)
					.endClass()
					.beginClass<Settings>("Settings")
						.addConstructor <void(*) (void)>()
						.addData("window", &Settings::window)
						.addData("game", &Settings::game)
					.endClass()
				.endNamespace()
				.beginNamespace("graphics")
					.beginClass<Colour>("Colour")
						.addConstructor <void(*) (uint8_t, uint8_t, uint8_t, uint8_t)>()
						.addData("red", &Colour::red)
						.addData("green", &Colour::green)
						.addData("blue", &Colour::blue)
						.addData("alpha", &Colour::alpha)
					.endClass()
					.beginClass<Texture>("Texture")
						.addData("width", &Texture::width, false)
						.addData("height", &Texture::height, false)
					.endClass()
				.endNamespace()
			.endNamespace();
	}

}
