#ifndef ENVIRONMENTVIEW_H
#define ENVIRONMENTVIEW_H

#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <model/Environment.h>

#include <view/DecorView.h>
#include <view/PlatformView.h>

using namespace std;
using namespace sf;



class EnvironmentView
{
	// Attributes
	private :
		Environment* target;
		DecorView decor_view;
		PlatformView platform_view;


	// Methods
	public :
		EnvironmentView();
		EnvironmentView(Environment*);
		~EnvironmentView();

		void update(RenderWindow* window);
};



#endif
