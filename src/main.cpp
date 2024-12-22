#include "sdlk.h"
#include "vlk.h"
#include <SDL3/SDL_main.h>
#include <print>

int main() {
  sdlk::initialize();
  auto window = sdlk::create_window("streaming");

  auto instance_extensions = sdlk::get_vulkan_instance_extensions();
  auto instance = vlk::create_instance(instance_extensions);
}
