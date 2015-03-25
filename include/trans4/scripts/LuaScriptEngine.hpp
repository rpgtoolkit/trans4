/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_LUASCRIPTENGINE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_LUASCRIPTENGINE_INCLUDED

#include "scripts/ScriptEngine.hpp"
#include "system/System.h"

struct lua_State;

namespace rpgtoolkit {

	class LuaScriptEngine : public ScriptEngine {
	public:

		LuaScriptEngine();

		virtual ~LuaScriptEngine();

		void initialize(Game* game, clio::System* system);

		void run(std::string script);

	private:

		lua_State* m_state;

		void registerFunctions();

	};

}

#endif
