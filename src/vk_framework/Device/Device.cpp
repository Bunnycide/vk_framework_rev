#include <vk_framework/Device/Device.h>


std::vector<VkPhysicalDevice> vk_framework::_h_get_all_physical_devices(const VkInstance& instance)
{
  uint32_t physical_device_count = 0;
  vkEnumeratePhysicalDevices(instance, &physical_device_count, nullptr);
  if ( physical_device_count <= 0) return {};
  std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
  vkEnumeratePhysicalDevices(instance, &physical_device_count, physical_devices.data());

  return physical_devices;
}

vk_framework::Device::ErrorCode vk_framework::Device::createDevice()
{
  // Get all the physical devices
  auto t_physical_devices = _h_get_all_physical_devices(m_instance);

  if (t_physical_devices.empty())
  {
    return ERR_NO_PHYSICAL_DEVICES;
  }

  if (m_handle_phys_dev_sel == nullptr)
  {
    return ERR_NO_PHYS_DEV_SEL_ROUTINE_HANDLE_SET;
  }

  m_physical_device = m_handle_phys_dev_sel(t_physical_devices);

  // Create a logical device

  // auto p_device_extension_names =

  // Provided by VK_VERSION_1_0
  VkDeviceCreateInfo create_info{
    .sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
    .pNext                   = nullptr,
    .flags                   = 0,
    .queueCreateInfoCount    = 0,
    .pQueueCreateInfos       = nullptr,
    .enabledExtensionCount   = 0,
    .ppEnabledExtensionNames = nullptr,
    .pEnabledFeatures        = nullptr,
  };



  return SUCCESS;
}
