#include "control/Config.h"


/**
 * Constructeur
 */
Config::Config()
{
	difficulty = NORMAL;
	fullscreen = false;
	resolution = VideoMode(800,600);
	vsync = false;
}



Config::~Config()
{}


void Config::apply(RenderWindow* window, String title)
{
	if(fullscreen)
		window->create(VideoMode::getDesktopMode(), title, Style::None);
	else
		window->create(resolution, title, Style::Default);

	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(vsync);
}


bool Config::loadFromXML(string filename)
{
	return false;
}



bool Config::saveToXML(string filename) const
{
	return false;
}
