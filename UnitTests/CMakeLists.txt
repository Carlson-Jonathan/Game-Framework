cmake_minimum_required(VERSION 3.10)

project(GameworkFramework)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

add_executable(
	Main.out 
	testHarness.cpp
	../miscellaneous.cpp
	miscellaneous_test.cpp
)

target_link_libraries(Main.out)
