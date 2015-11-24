#include "controller/MasterClass.h"


MasterClass::MasterClass()
{
  title = "Jeu 2D";

  window.setKeyRepeatEnabled(false);
  window.setMouseCursorVisible(false);

  config.difficulty = Config::NORMAL;
  config.fullscreen = true;
  config.resolution = VideoMode::getDesktopMode();
  config.vsync = false;

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

              case Event::KeyReleased :
                  game.keyReleased(event.key.code);
                  break;

             	case Event::KeyPressed :
             		if(event.key.code == Keyboard::Escape)
                  play = false;
                else
                  game.keyPressed(event.key.code);
             		break;
            } 
        }

        // cout << getFramerate(&clock) << "FPS" << endl;

        window.clear();
        game.update(clock.restart().asMilliseconds());
        window.display();
    }

    window.close();
}




void MasterClass::applyConfig()
{
	if(config.fullscreen)
    //window.create(VideoMode::getDesktopMode(), title, Style::Fullscreen);
		window.create(VideoMode::getDesktopMode(), title, Style::None);
	else
		window.create(config.resolution, title, Style::Default);

  window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(config.vsync);
}


float MasterClass::getFramerate(Clock* c) const
{
  return 1/(c->getElapsedTime().asSeconds());
}