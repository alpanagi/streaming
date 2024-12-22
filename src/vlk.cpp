#include "vlk.h"
#include "panik.h"
#include <print>
#include <vulkan/vk_enum_string_helper.h>

VkInstance vlk::create_instance(const std::vector<std::string> &extensions) {
  VkInstance instance;

  const char *layer_names[] = {"VK_LAYER_KHRONOS_validation"};
  const char **extension_names = new const char *[extensions.size()];
  for (int i = 0; i < extensions.size(); i++) {
    extension_names[i] = extensions[i].c_str();
  }

  VkInstanceCreateInfo instance_create_info{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
      .enabledLayerCount = 1,
      .ppEnabledLayerNames = layer_names,
      .enabledExtensionCount = static_cast<uint32_t>(extensions.size()),
      .ppEnabledExtensionNames = extension_names,
  };
  if (auto error = vkCreateInstance(&instance_create_info, nullptr, &instance);
      error != VK_SUCCESS) {
    panik::crash(panik::Component::Vulkan, string_VkResult(error));
  }

  return instance;
}
