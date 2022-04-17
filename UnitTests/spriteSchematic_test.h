#ifndef SPRITESCHEMATIC_TEST_H
#define SPRITESCHEMATIC_TEST_H

#include <iostream>
#include <vector>
#include "../battle/spriteSchematic.h"
#include "../miscellaneous.h"
using namespace std;

class SpriteSchematic_Test : public SpriteSchematic {
public:

    SpriteSchematic_Test() {}

    bool detectKeyword_Test();
	bool setNameImageWidthHeightFromRawData_test();
	// void populateEntireSpriteSchematic();
    // void getDataFromLibraryAndSetRawData(string keyword);
	// void formatRawData();
	// void setSpeedFromRawData();
	// vector<pair<short, short>> setSpritePointsInActionArrays(vector<string> words);
	// void displayRawCharacterData();
	// void displaySchematicData();

    void printFailMessage(string funct, short testNum) {
        cout << "UNIT TEST FAILED: SpriteSchematic_Test::" << funct << "()\n"
             << "Incorrect result on test #" << testNum << endl;
    }
};
#endif // SPRITESCHEMATIC_TEST_H

/********************************************************************************
 * detectKeyword_Test()
 ********************************************************************************/
bool SpriteSchematic_Test::detectKeyword_Test() {
    vector<string> param1_testCases = {
        "This is the first line.",
        "Apple peanut butter beef rainbow.",
        "chocolate scary clown puppy nose.",
        "4567 7537 6541 7893 357 3240",
        "@#% % @#% #@ %23 5235 #@.",
        "     excessive    spacing      goes    here.",
        "$G$G  7775, sdf.",
        "!WORD! 123 123 132"
    };

    vector<string> param2_testCases = {
        "is", "Apple", "chocolate", "45678", "@#%", "excessive", "$G$G", "WORD"
    };

    vector<bool> expectedResults = { 
        false, true, true, false, true, false, true, false
    };

    for(short i = 0; i < param1_testCases.size(); i++) {
        string line = param1_testCases[i];
        string word = param2_testCases[i];
        bool result = detectKeyword(param1_testCases[i], param2_testCases[i]);
        bool expected = expectedResults[i];

        if(result != expected) {
            cout.setf(std::ios::boolalpha); 
            printFailMessage("detectKeyword_Test", i);
            return false;
        }
    }
    return true;
}

/********************************************************************************
 * setNameImageWidthHeightFromRawData_test()
 ********************************************************************************/
bool SpriteSchematic_Test::setNameImageWidthHeightFromRawData_test() {

    // Test 1
    rawData.push_back("Bozo clownPicture.jpg 123 456");
    rawData.push_back("bunny asdf.png 654 789");
    rawData.push_back("Filler filler filler filler filler");
    rawData.push_back("Don't break or anything ok?");

    setNameImageWidthHeightFromRawData();

    bool check1 = (name == "Bozo");
    bool check2 = (fileName == "clownPicture.jpg");
    bool check3 = (width == 123);
    bool check4 = (height == 456);
    if(!(check1 && check3 && check3 && check4)) {
        printFailMessage("setNameImageWidthHeightFromRawData_test", 1);
        displayRawCharacterData();
        return false;
    }

    // Test 2
    rawData.clear();
    rawData.push_back("!#%%%$^ #$%#$.#^$^ 2147483647 -2147483647 extra words");

    setNameImageWidthHeightFromRawData();

    check1 = (name == "!#%%%$^");
    check2 = (fileName == "#$%#$.#^$^");
    check3 = (width == 2147483647);
    check4 = (height == -2147483647);
    if(!(check1 && check3 && check3 && check4)) {
        printFailMessage("setNameImageWidthHeightFromRawData_test", 2);
        displayRawCharacterData();
        return false;
    }

    // Test 3
    rawData.clear();
    rawData.push_back(" WithAPreceedingSpace   triple.space.then.tab     000 0");

    setNameImageWidthHeightFromRawData();

    check1 = (name == "WithAPreceedingSpace");
    check2 = (fileName == "triple.space.then.tab");
    check3 = (width == 0);
    check4 = (height == 0);
    if(!(check1 && check3 && check3 && check4)) {
        printFailMessage("setNameImageWidthHeightFromRawData_test", 3);
        displayRawCharacterData();
        return false;
    } 

    // Test 4
    rawData.clear();    // Too big to fit in int!
    rawData.push_back("X Y 2147483648 -2147483648");

    try {
        setNameImageWidthHeightFromRawData();
    } catch(int exception) {
        width = 3712;
        height = 3911;
    }

    check1 = (name == "X");
    check2 = (fileName == "Y");
    check3 = (width == 3712);
    check4 = (height == 3911);
    if(!(check1 && check3 && check3 && check4)) {
        printFailMessage("setNameImageWidthHeightFromRawData_test", 4);
        displayRawCharacterData();
        return false;
    } 

    // Test 5
    rawData.clear(); // Invalid text entry
    rawData.push_back("X Y Hello World!");

    try {
        setNameImageWidthHeightFromRawData();
    } catch(int exception) {
        width = 3712;
        height = 3911;
    }

    check1 = (name == "X");
    check2 = (fileName == "Y");
    check3 = (width == 3712);
    check4 = (height == 3911);
    if(!(check1 && check3 && check3 && check4)) {
        printFailMessage("setNameImageWidthHeightFromRawData_test", 5);
        displayRawCharacterData();
        return false;
    } 

    return true;
}
