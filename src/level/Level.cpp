#include "level/Level.h"



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




void Level::loadFromFile(string filename)
{
}



void Level::playMusic(int id)
{

}

