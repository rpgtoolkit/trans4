/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "Engine.hpp"

using rpgtoolkit::Engine;

int main(int argc, char* argv[]) {

	auto & engine = Engine::GetInstance();

	engine.Configure();
	engine.Run();

	return 0;

}