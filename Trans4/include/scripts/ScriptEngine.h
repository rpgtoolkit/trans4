#pragma once

#include <string>



namespace tk4 {
	class Game;
	class System;

	class ScriptEngine {
	public:
		ScriptEngine();

		virtual ~ScriptEngine();

		virtual void initialize(Game* game, System* system);

		virtual void run(std::string script);

		ScriptEngine(ScriptEngine const&) = delete;

		ScriptEngine & operator=(ScriptEngine const&) = delete;
	protected:
		ScriptEngine* m_scriptEngine;
	};
}