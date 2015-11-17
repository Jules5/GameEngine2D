#include "model/Character.h"

Character::Character()
:ObjetPhysique()
{
	init();
}


Character::Character(Float2 pos, Float2 siz, unsigned int m, float el)
:ObjetPhysique(pos,siz,m,el)
{
	init();
}


void Character::init()
{
	way = RIGHT;
}