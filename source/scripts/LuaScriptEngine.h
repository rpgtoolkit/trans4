#pragma once

#include "scripts/ScriptEngine.h"

struct lua_State;

namespace lua {
	class ScriptEngine : public tk4::ScriptEngine {
	public:
		ScriptEngine();

		virtual ~ScriptEngine();

		void initialize(tk4::Game* game);

		void run(std::string script);
	private:
		lua_State* m_state;

		void registerFunctions();
	};
}