/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "Engine.hpp"

int main(int argc, char* argv[]) {

	auto & engine = rpgtoolkit::Engine::GetInstance();

	engine.Configure();
	engine.Run();

	return 0;

}