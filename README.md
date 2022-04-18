Having underestimated the size of many of the projects I have endevoured to create, I am going to make a small, basic card game using SFML to get a grasp on how I will implement graphical features and such. To start, I will make the card game 'War', where 2 players each take half of the deck, the compare the top cards.

####################################################################################################
# COMPILE INSTRUCTIONS(CMake):
# Note: Only step 4 will be used in most cases unless you need to remake the 'build' folder.
# Also, in the CMakeLists.txt file, the folder to generate the executable is an absolute path, which
# will not work on other systems. I havent figured out how to set relative paths yet.
####################################################################################################
1.) Create build folder (if doesnt exist). 
2.) cd into build folder.
3.) Run command: "ccmake .." 
	Configure anything needed but you should only need to add "Debug" to the 1 blank.
	Hit "c" to create crap. If it works, a "g" option will appear to generate and exit.
4.) Run command: "make" This will create a "Main.out" executable in the source folder.