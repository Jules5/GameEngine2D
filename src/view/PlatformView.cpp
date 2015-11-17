#include "view/PlatformView.h"


PlatformView::PlatformView()
:target(NULL)
{
	init();
}



PlatformView::PlatformView(Platform* p)
:target(p)
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



void PlatformView::update()
{
	body.setSize(Vector2f(target->size.x,target->size.y));
	body.setPosition(Vector2f(target->position.x,target->position.y));
}


void PlatformView::display(RenderWindow* window)
{
	if(target->visible && target->size.y!=0) // On affiche que si la plateforme a une hauteur non nulle
		window->draw(body);
}

