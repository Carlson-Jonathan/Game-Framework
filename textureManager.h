// Copyright Jonathan Carlson 2022

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
using namespace std;

#include <map>
#include <SFML/Graphics.hpp>
#include <vector>

class TextureManager {
public:

	TextureManager() {
		populateTextures();
	}

	map<string, sf::Texture> textures;

private:
	
	sf::Texture texture;

	/***********************************************************************************************
	* When you need to add new textures to the game, add the information to this vector. The first
	* element is a unique name for your image, and the 2nd is the relative path to the file. The
	* first element is the key word you will use to access the textures from other files.
	***********************************************************************************************/
	vector< pair<string, string> > textureFilePaths = {
		{"background", "Images/battleback4.png"}
	};

	void populateTextures() {

		for(int i = 0; i < textureFilePaths.size(); i++) {
			if (!texture.loadFromFile(textureFilePaths[i].second)) 
				cout << "ERROR: Unable to load image '" << textureFilePaths[i].second << "'" << endl;
			else 
				textures.insert({textureFilePaths[i].first, texture});
		}
	}

};

#endif // TEXUTUREMANAGER_H