#include "control/Game.h"


const unsigned int Game::WIDTH = 1600, Game::HEIGHT = 900;


Game::Game()
:window(NULL),config(NULL)
{}



Game::~Game()
{}


void Game::init()
{
    view.setCenter(WIDTH/2,HEIGHT/2);
    view.setSize(WIDTH,HEIGHT);
    
    window->setView(view);

    player = Character(Float2(200,800),Float2(40,40),20);

    level.environment.addDecor(Int2(0,0),Int2(WIDTH,HEIGHT),0,view.getCenter().x);
    level.environment.addPlatform(Int2(0,HEIGHT-10),Int2(WIDTH,10),0);
    level.environment.addPlatform(Int2(0,HEIGHT-110),Int2(WIDTH/2,10),0);
    level.environment.addPlatform(Int2(WIDTH/2+300,HEIGHT-110),Int2(WIDTH-WIDTH/2-300,10),0);
    level.environment.addPlatform(Int2(0,HEIGHT-210),Int2(WIDTH/5,10),0);
    level.environment.addPlatform(Int2(WIDTH/5+200,HEIGHT-210),Int2(WIDTH-WIDTH/5-200,10),0);
    level.environment.addPlatform(Int2(0,HEIGHT-310),Int2(WIDTH/2-100,10),0);
    level.environment.addPlatform(Int2(WIDTH/2+100,HEIGHT-310),Int2(WIDTH-WIDTH/2-100,10),0);
    level.environment.addPlatform(Int2(0,HEIGHT-410),Int2(WIDTH/6,10),0);
    level.environment.addPlatform(Int2(WIDTH/6+400,HEIGHT-410),Int2(WIDTH-WIDTH/6-400,10),0);
    level.environment.addPlatform(Int2(0,HEIGHT-510),Int2(WIDTH-300,10),0);
    level.environment.addPlatform(Int2(WIDTH-100,HEIGHT-510),Int2(100,10),0);
    level.environment.addPlatform(Int2(0,HEIGHT-610),Int2(WIDTH/4,10),0);
    level.environment.addPlatform(Int2(WIDTH/4+200,HEIGHT-610),Int2(WIDTH-WIDTH/4-200,10),0);
    level.environment.addPlatform(Int2(0,HEIGHT-750),Int2(WIDTH/3*2,10),0);
    level.environment.addPlatform(Int2(WIDTH/3*2+400,HEIGHT-750),Int2(WIDTH-WIDTH/3*2-200,10),0);
    level.environment.addPlatform(Int2(0,HEIGHT-900),Int2(WIDTH,10),0);
}



void Game::setWindow(RenderWindow* w)
{
    window = w;
}


void Game::setConfig(Config* c)
{
    config = c;
}



void Game::update(int dt)
{
    player.animate(dt);

    // Calcul des collisions
    checkCollisions();
}

void Game::display()
{
    level.display(window);
    player.display(window);
}



void Game::keyPressed(Keyboard::Key code)
{
    switch(code)
    {
        case Keyboard::Space : 
            player.jump();
            break;

        case Keyboard::Left : 
            player.run(true);
            break;

        case Keyboard::Right : 
            player.run(false);
            break;
    }
}


void Game::keyReleased(Keyboard::Key code)
{
    switch(code)
    {
        case Keyboard::Left : 
            player.stop();
            if(Keyboard::isKeyPressed(Keyboard::Right))
                player.run(false);
            break;

        case Keyboard::Right : 
            player.stop();
            if(Keyboard::isKeyPressed(Keyboard::Left))
                player.run(true);
            break;
    }
}



void Game::checkCollisions()
{
    const list<Platform>* platforms = level.environment.getPlatforms();

    // Player / Platform
    for(list<Platform>::const_iterator it = platforms->begin(); it != platforms->end(); it++)
        player.checkCollisions(&*it);
}