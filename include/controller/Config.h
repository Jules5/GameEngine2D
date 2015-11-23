#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <SFML/Window.hpp>
#include <tools/tools.h>

using namespace std;
using namespace sf;


class Config
{
	public :

		// Enumeration
		enum Difficulty {EASY,NORMAL,HARD,HARDEST,HARDESTEST};
		
		// Attributes
		Difficulty difficulty; 
		bool fullscreen; 
		VideoMode resolution;
		bool vsync;

		// Methods
		Config();
		~Config();

		bool loadFromXML(string filename);  // TODO
		bool saveToXML(string filename) const;  // TODO
};

/** @}*/

#endif
