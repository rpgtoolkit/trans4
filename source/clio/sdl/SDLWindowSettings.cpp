#include "SDL.hpp"
#include "window/WindowSettings.hpp"

uint32_t clio::WindowSettings::FULLSCREEN = SDL_WINDOW_FULLSCREEN;
uint32_t clio::WindowSettings::FULLSCREEN_DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP;
uint32_t clio::WindowSettings::BORDERLESS = SDL_WINDOW_BORDERLESS;
uint32_t clio::WindowSettings::RESIZABLE = SDL_WINDOW_RESIZABLE;
uint32_t clio::WindowSettings::MINIMIZED = SDL_WINDOW_MINIMIZED;
uint32_t clio::WindowSettings::MAXIMIZED = SDL_WINDOW_MAXIMIZED;

int clio::WindowSettings::POSITION_CENTERED = SDL_WINDOWPOS_CENTERED;