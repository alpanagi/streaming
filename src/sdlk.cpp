#include "sdlk.h"
#include "panik.h"
#include <print>

void sdlk::initialize() {
  if (!SDL_Init(0)) {
    panik::crash(panik::Component::Sdl, SDL_GetError());
  }
}

SDL_Window *sdlk::create_window(const std::string &title) {
  SDL_Window *window =
      SDL_CreateWindow(title.c_str(), 800, 600, SDL_WINDOW_VULKAN);
  if (window == nullptr) {
    panik::crash(panik::Component::Sdl, SDL_GetError());
    exit(1);
  }

  return window;
}
