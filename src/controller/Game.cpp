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

    level_view = LevelView(&level);
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
    // Mise à jour du modèle
    // level.environment.update(view.getCenter().x-view.getSize().x/2);
    player.animate(dt);

    // Calcul des collisions
    checkCollisions();

    // Mise à jour des vues
    level_view.update(window);
    player_view.update(window);
}



void Game::checkCollisions()
{
    const list<Platform>* platforms = level.environment.getPlatforms();

    // Player / Platform
    for(list<Platform>::const_iterator it = platforms->begin(); it != platforms->end(); it++)
        player.checkCollisions((PhysicObject*)&*it);
}