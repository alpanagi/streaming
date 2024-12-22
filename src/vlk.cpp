#include "vlk.h"
#include "panik.h"
#include <vulkan/vk_enum_string_helper.h>

VkInstance vlk::create_instance() {
  VkInstance instance;

  const char *layer_names[] = {"VK_LAYER_KHRONOS_validation"};

  VkInstanceCreateInfo instance_create_info{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
      .enabledLayerCount = 1,
      .ppEnabledLayerNames = &layer_names[0]};
  if (auto error = vkCreateInstance(&instance_create_info, nullptr, &instance);
      error != VK_SUCCESS) {
    panik::crash(panik::Component::Vulkan, string_VkResult(error));
  }

  return instance;
}
