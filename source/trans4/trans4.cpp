/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "clio/common/Exception.hpp"
#include "clio/system/Dialog.hpp"

//Have to include this after clio Exception
//This is a hack anyway, should rethrow luabridge exceptions as tk ones
#include "lua.hpp"
#include "LuaBridge.h"

#include "Engine.hpp"

int main(int argc, char* argv[]) {

	auto & engine = rpgtoolkit::Engine::GetInstance();

	try {
		engine.Configure();
		engine.Run();
	} catch(clio::Exception e) {
		clio::Dialog::ShowError("Clio Error", e.what());
	}
	catch (luabridge::LuaException e) {
		clio::Dialog::ShowError("Lua Error", e.what());
	}

	return 0;

}