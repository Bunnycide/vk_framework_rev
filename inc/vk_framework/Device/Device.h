#ifndef VK_FRAMEWORK_DEVICE_H_
#define VK_FRAMEWORK_DEVICE_H_

#include <functional>
#include <string>
#include <vk_loader/vk_loader.h>

namespace vk_framework
{

  // Helper functions
  [[ nodiscard ]] std::vector<VkPhysicalDevice> _h_get_all_physical_devices(const VkInstance& instance);

  typedef struct Device_ {
    enum ErrorCode
    {
      ERR_NO_PHYSICAL_DEVICES,
      ERR_NO_PHYS_DEV_SEL_ROUTINE_HANDLE_SET,
      SUCCESS,
    };

    std::vector<std::string> m_device_extensions = {};

    VkInstance        m_instance        = VK_NULL_HANDLE;
    VkPhysicalDevice  m_physical_device = VK_NULL_HANDLE;
    VkDevice          m_device          = VK_NULL_HANDLE;

    // Handle for function to handle physical device selection
    std::function<VkPhysicalDevice(std::vector<VkPhysicalDevice>)>
                      m_handle_phys_dev_sel = nullptr;

    // Interface functions
    [[ nodiscard ]]ErrorCode createDevice();
  } Device;
}

#endif // VK_FRAMEWORK_DEVICE_H_
