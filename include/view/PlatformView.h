#ifndef PLATFORMVIEW_H
#define PLATFORMVIEW_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Platform.h>

#include <view/PhysicObjectView.h>

using namespace std;
using namespace sf;



class PlatformView : public PhysicObjectView
{

	// Attributes
	private :


	// Methods
	public :
		PlatformView();
		PlatformView(Platform*);
		~PlatformView();

		void init();
		void update(RenderWindow* window);
};


/** @}*/

#endif
