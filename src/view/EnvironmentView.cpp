#include "view/EnvironmentView.h"


EnvironmentView::EnvironmentView()
:target(NULL)
{
}


EnvironmentView::EnvironmentView(Environment* c)
:target(c)
{
}


EnvironmentView::~EnvironmentView()
{
}


void EnvironmentView::update(RenderWindow* window)
{
	// Récupération des éléments de l'environnement
	list<Decor>* decors = target->getDecors();
	list<Platform>* platforms = target->getPlatforms();

	// Mise à jour des décors
	for(list<Decor>::iterator it = decors->begin(); it != decors->end(); it++)
	{
		decor_view.setTarget(&*it);
        decor_view.update(window);
	}

	// Mise à jour des plateformes
	for(list<Platform>::iterator it = platforms->begin(); it != platforms->end(); it++)
	{
		platform_view.setTarget(&*it);
        platform_view.update(window);
	}
}