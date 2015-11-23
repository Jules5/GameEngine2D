#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <cmath>

// #include <tools/tools.h>

#include <model/PhysicObject.h>

using namespace std;


class Character : public PhysicObject
{
	// Enumerations
	public :
		enum CharacterWay {LEFT, RIGHT};
		enum CharacterState {IDLE, RUN};


	// Attributes
	private :
		CharacterWay way;
		CharacterState state;


	// Methods
	public :
		Character();
		Character(Float2 pos, Float2 siz, unsigned int m=0, float el=0.);

		void init();
		virtual void animate(int dt);
		void walk(CharacterWay);
};


#endif
