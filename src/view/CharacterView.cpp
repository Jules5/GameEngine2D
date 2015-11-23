#include "view/CharacterView.h"


CharacterView::CharacterView()
:PhysicObjectView()
{
	init();
}


CharacterView::CharacterView(Character* c)
:PhysicObjectView(c)
{
	init();
}


CharacterView::~CharacterView()
{
}


void CharacterView::init()
{
	body.setFillColor(Color(30,30,30));
}




void CharacterView::update(RenderWindow* window)
{
	PhysicObjectView::update(window);
}