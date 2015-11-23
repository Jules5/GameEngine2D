#ifndef DECORVIEW_H
#define DECORVIEW_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Decor.h>

#include <view/PhysicObjectView.h>

using namespace std;
using namespace sf;



class DecorView : public PhysicObjectView
{
	// Attributes
	private :


	// Methodes
	public :
		DecorView();
		DecorView(Decor*);
		~DecorView();

		void init();
		void update(RenderWindow* window);
};


/** @}*/

#endif
