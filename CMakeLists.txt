cmake_minimum_required(VERSION 3.10.0)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# ----------------------------------------------------------
# add vk_loader
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/vk_loader)

# ----------------------------------------------------------
# framework lib src
set(SRC
  ${SRC_DIR}/Device.cpp)

add_library(vk_framework ${SRC})

target_include_directories(vk_framework PRIVATE ${INC_DIR})
