#include "sdlk.h"
#include <SDL3/SDL_main.h>
#include <print>

int main() {
  sdlk::initialize();
  auto window = sdlk::create_window("streaming");
}
