cmake_minimum_required(VERSION 3.11)
include(FetchContent)

FetchContent_Declare(
  glm
  GIT_REPOSITORY  https://github.com/g-truc/glm
)

FetchContent_GetProperties(glm)

if (NOT glm_POPULATED)
  FetchContent_Populate(glm)

  add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
endif()
