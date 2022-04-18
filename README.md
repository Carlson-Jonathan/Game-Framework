DESCRIPTION:
    This is a C++ game starter framework project made with SFML. Classes have been prepared to 
    better handle and manage textures, sounds, and hardware controls so you don't have to 
    re-invent the wheel every time you want to start making a new C++ game. Run the CMake 
    instructions below to compile. This will draw a window with a sample background image and play
    a demo song. Just edit the relevant code and call your game objects from main.cpp.


DEPENDENCIES:
    C++ 11,
    SFML (Get it here: https://www.sfml-dev.org/index.php)


COMPILE INSTRUCTIONS (CMake):
Note: Only step 4 will be used in most cases unless you need to remake the 'build' folder.

    1.) Create build folder (if doesnt exist). 
    2.) cd into build folder.
    3.) Run command: "cmake .." (auto config) or "ccmake .." (manual config) 
    	If manual, configure anything needed but you should only need to add "Debug" to the 1 blank. 
        Hit "c" to create crap. If it works, a "g" option will appear to generate and exit.
    4.) Run command: "make" This will create a "Main.out" executable in the source folder.


COMPILE INSTRUCTIONS (g++):
    If CMake isnt working, you can try the 'compileAndRun.bash' script. Just run. If you get linker 
    errors, you may need to add .cpp files that are not already listed because I will probably not 
    be updating the script regularly.