# Copyright (c) 2015, Chris Hutchinson
#
# See LICENSE.md in the distribution for the full license text including,
# but not limited to, a notice of warranty and distribution rights.

set(RPGTOOLKIT_TRANS4_TARGET    "trans4")

# Dependencies

find_package(SDL2 REQUIRED)
find_package(LUA 5.3.0 REQUIRED)
find_package(LUABRIDGE REQUIRED)

# Files

set(RPGTOOLKIT_TRANS4_HEADERS
  ${RPGTOOLKIT_HEADERS}/trans4/assets/Asset.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetDescriptor.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetHandle.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetHandleResolver.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetRepository.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetSerializer.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/Item.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/serializers/LegacyItemSerializer.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/common/Exception.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/common/Rectangle.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/io/BinaryReader.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/game/Game.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/game/GameState.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/game/GameStateManager.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/game/EmptyState.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/graphics/Renderer.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/input/Input.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/input/InputHandler.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/input/Key.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/input/Keyboard.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/ScriptEngine.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/LuaScriptEngine.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/LuaGameState.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/ScriptInterface.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/system/System.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/system/Timer.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/system/Window.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/sdl/SDLInput.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/sdl/SDLKeyboard.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/sdl/SDLRenderer.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/sdl/SDLWindow.hpp
)

set(RPGTOOLKIT_TRANS4_SOURCES
  ${RPGTOOLKIT_SOURCES}/trans4/trans4.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/common/Exception.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/game/Game.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/input/Key.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/LuaGameState.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/LuaScriptEngine.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/ScriptEngine.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/ScriptInterface.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/sdl/SDLInput.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/sdl/SDLKeyboard.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/sdl/SDLRenderer.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/sdl/SDLSystem.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/sdl/SDLTimer.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/sdl/SDLWindow.cpp
)

# Build

include_directories(
  ${RPGTOOLKIT_HEADERS}
  ${SDL2_INCLUDE_DIR}
  ${LUA_INCLUDE_DIR}
  ${LUABRIDGE_INCLUDE_DIRS}
)

add_executable(${RPGTOOLKIT_TRANS4_TARGET}
  ${RPGTOOLKIT_TRANS4_HEADERS}
  ${RPGTOOLKIT_TRANS4_SOURCES}
)

target_link_libraries(${RPGTOOLKIT_TRANS4_TARGET}
  ${LUA_LIBRARY}
  ${SDL2_LIBRARY}
  ${SDL2MAIN_LIBRARY}
)

if (WIN32)
  target_link_libraries(${RPGTOOLKIT_TRANS4_TARGET}
    "imm32"
    "winmm"
    "version"
  )
endif ()

# Build Flags

if (CMAKE_COMPILER_IS_GNUCXX)

  add_definitions(-std=c++11)
  add_definitions(-Wextra -Wall)
  add_definitions(-Wno-unused-parameter)
  add_definitions(-Wno-ignored-qualifiers)

  target_link_libraries(${RPGTOOLKIT_TRANS4_TARGET}
    -static
    -static-libgcc
    -static-libstdc++
  )

endif ()
