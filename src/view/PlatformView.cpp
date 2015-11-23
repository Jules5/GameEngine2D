#include "view/PlatformView.h"


PlatformView::PlatformView()
:PhysicObjectView()
{
	init();
}



PlatformView::PlatformView(Platform* p)
:PhysicObjectView(p)
{
	init();
}


PlatformView::~PlatformView()
{
}


void PlatformView::init()
{
	body.setFillColor(Color(220,220,220));
}





void PlatformView::update(RenderWindow* window)
{
	PhysicObjectView::update(window);

	//if(target->visible && target->size.y!=0) // On affiche que si la plateforme a une hauteur non nulle
	//	window->draw(body);
}

