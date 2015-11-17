#include "view/DecorView.h"


DecorView::DecorView()
:target(NULL)
{
	init();
}



DecorView::DecorView(Decor* d)
:target(d)
{	
	init();
}


DecorView::~DecorView()
{
}


void DecorView::init()
{
	body.setFillColor(Color(128,128,128));
}



void DecorView::update()
{
	body.setSize(Vector2f(target->size.x,target->size.y));
	body.setPosition(Vector2f(target->position.x,target->position.y));

	// Parallaxe
	IntRect rect = body.getTextureRect();
	rect.left = target->dx;
	body.setTextureRect(rect);
}



void DecorView::display(RenderWindow* window)
{
	window->draw(body);
}