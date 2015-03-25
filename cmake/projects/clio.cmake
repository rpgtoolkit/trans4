# Copyright (c) 2015, Chris Hutchinson
#
# See LICENSE.md in the distribution for the full license text including,
# but not limited to, a notice of warranty and distribution rights.

set(RPGTOOLKIT_CLIO_TARGET "clio")

# Dependencies

find_package(SDL2 REQUIRED)
find_package(SDL_image REQUIRED)

# Files

set(RPGTOOLKIT_CLIO_HEADERS
  ${RPGTOOLKIT_HEADERS}/clio/common/Exception.hpp
  ${RPGTOOLKIT_HEADERS}/clio/common/Logger.hpp
  ${RPGTOOLKIT_HEADERS}/clio/common/Timer.hpp
  ${RPGTOOLKIT_HEADERS}/clio/game/GameState.hpp
  ${RPGTOOLKIT_HEADERS}/clio/game/GameStateStack.hpp
  ${RPGTOOLKIT_HEADERS}/clio/graphics/Renderer2D.hpp
  ${RPGTOOLKIT_HEADERS}/clio/graphics/Texture.hpp
  ${RPGTOOLKIT_HEADERS}/clio/input/Input.hpp
  ${RPGTOOLKIT_HEADERS}/clio/input/InputContext.hpp
  ${RPGTOOLKIT_HEADERS}/clio/input/InputHandler.hpp
  ${RPGTOOLKIT_HEADERS}/clio/input/Key.hpp
  ${RPGTOOLKIT_HEADERS}/clio/input/Keyboard.hpp
  ${RPGTOOLKIT_HEADERS}/clio/system/System.hpp
  ${RPGTOOLKIT_HEADERS}/clio/system/SystemSettings.hpp
  ${RPGTOOLKIT_HEADERS}/clio/window/Window.hpp
  ${RPGTOOLKIT_HEADERS}/clio/window/WindowSettings.hpp
)

set(RPGTOOLKIT_CLIO_SOURCES
  ${RPGTOOLKIT_SOURCES}/clio/common/Exception.cpp
  ${RPGTOOLKIT_SOURCES}/clio/common/Logger.cpp
  ${RPGTOOLKIT_SOURCES}/clio/common/Timer.cpp
  ${RPGTOOLKIT_SOURCES}/clio/game/GameStateStack.cpp
  ${RPGTOOLKIT_SOURCES}/clio/input/InputContext.cpp
  ${RPGTOOLKIT_SOURCES}/clio/input/Key.cpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDL.cpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLInput.cpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLKeyboard.cpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLRenderer2D.cpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLSystem.cpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLWindow.cpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLWindowSettings.cpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDL.hpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLInput.hpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLKeyboard.hpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLRenderer2D.hpp
  ${RPGTOOLKIT_SOURCES}/clio/sdl/SDLWindow.hpp
)

# Build

include_directories(
  ${RPGTOOLKIT_HEADERS}/clio
  ${SDL2_INCLUDE_DIR}
  ${SDL2_IMAGE_INCLUDE_DIR}
)

add_library(${RPGTOOLKIT_CLIO_TARGET} STATIC
  ${RPGTOOLKIT_CLIO_HEADERS}
  ${RPGTOOLKIT_CLIO_SOURCES}
)

target_link_libraries(${RPGTOOLKIT_CLIO_TARGET}
  ${SDL2_LIBRARY}
  ${SDL2MAIN_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
)

if (WIN32)
  target_link_libraries(${RPGTOOLKIT_CLIO_TARGET}
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

  target_link_libraries(${RPGTOOLKIT_CLIO_TARGET}
    -static
    -static-libgcc
    -static-libstdc++
  )

endif ()
