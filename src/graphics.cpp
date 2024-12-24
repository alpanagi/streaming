#include "graphics.h"
#include "sdlk.h"
#include "vlk.h"

Graphics::Graphics() {
  auto instance_extensions = sdlk::get_vulkan_instance_extensions();
  instance = vlk::create_instance(instance_extensions);
  physical_device = vlk::get_physical_device(instance);

  auto [device_, queue_] = vlk::create_device(physical_device);
  device = device_;
  queue = queue_;

  command_pool = vlk::create_command_pool(device);
}

void Graphics::render() {
  VkSubmitInfo submit_info{
      .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
      .commandBufferCount = 0,
      .pCommandBuffers = nullptr,
  };
  vkQueueSubmit(queue, 1, &submit_info, nullptr);
}
