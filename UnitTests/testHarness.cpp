#ifndef TESTHARNESS_CPP
#define TESTHARNESS_CPP

#include <iostream>
#include <map>
using namespace std;

#include "miscellaneous_test.h"

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

    allResults.insert(pair<string, bool>(
        "Miscellaneous_Test::generateRandomNumber_test()",
        Miscellaneous_Test::generateRandomNumber_test()
    ));    

    allResults.insert(pair<string, bool>(
        "Miscellaneous_Test::convertStringToFloat_test()",
        Miscellaneous_Test::convertStringToFloat_test()
    ));      

    printResults(allResults);

    return 0;
}

#endif // TESTHARNESS_CPP