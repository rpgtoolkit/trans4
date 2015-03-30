# Copyright (c) 2015, Chris Hutchinson
#
# See LICENSE.md in the distribution for the full license text including,
# but not limited to, a notice of warranty and distribution rights.

set(RPGTOOLKIT_TRANS4_TARGET "trans4")

# Dependencies

find_package(SDL2 REQUIRED)
find_package(SDL_image REQUIRED)
find_package(LUA 5.3.0 REQUIRED)
find_package(LUABRIDGE REQUIRED)
find_package(CLIO REQUIRED)

# Files

set(RPGTOOLKIT_TRANS4_HEADERS
  ${RPGTOOLKIT_HEADERS}/trans4/Version.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/Engine.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/Asset.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetDescriptor.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetHandle.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetHandleResolver.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetRepository.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/AssetSerializer.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/Item.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/GameManifest.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/Tileset.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/files/FileAssetHandle.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/files/FileAssetHandleResolver.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/serializers/LegacyItemSerializer.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/serializers/LegacyGameManifestSerializer.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/assets/serializers/LegacyTilesetSerializer.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/io/BinaryReader.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/game/Game.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/Canvas.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/LuaCommand.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/LuaGameState.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/LuaScriptEngine.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/ScriptEngine.hpp
  ${RPGTOOLKIT_HEADERS}/trans4/scripts/ScriptInterface.hpp
)

set(RPGTOOLKIT_TRANS4_SOURCES
  ${RPGTOOLKIT_SOURCES}/trans4/trans4.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/Engine.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/Version.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/AssetHandle.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/AssetRepository.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/GameManifest.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/Item.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/Tileset.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/files/FileAssetHandle.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/files/FileAssetHandleResolver.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/serializers/LegacyGameManifestSerializer.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/serializers/LegacyItemSerializer.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/assets/serializers/LegacyTilesetSerializer.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/game/Game.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/io/BinaryReader.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/Canvas.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/LuaCommand.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/LuaGameState.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/LuaScriptEngine.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/ScriptEngine.cpp
  ${RPGTOOLKIT_SOURCES}/trans4/scripts/ScriptInterface.cpp
)

# Build

include_directories(
  ${RPGTOOLKIT_HEADERS}/clio
  ${RPGTOOLKIT_HEADERS}/trans4
  ${SDL2_INCLUDE_DIR}
  ${SDL2_IMAGE_INCLUDE_DIR}
  ${SDL2MAIN_LIBRARY}
  ${LUA_INCLUDE_DIR}
  ${LUABRIDGE_INCLUDE_DIRS}
  ${CLIO_INCLUDE_DIRS}
)

add_executable(${RPGTOOLKIT_TRANS4_TARGET}
  ${RPGTOOLKIT_TRANS4_HEADERS}
  ${RPGTOOLKIT_TRANS4_SOURCES}
)

target_link_libraries(${RPGTOOLKIT_TRANS4_TARGET} optimized
  ${LUA_LIBRARY}
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
  ${CLIO_LIBRARIES}
)

target_link_libraries(${RPGTOOLKIT_TRANS4_TARGET} debug
  ${LUA_LIBRARY}
  ${SDL2_LIBRARY}
  ${SDL2MAIN_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
  ${CLIO_LIBRARIES}
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