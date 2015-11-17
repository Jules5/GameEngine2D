#include "controller/MasterClass.h"


MasterClass::MasterClass()
{
  title = "Jeu 2D";

  window.setKeyRepeatEnabled(false);
  window.setMouseCursorVisible(false);

  config.difficulty = Config::NORMAL;
  config.fullscreen = true;
  config.resolution = VideoMode::getDesktopMode();
  config.vsync = true;

  applyConfig();

  game.setWindow(&window);
  game.setConfig(&config);
  game.init();

  play = true;
}


MasterClass::~MasterClass()
{
}	


void MasterClass::playApp()
{
	Clock clock;
	
  while (window.isOpen() && play)
    {
        Event event;
        while(window.pollEvent(event))
        {
        	switch(event.type)
            {
            	case Event::Closed :
               		play = false;
               		break;

               	case Event::KeyPressed :
               		switch(event.key.code)
               		{
               			case Keyboard::Escape :
               				play = false;
               				break;
               		}
               		break;
            } 
        }

        // cout << getFramerate(&clock) << "FPS" << endl;

        game.update(clock.restart().asMilliseconds());
        window.clear();
        game.display();
        window.display();
    }

    window.close();
}




void MasterClass::applyConfig()
{
	if(config.fullscreen)
		window.create(VideoMode::getDesktopMode(), title, Style::Fullscreen);
	else
		window.create(config.resolution, title, Style::Default);

  window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(config.vsync);
}


float MasterClass::getFramerate(Clock* c)
{
  return 1/(c->getElapsedTime().asSeconds());
}