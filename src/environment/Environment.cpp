#include "environment/Environment.h"



Environment::Environment()
{	

}




Environment::~Environment()
{
	decors.clear();
	platforms.clear();
}



void Environment::update(int center)
{
	// Décors
	//for(list<Decor>::iterator it = decors.begin(); it != decors.end(); it++)
		//(*it).animate(center);
	//for(list<DecorView>::iterator it = decors_views.begin(); it != decors_views.end(); it++)
		// (*it).update();

	// Plate-formes
	// for(list<Platform>::iterator it = platforms.begin(); it != platforms.end(); it++)
	// 	(*it).animate();
	//for(list<PlatformView>::iterator it = platforms_views.begin(); it != platforms_views.end(); it++)
		// (*it).update();
}



void Environment::display(RenderWindow* window)
{
	// Récupération des éléments de l'environnement
	list<Decor>* decors = getDecors();
	list<Platform>* platforms = getPlatforms();

	// Affichage des décors
	for(list<Decor>::iterator it = decors->begin(); it != decors->end(); it++)
		it->display(window);

	// Affichage des plateformes
	for(list<Platform>::iterator it = platforms->begin(); it != platforms->end(); it++)
		it->display(window);
}


void Environment::addDecor(Int2 pos, Int2 siz, Texture* tex, int z)
{
	Decor dec(pos,siz,z);
	decors.push_back(dec);

	// Vue
	// DecorView dec_v(&decors.back());
	// // if(tex != NULL)
	// // 	dec_v.setTexture(tex,Bool2(true,false));
	// decors_views.push_back(dec_v);
}


void Environment::addPlatform(Int2 pos, Int2 siz, int wl, bool b, Texture* tex, Bool2 tex_repeat)
{
	Platform plt(pos,siz,wl,b);
	platforms.push_back(plt);

	// Vue
	// PlatformView plt_v(&platforms.back());
	// // if(tex != NULL)
	// // 	plt_v.setTexture(tex,tex_repeat);
	// platforms_views.push_back(plt_v);
}
