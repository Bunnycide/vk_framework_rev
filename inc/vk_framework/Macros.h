#ifndef VK_FRAMEWORK_MACROS_H__
#define VK_FRAMEWORK_MACROS_H__

#include <vk_loader/vulkan/vk_enum_string_helper.h>


#define VK_CHECK_RESULT(f)                                              \
    {                                                                   \
	VkResult res = (f);                                             \
	if (res != VK_SUCCESS)                                          \
	{                                                               \
            Log::error("Fatal : VkResult is \" %s \" in %s at line %d", string_VkResult(res) , __FILE__, __LINE__); \
            assert(res == VK_SUCCESS);                                  \
	}                                                               \
    }

#endif // VK_FRAMEWORK_MACROS_H__
