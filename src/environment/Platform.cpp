#include "environment/Platform.h"

Platform::Platform(Int2 pos, Int2 siz, int wl, bool vis)
:PhysicObject(pos,siz), walkline(wl), visibility(vis)
{
	init();
}



Platform::Platform()
:PhysicObject(), walkline(0), visibility(true)
{
	init();
}


Platform::~Platform()
{
}


void Platform::init()
{
	if(walkline > size.y)
		walkline = size.y;

	body.setFillColor(Color(220,220,220));
}



void Platform::display(RenderWindow* window)
{
	PhysicObject::display(window);

	//if(target->visible && target->size.y!=0) // On affiche que si la plateforme a une hauteur non nulle
	//	window->draw(body);
}





void Platform::print(ostream& os) const 
{

}

