#include "view/DecorView.h"


DecorView::DecorView()
:PhysicObjectView()
{
	init();
}


DecorView::DecorView(Decor* d)
:PhysicObjectView(d)
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





void DecorView::update(RenderWindow* window)
{
	// Parallaxe
	IntRect rect = body.getTextureRect();
	rect.left = ((Decor*)target)->getDeltaX();
	body.setTextureRect(rect);

	PhysicObjectView::update(window);}