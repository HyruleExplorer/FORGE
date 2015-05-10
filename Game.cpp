#include "Game.hpp"
#include <iostream>

Game::Game()
: TimePerFrame( sf::seconds( 1.f / 60.f ) )
{
    mWindow.setFramerateLimit(120);
    mWindow.setVerticalSyncEnabled(true);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    //MAIN LOOP
    while(!isExiting)
    {
        timeSinceLastUpdate += clock.restart();
        std::cout<< 1/timeSinceLastUpdate.asSeconds() <<"\n";

        //Pulisco lo schermo
        mWindow.clear();

        //Stabilizzo il framerate per essere costante su ogni macchina
        while( timeSinceLastUpdate > TimePerFrame )
        {
            timeSinceLastUpdate -= TimePerFrame;
            //Aggiorno tutti gli oggetti di gioco in base agli input
            GameMan.run();
            GameMan.update();
        }
        //Disegno e aggiorno lo sfondo dei vari livelli
        LevMan.run();
        //Disegno, inizializzo e aggiorno tutti gli oggetti di gioco
        GameMan.run();
        GameMan.update();


        //Mostro lo schermo con gli elementi disegnati sopra
        mWindow.display();


        //Per qualche motivo il seguente riduce di molto gli FPS:
        //TODO: scoprire il motivo
        //system("cls");
    }
}

//std::map<std::string,Level> Game::discoveredLevels;
Game::currentLevel Game::cLevel = MENU_0;
Game::currentAge Game::cAge = PRESENT;
bool Game::isExiting = false;
bool Game::change = false;
const int Game::SCREEN_WIDTH = 800;
const int Game::SCREEN_HEIGHT = 600;
const float Game::mSpeed = 2.f;
sf::RenderWindow Game::mWindow(sf::VideoMode( Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, 16 ), "The Chronicles of Time");
