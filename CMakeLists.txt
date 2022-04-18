cmake_minimum_required(VERSION 3.10)

project(AdventureGame)

find_package(SFML 2.5 COMPONENTS graphics audio window system network REQUIRED)

# NOTE: This is an absolute path and will not work on other machines. I still havent figured out
# how to make this a relative path because I dont know what the default is.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /media/jonathan/2TB\ Storage\ and\ Game\ Drive/Jon/Programming/CardGames/War)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
	Main.out 
	main.cpp 
	miscellaneous.cpp
)

target_link_libraries(Main.out sfml-graphics sfml-audio)

