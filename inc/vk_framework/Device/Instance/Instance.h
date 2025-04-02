#ifndef VK_FRAMEWORK_INSTANCE_H__
#define VK_FRAMEWORK_INSTANCE_H__

#include <vector>
#include <string>
#include <vk_loader/vk_loader.h>
namespace vk_framework
{
  [[nodiscard]] bool    _h_checkIfLayersAvailable(const std::vector<std::string>& layer_names);
  [[nodiscard]] bool    _h_checkIfExtensionsAvailable(const std::vector<std::string>& extension_names);

  typedef struct Instance_ {

    enum ErrorCode
    {
      INS_ERR_LAYER_OR_EXTENSION_NOT_AVAILABLE,
      INS_ERR_CREATE_INSTANCE_FAILED,
      INS_ERR_LOADING_INSTANCE_VULKAN_FUNCTIONS_FAILED,
      INS_SUCCESS,
    };

    bool                     enable_debug_layers = false; // Enable vulkan debug layers

    VkInstance               instance            = VK_NULL_HANDLE;
    std::vector<std::string> layer_names         = {};
    std::vector<std::string> extension_names     = {};

    [[nodiscard]] ErrorCode create();

  } Instance;
}


#endif // VK_FRAMEWORK_INSTANCE_H__
