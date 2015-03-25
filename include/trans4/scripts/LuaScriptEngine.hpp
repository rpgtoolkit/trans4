/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_LUASCRIPTENGINE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_LUASCRIPTENGINE_INCLUDED


#include <memory>

#include "lua.hpp"
#include "scripts/ScriptEngine.hpp"
#include "system/System.hpp"

struct lua_State;

namespace rpgtoolkit {
	/// \brief Smart pointer deleter for lua_State pointers
	struct LuaStateDeleter {
		void operator()(lua_State* L) {
			if (L != nullptr) {
				lua_close(L);
			}
		}
	};

	/// \brief A ScriptEngine implementation using Lua.
	///
	/// Maintains the lua_State* pointer and runs scripts
	/// by using the relevant lua calls. The class is also
	/// responsible for exposing functions and classes to
	/// Lua.
	class LuaScriptEngine : public ScriptEngine {
	public:
		LuaScriptEngine();

		virtual ~LuaScriptEngine();

		void Initialize(Game * const game, clio::System * const system);

		/// \brief Run a lua script. 
		/// Checks the string for a .lua extension. If found, 
		/// it will run the file, otherwise it will inline
		/// the script.
		///
		/// \param script The script or script file.
		void Run(const std::string& script);
	private:

		std::unique_ptr<lua_State, LuaStateDeleter> state_;

		/// \brief Helper function to expose TK functions to lua
		void RegisterFunctions();
	};

}

#endif
