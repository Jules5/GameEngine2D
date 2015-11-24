#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <cmath>

// #include <tools/tools.h>

#include <model/PhysicObject.h>
#include <model/Platform.h>

using namespace std;


class Character : public PhysicObject
{
	// Enumerations
	public :

	// Attributes
	private :
		bool left;
		bool running;


	// Methods
	public :
		Character();
		Character(Float2 pos, Float2 siz, unsigned int m=0, float el=0.);

		void init();
		virtual void animate(int dt);
		void run(bool l);
		void stop();
		void jump(int j=3);
		void checkCollisions(const Platform*);
};


#endif
