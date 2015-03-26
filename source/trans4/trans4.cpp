/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <iostream>

#include "system/System.hpp"
#include "system/SystemSettings.hpp"
#include "game/GameStateStack.hpp"

#include "game/Game.hpp"
#include "scripts/ScriptEngine.hpp"
#include "Engine.hpp"

using clio::System;
using clio::SystemSettings;

using rpgtoolkit::Engine;
using rpgtoolkit::Game;
using rpgtoolkit::ScriptEngine;

int main(int argc, char* argv[]) {

	auto & engine = Engine::GetInstance();

	engine.Configure();
	engine.Run();

	return 0;

}