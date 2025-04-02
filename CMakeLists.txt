cmake_minimum_required(VERSION 3.10.0)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)

set(CMAKE_CXX_STANDARD 23)

set(LINK_LIBS vk_loader)

# ----------------------------------------------------------
# add vk_loader
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/vk_loader)
# ----------------------------------------------------------

# ----------------------------------------------------------
# framework lib sources
set(SRC
    ${SRC_DIR}/vk_framework/Device/Instance/Instance.cpp
    ${SRC_DIR}/vk_framework/Device/Device.cpp
    ${SRC_DIR}/vk_framework/Core.cpp)
# ----------------------------------------------------------

add_library(vk_framework ${SRC})

target_include_directories(vk_framework PUBLIC
    ${INC_DIR} # framework include dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/vk_loader/inc/)

target_link_libraries(vk_framework ${LINK_LIBS})
