# CMakeList.txt : CMake project for BoomBox, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories("${PROJECT_SOURCE_DIR}/nanogui/include")
include_directories("${PROJECT_SOURCE_DIR}/nanogui/ext/glfw/include")
include_directories("include")

set(BOOM_SRC src/BoomBox.cpp src/BoomField.cpp)

# Add source to this project's executable.
add_executable(BoomBox ${BOOM_SRC})

set_target_properties(BoomBox PROPERTIES
LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
)

find_package(jsoncpp CONFIG REQUIRED)

target_compile_definitions(BoomBox PRIVATE NANOGUI_USE_OPENGL)
target_link_libraries(BoomBox PRIVATE jsoncpp_lib jsoncpp_object nanogui)

# TODO: Add tests and install targets if needed.


add_custom_command(TARGET BoomBox POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/nanogui/nanogui.dll
        ${CMAKE_BINARY_DIR}/BoomBox)
