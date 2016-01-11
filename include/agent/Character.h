#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <cmath>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// #include <tools/tools.h>

#include <physic/PhysicObject.h>
#include <environment/Platform.h>

using namespace std;


class Character : public PhysicObject
{
	// Enumerations
	public :

	// Attributes
	private :
		bool left;
		bool running;
		float speed; //pixels/sec


	// Methods
	public :
		Character();
		Character(Float2 pos, Float2 siz, unsigned int m=0, float el=0.);

		void init();
		
		virtual void animate(int dt);
		virtual void display(RenderWindow* window);

		void run(bool l);
		void stop();
		void jump(int j=3);
		void checkCollisions(const Platform*);
};


#endif
