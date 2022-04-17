#ifndef TESTHARNESS_CPP
#define TESTHARNESS_CPP

#include <iostream>
#include <map>
#include "miscellaneous_test.h"
#include "spriteSchematic_test.h"
using namespace std;

void printResults(const map<string, bool> & allResults) {
    cout << "############################# Unit Test Summary: #############################" << endl;
    for(auto i : allResults) {
        if(i.second) 
            cout << "Passed: " << i.first << endl;
        else
            cout << "FAILED: " << i.first << " <--Errors!" << endl;
    }
}

int main() {

    map<string, bool> allResults;
    SpriteSchematic_Test spriteSchematic_test;

    // allResults.insert(std::pair<string, bool>(
    //     "SpriteSchematic_Test::detectKeyword_test()", 
    //     spriteSchematic_test.detectKeyword_Test()
    // ));

    // allResults.insert(std::pair<string, bool>(
    //     "SpriteSchematic_Test::setNameImageWidthHeightFromRawData_test()",
    //     spriteSchematic_test.setNameImageWidthHeightFromRawData_test()
    // ));

    allResults.insert(std::pair<string, bool>(
        "Miscellaneous_Test::generateRandomNumber_test()",
        Miscellaneous_Test::generateRandomNumber_test()
    ));    

    allResults.insert(std::pair<string, bool>(
        "Miscellaneous_Test::convertStringToFloat_test()",
        Miscellaneous_Test::convertStringToFloat_test()
    ));      

    printResults(allResults);

    return 0;
}

#endif // TESTHARNESS_CPP