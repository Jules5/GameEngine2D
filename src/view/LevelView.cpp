#include "view/LevelView.h"


LevelView::LevelView()
:target(NULL)
{
	init();
}


LevelView::LevelView(Level* c)
:target(c)
{
	environment_view = EnvironmentView(&target->environment);
	init();
}


LevelView::~LevelView()
{
}


void LevelView::init()
{
}



void LevelView::update(RenderWindow* window)
{
	if(target == NULL) 
		return;

	environment_view.update(window);
}