// Copyright Jonathan Carlson 2022

#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
using namespace std;

#include "initializer.h"

int main() {

	Initializer globalData;
	
	/**************************************  Main Game Loop ****************************************/
    while(globalData.window.isOpen()) {
		globalData.window.draw(globalData.background);
		globalData.eventHandler.listen();



		globalData.window.display();
   	}
   	/***********************************************************************************************/

	return 0;
}

#endif // MAIN_CPP