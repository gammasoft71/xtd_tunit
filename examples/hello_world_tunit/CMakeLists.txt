cmake_minimum_required(VERSION 3.3)

project(hello_world_tunit)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world_tunit.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.tunit")
