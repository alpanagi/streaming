#ifndef _SDLK_H_
#define _SDLK_H_

#include <SDL3/SDL_main.h>
#include <string>

namespace sdlk {
void initialize();
SDL_Window *create_window(const std::string &title);
} // namespace sdlk

#endif
