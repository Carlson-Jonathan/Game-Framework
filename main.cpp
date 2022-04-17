// Copyright Jonathan Carlson 2022

#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
using namespace std;

#include "initializer.h"

int main() {

	Initializer globalData;
	int x = 0;
	
	/**************************************  Main Game Loop ****************************************/
    while(globalData.window.isOpen()) {

		globalData.eventHandler.listen();
		globalData.window.draw(globalData.background);

		// cout << "Frames: " << x++ << endl;

		globalData.window.display();
   	}
   	/***********************************************************************************************/

	return 0;
}

#endif // MAIN_CPP