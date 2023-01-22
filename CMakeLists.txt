cmake_minimum_required(VERSION 3.11)
project("minecraft-clone")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Handle Dependencies
include(cmake/handle_glad.cmake)
include(cmake/handle_glfw.cmake)
include(cmake/handle_glm.cmake)

set(SOURCES 
  src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad glm)
