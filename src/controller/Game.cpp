#include "controller/Game.h"


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

    player = Character(Float2(200,100),Float2(100,100),20);
    player_view = CharacterView(&player);
    player.addMovement(Int2(40,-30));

    level.environment.addDecor(Int2(0,0),Int2(WIDTH,HEIGHT),0,view.getCenter().x);
    level.environment.addPlatform(Int2(0,HEIGHT-50),Int2(WIDTH,50),0);
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
    level.environment.update(view.getCenter().x-view.getSize().x/2);

    player.animate(dt);
    checkCollisions();
    player_view.update();
}


void Game::display()
{
    level.environment.display(window);

    player_view.display(window);
}



void Game::checkCollisions()
{
    // Joueur / Platform
    for(list<Platform>::iterator it = level.environment.platforms.begin(); it != level.environment.platforms.end(); it++)
        player.checkCollisions((ObjetPhysique*)&*it);
}