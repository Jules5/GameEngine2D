#ifndef LEVELVIEW_H
#define LEVELVIEW_H

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Level.h>

#include <view/EnvironmentView.h>

using namespace std;
using namespace sf;



class LevelView
{
	// Attributes
	private :
		Level* target;
		EnvironmentView environment_view; 


	// Methods
	public :
		LevelView();
		LevelView(Level*);
		~LevelView();

		void init();
		void update(RenderWindow* window);

};



#endif
