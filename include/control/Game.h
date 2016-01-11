#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <control/Config.h>
#include <level/Level.h>
#include <physic/PhysicObject.h>
#include <agent/Character.h>

using namespace std;
using namespace sf;


class Game
{	
	//Attributes
	private :
		static const unsigned int WIDTH, HEIGHT;

		RenderWindow* window;
		Config* config;
		View view;

		Level level;

		Character player;


	// Methods
	public :
		Game();
		~Game();

		void init();
		void update(int dt);
		void display();
		void keyPressed(Keyboard::Key code);
		void keyReleased(Keyboard::Key code);
		void checkCollisions();

		void setConfig(Config* c);
		void setWindow(RenderWindow* c);
};

/** @}*/

#endif
