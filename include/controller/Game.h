#ifndef GAME_H
#define GAME_H

/*!
 * \file Game.h
 * \author Jules
 * \brief Déclaration de la classe Game
 * \addtogroup Controller 
 * @{
 */

#include <iostream>
#include <list>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <controller/Config.h>
#include <controller/Level.h>

#include <model/Character.h>
#include <model/Decor.h>
#include <model/Platform.h>

#include <view/CharacterView.h>
#include <view/DecorView.h>

using namespace std;
using namespace sf;



/*! \class Game
 * \brief Gère le jeu.
 */
class Game
{	
	private :

		static const unsigned int WIDTH, HEIGHT;

		RenderWindow* window;
		Config* config;
		Level level;
		View view;

		Character player;
		CharacterView player_view;

	public :

		Game();
		~Game();

		void init();
		
		void setConfig(Config* c);
		void setWindow(RenderWindow* c);

		void update(int dt);
		void display();

		void checkCollisions();

};

/** @}*/

#endif
