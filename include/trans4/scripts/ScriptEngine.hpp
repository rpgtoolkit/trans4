/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTENGINE_INCLUDED
#define RPGTOOLKIT_TRANS4_SCRIPTS_SCRIPTENGINE_INCLUDED

#include <string>

namespace rpgtoolkit {

	class Game;
	class System;

	/**
	* The ScriptEngine interface defines how scripts can be run.
	*/
	class ScriptEngine {
	public:

		ScriptEngine();

		virtual ~ScriptEngine();

		/**
		* Initialize the ScriptEngine and provide references to
		* the System and Game implementations, to be used with
		* scripts in the future.
		*
		* @param game The current game being run.
		* @param system The current system that has been initialized.
		*/
		virtual void initialize(Game* game, System* system);

		/**
		* Run a script.
		*
		* @param script The script or script file.
		*/
		virtual void run(std::string script);

		/**
		* No copying allowed.
		*/
		ScriptEngine(ScriptEngine const&) = delete;

		/**
		* No copying allowed.
		*/
		ScriptEngine & operator=(ScriptEngine const&) = delete;

	protected:

		ScriptEngine* m_scriptEngine;

	};
}

#endif
