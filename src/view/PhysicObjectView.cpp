#include "view/PhysicObjectView.h"


PhysicObjectView::PhysicObjectView()
:target(NULL)
{
	init();
}


PhysicObjectView::PhysicObjectView(PhysicObject* obj)
:target(obj)
{
	init();
}


PhysicObjectView::~PhysicObjectView()
{
}


void PhysicObjectView::init()
{
	body.setFillColor(Color(30,30,30));
}




void PhysicObjectView::update(RenderWindow* window)
{
	// Mise à jour
	body.setSize(target->getSize().vector());
	body.setPosition(target->getPosition().vector());

	// Affichage
	window->draw(body);
}