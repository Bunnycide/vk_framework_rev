#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory>
#include <set>
#include <vk_framework/Device/Instance/Instance.h>
#include <vulkan/vulkan_core.h>
#include <vk_framework/Core.h>

using namespace vk_framework;

bool vk_framework::_h_checkIfLayersAvailable(const std::vector<std::string>& layer_names){

    std::set available_layers(layer_names.begin(), layer_names.end());

    uint32_t layer_count = 0;
    vkEnumerateInstanceLayerProperties(&layer_count, nullptr);

    if (layer_count <=0) return false;
    std::vector<VkLayerProperties> layer_properties(layer_count);
    vkEnumerateInstanceLayerProperties(&layer_count, layer_properties.data());

    std::ranges::for_each(layer_properties.begin(), layer_properties.end(),
        [&available_layers](const VkLayerProperties& layer_prop)
    {
        available_layers.erase(layer_prop.layerName);
    });

    return available_layers.empty();
}

bool vk_framework::_h_checkIfExtensionsAvailable(const std::vector<std::string> &extension_names){

    std::set available_extensions(extension_names.begin(), extension_names.end());

    uint32_t extension_count = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, nullptr);

    if (extension_count <=0) return false;
    std::vector<VkExtensionProperties> extension_properties(extension_count);
    vkEnumerateInstanceExtensionProperties(nullptr, &extension_count,
        extension_properties.data());

    std::ranges::for_each(extension_properties.begin(), extension_properties.end(),
        [&available_extensions](const VkExtensionProperties& extension_prop)
        {
            available_extensions.erase(extension_prop.extensionName);
        });

    return available_extensions.empty();
}

Instance::ErrorCode Instance::create()
{
    VkApplicationInfo appInfo {
        .sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pNext              = nullptr,
        .pApplicationName   = "vk-framework",
        .applicationVersion = VK_MAKE_VERSION(1,0,0),
        .pEngineName        = "vk-framework",
        .engineVersion      = VK_MAKE_VERSION(1,0,0),
        .apiVersion         = VK_MAKE_VERSION(1,0,0)
    };

    char** pp_layer_names = _h_stringVectorToCharPP(layer_names);
    char** pp_extenion_names = _h_stringVectorToCharPP(extension_names);

    if ( ! ( _h_checkIfLayersAvailable(layer_names) && _h_checkIfExtensionsAvailable(extension_names)) )
    {
        return INS_ERR_LAYER_OR_EXTENSION_NOT_AVAILABLE;
    }


    VkInstanceCreateInfo instanceCreateInfo {
        .sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pNext                   = nullptr,
        .flags                   = 0,
        .pApplicationInfo        = &appInfo,
        .enabledLayerCount       = layer_names.empty() ? 0 : static_cast<uint32_t>(layer_names.size()),
        .ppEnabledLayerNames     = layer_names.empty() ? nullptr : pp_layer_names,
        .enabledExtensionCount   = extension_names.empty() ? 0 : static_cast<uint32_t>(extension_names.size()),
        .ppEnabledExtensionNames = extension_names.empty() ? nullptr : pp_extenion_names
    };

    if(VK_SUCCESS != vkCreateInstance(
        &instanceCreateInfo,
        nullptr,
        &instance)){
        std::cout << "Error occurred" << std::endl;

        return INS_ERR_CREATE_INSTANCE_FAILED;
    }

    _h_freeCharPPMemory(pp_layer_names, layer_names.size());
    _h_freeCharPPMemory(pp_extenion_names, extension_names.size());

    if (! loadInstanceVulkanFunctions(instance))
    {
        return INS_ERR_LOADING_INSTANCE_VULKAN_FUNCTIONS_FAILED;
    }

    return INS_SUCCESS;
}
