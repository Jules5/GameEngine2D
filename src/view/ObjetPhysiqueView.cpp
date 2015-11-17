#include "view/ObjetPhysiqueView.h"


ObjetPhysiqueView::ObjetPhysiqueView()
:target(NULL)
{
	init();
}


ObjetPhysiqueView::ObjetPhysiqueView(ObjetPhysique* obj)
:target(obj)
{
	init();
}


ObjetPhysiqueView::~ObjetPhysiqueView()
{
}


void ObjetPhysiqueView::init()
{
	body.setFillColor(Color(30,30,30));
}


void ObjetPhysiqueView::update()
{
	body.setSize(Vector2f(target->size.x,target->size.y));
	body.setPosition(Vector2f(target->position.x,target->position.y));
}



void ObjetPhysiqueView::display(RenderWindow* window)
{
	window->draw(body);
}