#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Environment.h>

using namespace std;


class Level
{

	// Attributes
	public :
		Environment environment; 
		
	private :
		vector<Music*> musics; 
		vector<Texture*> textures; 


	// Methods
	public :
		Level();
		~Level();

		void loadFromFile(string filename);
		void playMusic(int id);
};

/** @}*/

#endif
