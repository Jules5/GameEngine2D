#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <controller/Config.h>

#include <model/Level.h>
#include <model/Character.h>

#include <view/CharacterView.h>
#include <view/LevelView.h>

using namespace std;
using namespace sf;


class Game
{	
	//Attributes
	private :
		static const unsigned int WIDTH, HEIGHT;

		RenderWindow* window;
		Config* config;
		Level level;
		LevelView level_view;
		View view;

		Character player;
		CharacterView player_view;


	// Methods
	public :
		Game();
		~Game();

		void init();
		void update(int dt);
		void checkCollisions();

		void setConfig(Config* c);
		void setWindow(RenderWindow* c);
};

/** @}*/

#endif
