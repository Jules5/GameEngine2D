#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <cmath>

// #include <tools/tools.h>

#include <model/ObjetPhysique.h>

using namespace std;


class Character : public ObjetPhysique
{

	public :

		enum CharacterWay {LEFT, RIGHT};

		CharacterWay way;


		Character();
		Character(Float2 pos, Float2 siz, unsigned int m=0, float el=0.5);

		void init();

};


#endif
