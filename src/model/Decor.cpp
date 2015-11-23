#include "model/Decor.h"

Decor::Decor(Int2 pos, Int2 siz, int z, int dx)
:PhysicObject(pos,siz),z(z),dx(dx)
{
	if(z==0)
		this->z = -1;
}



Decor::Decor()
:PhysicObject()
{
	z = -1;
}


Decor::~Decor()
{
}


void Decor::print(ostream& os) const 
{

}


void Decor::animate(int x)
{
	// Décalage parallaxe
	int offset = x - dx;
	if(offset > 0)
		dx += offset / z;
}