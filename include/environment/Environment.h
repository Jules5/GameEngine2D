#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <list>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <environment/Decor.h>
#include <environment/Platform.h>

using namespace std;
using namespace sf;


class Environment
{
	private :
		list<Decor> decors; 
		list<Platform> platforms; 


	public :
		Environment();
		~Environment();

		void update(int center); 
		virtual void display(RenderWindow* window);
		
		void addDecor(Int2 pos, Int2 siz, Texture* tex=NULL, int z=0);
		void addPlatform(Int2 pos, Int2 siz, int wl, bool v=true, Texture* tex=NULL, Bool2 tex_repeat=Bool2(false,false));
		//void addDestructible(); // TODO

		list<Decor>* getDecors() {return &decors;};
		list<Platform>* getPlatforms() {return &platforms;};
};

/** @}*/

#endif