/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTENGINE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTENGINE_INCLUDED

#include <memory>
#include <string>

#include "lua.hpp"

namespace rpgtoolkit {
	struct Game;
	
	/// The ScriptEngine interface defines how scripts can be run.
	struct ScriptEngine {
	public:
		ScriptEngine();

		virtual ~ScriptEngine();

		/// \brief Run a script.
		///
		/// \param script The script to run.
		virtual void Run(const std::string& script);

		/// \brief No copying allowed.
		ScriptEngine(ScriptEngine const&) = delete;

		/// \brief No copying allowed.
		ScriptEngine & operator=(ScriptEngine const&) = delete;
	private:
		/// \brief Smart pointer deleter for lua_State pointers
		struct LuaStateDeleter {
			void operator()(lua_State* L) {
				if (L != nullptr) {
					lua_close(L);
				}
			}
		};
		std::unique_ptr<lua_State, LuaStateDeleter> state_;

		/// \brief Helper function to expose TK functions to lua
		void RegisterFunctions();
	};
}

#endif
