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

VkPhysicalDevice vlk::get_physical_device(const VkInstance instance) {
  VkPhysicalDevice physical_device;

  uint32_t count = 1;
  if (auto error =
          vkEnumeratePhysicalDevices(instance, &count, &physical_device);
      error != VK_SUCCESS) {
    panik::crash(panik::Component::Vulkan, string_VkResult(error));
  }

  return physical_device;
}

std::pair<VkDevice, VkQueue>
vlk::create_device(const VkPhysicalDevice physical_device) {
  VkDevice device;
  VkQueue queue;

  float queue_priorities[] = {1};
  VkDeviceQueueCreateInfo queue_create_info{
      .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
      .queueFamilyIndex = 0,
      .queueCount = 1,
      .pQueuePriorities = &queue_priorities[0],
  };

  VkDeviceCreateInfo device_create_info{
      .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
      .queueCreateInfoCount = 1,
      .pQueueCreateInfos = &queue_create_info,
  };

  if (auto error = vkCreateDevice(physical_device, &device_create_info, nullptr,
                                  &device);
      error != VK_SUCCESS) {
    panik::crash(panik::Component::Vulkan, string_VkResult(error));
  }

  vkGetDeviceQueue(device, 0, 0, &queue);

  return {device, queue};
}

VkCommandPool vlk::create_command_pool(const VkDevice device) {
  VkCommandPool command_pool;

  VkCommandPoolCreateInfo command_pool_create_info{
      .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
      .queueFamilyIndex = 0,
  };
  if (auto error = vkCreateCommandPool(device, &command_pool_create_info,
                                       nullptr, &command_pool);
      error != VK_SUCCESS) {
    panik::crash(panik::Component::Vulkan, string_VkResult(error));
  }

  return command_pool;
}
