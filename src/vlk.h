#ifndef _VLK_H_
#define _VLK_H_

#include <string>
#include <vector>
#include <vulkan/vulkan.h>

namespace vlk {
VkInstance create_instance(const std::vector<std::string> &extension_names);
} // namespace vlk
#endif
