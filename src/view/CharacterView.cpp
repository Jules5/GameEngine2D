#include "view/CharacterView.h"


CharacterView::CharacterView()
:target(NULL)
{
	init();
}


CharacterView::CharacterView(Character* c)
:target(c)
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


void CharacterView::update()
{
	body.setSize(Vector2f(target->size.x,target->size.y));
	body.setPosition(Vector2f(target->position.x,target->position.y));
}



void CharacterView::display(RenderWindow* window)
{
	window->draw(body);
}