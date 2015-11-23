#ifndef OBJETPHYSIQUEVIEW_H
#define OBJETPHYSIQUEVIEW_H

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/PhysicObject.h>

using namespace std;
using namespace sf;


class PhysicObjectView
{
	// Attributes
	protected :
		PhysicObject* target;
		RectangleShape body; 


	// Methods
	public :
		PhysicObjectView();
		PhysicObjectView(PhysicObject*);
		~PhysicObjectView();

		void init();
		void update(RenderWindow* window);

		inline void setTarget(PhysicObject* o) {target=o;};

};


/** @}*/

#endif
