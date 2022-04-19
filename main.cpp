// Copyright Jonathan Carlson 2022

#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
using namespace std;

#include <time.h>
#include "initializer.h"

int main() {

	srand(time(NULL)); 
	Initializer globalData;

	// Main game loop	
    while(globalData.window.isOpen()) {
		globalData.eventHandler.listen();

		// ---------- Start coding game here ----------


		// Draw background on a loop.
		globalData.window.draw(globalData.background);



		// -------------------------------------------

		globalData.window.display();
   	}

	return 0;
}

#endif // MAIN_CPP