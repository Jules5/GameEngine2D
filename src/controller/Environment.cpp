#include "controller/Environment.h"



Environment::Environment()
{	

}




Environment::~Environment()
{
	decors.clear();
	decors_views.clear();
	platforms.clear();
	platforms_views.clear();
}



void Environment::update(int center)
{
	// Décors
	for(list<Decor>::iterator it = decors.begin(); it != decors.end(); it++)
		(*it).animate(center);
	for(list<DecorView>::iterator it = decors_views.begin(); it != decors_views.end(); it++)
		(*it).update();

	// Plate-formes
	// for(list<Platform>::iterator it = platforms.begin(); it != platforms.end(); it++)
	// 	(*it).animate();
	for(list<PlatformView>::iterator it = platforms_views.begin(); it != platforms_views.end(); it++)
		(*it).update();
}



void Environment::display(RenderWindow* window)
{
	// Décors
	for (list<DecorView>::iterator it = decors_views.begin(); it != decors_views.end(); it++)
		(*it).display(window);

	// PLate-forme
	for (list<PlatformView>::iterator it = platforms_views.begin(); it != platforms_views.end(); it++)
		(*it).display(window);
}



void Environment::addDecor(Int2 pos, Int2 siz, Texture* tex, int z)
{
	// Modèle
	Decor dec(pos,siz,z);
	decors.push_back(dec);

	// Vue
	DecorView dec_v(&decors.back());
	// if(tex != NULL)
	// 	dec_v.setTexture(tex,Bool2(true,false));
	decors_views.push_back(dec_v);
}


void Environment::addPlatform(Int2 pos, Int2 siz, int wl, bool b, Texture* tex, Bool2 tex_repeat)
{
	// Modèle
	Platform plt(pos,siz,wl);
	plt.setVisible(b);
	platforms.push_back(plt);

	// Vue
	PlatformView plt_v(&platforms.back());
	// if(tex != NULL)
	// 	plt_v.setTexture(tex,tex_repeat);
	platforms_views.push_back(plt_v);
}
