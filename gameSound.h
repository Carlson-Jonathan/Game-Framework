// Copyright Jonathan Carlson 2022

#ifndef GAMESOUND_H
#define GAMESOUND_H

#include <iostream>
using namespace std;

#include <SFML/Audio.hpp>
#include <vector>
#include "miscellaneous.h"

class GameSound {
public:

	GameSound() {
		SFMLmusic.setLoop(true);
	}

	void loadAndPlayMusic(string song) {
		if(!SFMLmusic.openFromFile(song)) {
			cout << "ERROR: Unable to load file '" << song << "'" << endl;
			return;
		}
		SFMLmusic.play();
	}

	void loadAndPlayRandomSongFromDirectory() {}

private: 

	sf::Music SFMLmusic;

};

#endif // GAMESOUND_H