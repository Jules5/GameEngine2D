#include "model/Character.h"

Character::Character()
:PhysicObject()
{
	init();
}


Character::Character(Float2 pos, Float2 siz, unsigned int m, float el)
:PhysicObject(pos,siz,m,el)
{
	init();
}


void Character::init()
{
	elasticity = 0;
	way = RIGHT;
	state = IDLE;
}


void Character::animate(int dt)
{
	PhysicObject::animate(dt);
}


void Character::walk(CharacterWay w)
{
	state = RUN;
	way = w;
}