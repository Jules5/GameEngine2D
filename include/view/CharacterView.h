#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Character.h>

using namespace std;
using namespace sf;



class CharacterView
{

	public :

		Character* target;
		RectangleShape body; 


	public :

		CharacterView();
		CharacterView(Character*);
		~CharacterView();

		void init();

		void update();
		void display(RenderWindow* window);

};



#endif
