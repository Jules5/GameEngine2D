#include "controller/Config.h"


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



bool Config::loadFromXML(string filename)
{
	return false;
}



bool Config::saveToXML(string filename) const
{
	return false;
}
