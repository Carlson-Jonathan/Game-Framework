// Copyright Jonathan Carlson 2022

#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
using namespace std;

#include <time.h>
#include "initializer.h"

int main() {

	srand(time(NULL)); // Seeds random number generator. Must be before other intializers.
	Initializer globalData;
	
	/**************************************  Main Game Loop ****************************************/
    while(globalData.window.isOpen()) {
		globalData.window.draw(globalData.background);
		globalData.eventHandler.listen();

		// Start coding game here

		globalData.window.display();
   	}
   	/***********************************************************************************************/

	return 0;
}

#endif // MAIN_CPP