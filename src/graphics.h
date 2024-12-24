#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "vlk.h"

class Graphics {
private:
  VkInstance instance;
  VkPhysicalDevice physical_device;
  VkDevice device;
  VkQueue queue;
  VkCommandPool command_pool;

public:
  Graphics();
  void render();
};

#endif
