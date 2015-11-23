#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Character.h>

#include <view/PhysicObjectView.h>

using namespace std;
using namespace sf;



class CharacterView : public PhysicObjectView
{
	// Attributes
	private :


	// Methods
	public :
		CharacterView();
		CharacterView(Character*);
		~CharacterView();

		void init();
		void update(RenderWindow* window);

};



#endif
