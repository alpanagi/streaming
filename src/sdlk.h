#ifndef _SDLK_H_
#define _SDLK_H_

#include <SDL3/SDL.h>
#include <string>
#include <vector>

namespace sdlk {
void initialize();
SDL_Window *create_window(const std::string &title);
std::vector<std::string> get_vulkan_instance_extensions();
} // namespace sdlk

#endif
