#include "panik.h"
#include <print>

void panik::crash(const panik::Component &component,
                  const std::string &message) {
  std::string component_name = "UNKNOWN";
  switch (component) {
  case Component::Sdl:
    component_name = "SDL";
    break;
  case Component::Vulkan:
    component_name = "VULKAN";
    break;
  }

  std::print("[ERROR][{}] {}\n", component_name, message);
  exit(1);
}
