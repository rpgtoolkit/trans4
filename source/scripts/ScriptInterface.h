#pragma once

#include <string>

namespace tk4 {
	class Game;
	class System;

	namespace wrapper {
		void setSystemInstance(System* system);

		void setGameInstance(Game* game);

		bool isKeyDown(std::string key);
	}
}