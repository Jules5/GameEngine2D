#include "environment/Decor.h"

Decor::Decor(Int2 pos, Int2 siz, int z, int dx)
:PhysicObject(pos,siz),z(z),dx(dx)
{
	init();
}



Decor::Decor()
:PhysicObject()
{
	z = -1;
	init();
}


Decor::~Decor()
{
}



void Decor::init()
{
	if(z==0)
		this->z = -1;

	body.setFillColor(Color(128,128,128));
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



void Decor::display(RenderWindow* window)
{
	// Parallaxe
	IntRect rect = body.getTextureRect();
	rect.left = getDeltaX();
	body.setTextureRect(rect);

	// Display
	PhysicObject::display(window);
}