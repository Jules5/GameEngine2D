#ifndef MASTERCLASS_H
#define MASTERCLASS_H

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <control/Game.h>
#include <control/Config.h>

using namespace std;
using namespace sf;


class MasterClass
{
	// Attributes
	private :

		RenderWindow window;
		Game game; 
		Config config;

		string title;
		bool play;


	// Methods
	public :
		MasterClass();
		~MasterClass();

		void playApp();
		void playGame();

		float getFramerate(Clock*) const;

};

/** @}*/

#endif
