#ifndef _VLK_H_
#define _VLK_H_

#include <string>
#include <vector>
#include <vulkan/vulkan.h>

namespace vlk {
VkInstance create_instance(const std::vector<std::string> &extension_names);
VkPhysicalDevice get_physical_device(const VkInstance);
std::pair<VkDevice, VkQueue> create_device(const VkPhysicalDevice);
VkCommandPool create_command_pool(const VkDevice);
} // namespace vlk
#endif
