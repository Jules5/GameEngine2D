#include "controller/Level.h"



Level::Level()
{
}




Level::~Level()
{
	for(unsigned int i = 0; i < musics.size(); i++)
		delete(musics[i]);
		
	for(unsigned int i = 0; i < textures.size(); i++)
		delete(textures[i]);
}



void Level::display(RenderWindow* window)
{
	environment.display(window);
}


void Level::loadFromFile(string filename, Config* config)
{
}


// void Level::addDecor(Int2 siz, Texture* tex, int z)
// {
// 	environment.addDecor(siz,tex,z);
// }


// void Level::addPlatform(Int2 pos, Int2 siz, int wl, Texture* tex)
// {
// 	environment.addPlatform(pos,siz,wl,tex);
// }


void Level::playMusic(int id)
{

}

