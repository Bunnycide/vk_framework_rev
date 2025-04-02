#ifndef VK_FRAMEWORK_CORE_H__
#define VK_FRAMEWORK_CORE_H__

#include <vector>
#include <string>

namespace vk_framework
{
  [[nodiscard]]   bool      frameWorkInit();
  [[nodiscard]]   char**    _h_stringVectorToCharPP(const std::vector<std::string> &vec);
  /**        */   void      _h_freeCharPPMemory(char** pp_char_array, size_t size);
}

#endif // VK_FRAMEWORK_CORE_H__
