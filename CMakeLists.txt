cmake_minimum_required(VERSION 2.8)

# add libfbcp library
add_subdirectory(libfbcp)

# fbcp-ili9341 executable
project(fbcp-ili9341)
add_executable(${PROJECT_NAME} fbcp/fbcp.c)
target_link_libraries(${PROJECT_NAME} fbcp)
