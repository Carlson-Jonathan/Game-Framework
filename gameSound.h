// Copyright Jonathan Carlson 2022

#ifndef GAMESOUND_H
#define GAMESOUND_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <vector>
using namespace std;

class GameSound {
public:

	GameSound() {}
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

private: 

	sf::Music SFMLmusic;

};

#endif // GAMESOUND_H