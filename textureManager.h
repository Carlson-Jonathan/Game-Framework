// Copyright Jonathan Carlson 2022

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
using namespace std;

#include <dirent.h>     // directory
#include <cstring>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

/***************************************************************************************************
* How to use:
* 1.) List all directory paths containing images you wish to load in the 'textureDirectories' variable.
* 2.) getAllFileNamesFromDirectory() fills 'textureFilePaths' with file names and paths (strings).
* 3.) populateTextures() fills public 'textures' with sf::texture files and keys to access them.
***************************************************************************************************/
class TextureManager {
public:

	TextureManager() {
		loadTextureFilePaths();
		populateTextures();
	}

	map<string, sf::Texture> textures;

private:
	
	// All paths to directories containing images you wish to load go here (relative to this file).
	vector<string> textureDirectories = {
		"./Images/"
	};

	sf::Texture texture;
	vector< pair<string, string> > textureFilePaths;
	
	//----------------------------------------------------------------------------------------------

	vector<string> getAllFileNamesFromDirectory(const char *path) {
    	struct dirent *entry;
    	vector<string> files;
    	DIR *directory = opendir(path);

    	if (directory != NULL) {
	        while((entry = readdir(directory)) != NULL) {
            	string file = entry->d_name;
	                files.push_back(file);
        	}
    	}

	    closedir(directory);
	    return files;
	}

	//----------------------------------------------------------------------------------------------

	string getTextureName(string fileName) {
		size_t found = fileName.find('.');
		string textureName;

    	if(found != string::npos)
			textureName = fileName.substr(0, found);

		return textureName;
	}

	//----------------------------------------------------------------------------------------------

	void loadTextureFilePaths() {
		for(auto dir : textureDirectories) {

			char cDir[dir.length()];
			strcpy(cDir, dir.c_str()); 

			vector textureFiles = getAllFileNamesFromDirectory(cDir);

			for(auto file : textureFiles) {

				if(file == "." || file == "..")
					continue;

				textureFilePaths.push_back({getTextureName(file), (dir + "/" + file)});
			}
		}
	}

	//----------------------------------------------------------------------------------------------

	void populateTextures() {
		for(int i = 0; i < textureFilePaths.size(); i++) {
			if(!texture.loadFromFile(textureFilePaths[i].second)) 
				cout << "ERROR: Unable to load image '" << textureFilePaths[i].second << "'" << endl;
			else 
				textures.insert({textureFilePaths[i].first, texture});
		}
	}

};

#endif // TEXUTUREMANAGER_H