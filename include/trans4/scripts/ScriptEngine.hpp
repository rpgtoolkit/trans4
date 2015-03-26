/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTENGINE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTENGINE_INCLUDED

#include <memory>
#include <string>

namespace clio {
	struct System;
}

namespace rpgtoolkit {

	struct Game;
	
	/// The ScriptEngine interface defines how scripts can be run.
	struct ScriptEngine {
	public:
		ScriptEngine();

		virtual ~ScriptEngine();


		/// \brief Initialize the ScriptEngine. 
		/// Provide references to the System and Game implementations, 
		/// to be used with scripts in the future.
		///
		/// \param game
		/// \param system
		virtual void Initialize(Game * const game, clio::System * const system);

		/// \brief Run a script.
		///
		/// \param script The script to run.
		virtual void Run(const std::string& script);

		/// \brief No copying allowed.
		ScriptEngine(ScriptEngine const&) = delete;

		/// \brief No copying allowed.
		ScriptEngine & operator=(ScriptEngine const&) = delete;
	protected:
		/// \brief The ScriptEngine implementation.
		std::unique_ptr<ScriptEngine> scriptEngine_;

	};
}

#endif
