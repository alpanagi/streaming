#include "sdlk.h"
#include "panik.h"
#include <SDL3/SDL_vulkan.h>
#include <print>

void sdlk::initialize() {
  if (!SDL_Init(0)) {
    panik::crash(panik::Component::Sdl, SDL_GetError());
  }
}

std::vector<std::string> sdlk::get_vulkan_instance_extensions() {
  std::vector<std::string> extensions;
  uint32_t count = 0;

  auto data = SDL_Vulkan_GetInstanceExtensions(&count);
  for (int i = 0; i < count; i++) {
    extensions.push_back(data[i]);
  }

  return extensions;
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
