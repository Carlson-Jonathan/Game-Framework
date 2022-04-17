// Copyright Jonathan Carlson 2022

#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "eventHandler.h"
#include "gameSound.h"
#include "textureManager.h"

class Initializer {
public:

	Initializer() : window(sf::VideoMode(screenWidth, screenHeight), "War Card Game"), 
					eventHandler(window, screenWidth, screenHeight) {
						
		window.setFramerateLimit(frameRate);

		// Draw background
		background.setTexture(textures.textures["backgroundInSubFolder"]);  
		background.setOrigin(0, 0);	

		// Play song
		gameSound.loadAndPlayMusic("Sounds/Music/ExampleSong.ogg");
	}

	unsigned int screenWidth  = 1333;
	unsigned int screenHeight = 750;
	short frameRate           = 60;

	sf::RenderWindow window;
	sf::Sprite background;

	EventHandler   eventHandler;
	GameSound      gameSound;
	TextureManager textures;	
};

#endif // INITIALIZER_H