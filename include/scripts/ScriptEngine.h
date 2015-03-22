#pragma once

#include <string>

#include "game/Game.h"

namespace tk4 {
	class ScriptEngine {
	public:
		ScriptEngine();

		virtual ~ScriptEngine();

		virtual void initialize(Game* game);

		virtual void run(std::string script);

		ScriptEngine(ScriptEngine const&) = delete;

		ScriptEngine & operator=(ScriptEngine const&) = delete;
	protected:
		Game* m_game;

		ScriptEngine* m_scriptEngine;
	};
}