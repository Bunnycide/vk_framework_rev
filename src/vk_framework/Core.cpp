#include <vk_framework/Core.h>
#include <vk_loader/vk_loader.h>
#include <algorithm>
#include <memory>
#include <cstring>

char** vk_framework::_h_stringVectorToCharPP(const std::vector<std::string> &vec)  {
    auto pp_char_array = static_cast<char**>(std::malloc(sizeof(char*) * vec.size()));

    std::ranges::for_each(vec, [&pp_char_array](const std::string& name ){
        // Allocate the memory for the names
        *pp_char_array = static_cast<char*>(std::malloc(sizeof(char) * name.size()));
        // Move over the string contents
        std::memcpy(*pp_char_array, name.c_str(), name.size());
        // On the next element
        ++pp_char_array;
    });

    // Decrement pointer back to the beginning
    pp_char_array -= vec.size();

    return pp_char_array;
}

void vk_framework::_h_freeCharPPMemory(char** pp_char_array, size_t size)
{
    std::ranges::for_each(pp_char_array, pp_char_array, [](char* pStr)
    {
        std::free(pStr);
    });

    std::free(pp_char_array);
}

bool vk_framework::frameWorkInit(){
    VulkanFuncLoadState::areCoreVulkanFunctionsAvailable = loadVulkan();
    return VulkanFuncLoadState::areCoreVulkanFunctionsAvailable;
}
