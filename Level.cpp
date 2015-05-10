#include "Level.hpp"
#include "Game.hpp"
#include <iostream>

Level::Level()
:   mFileName("main_menu.png")
{
    mTexture.loadFromFile( mFileName );
    mBackground.setTexture( mTexture );
}

//Carico la texture dello sfondo
void Level::setColor( sf::Color& mColor )
{
    mBackground.setColor( mColor );
}

void Level::setBackground( std::string& newFileName )
{
    std::cout<<"Cambio Background\n";
    mTexture.loadFromFile( newFileName );
    mBackground.setTexture( mTexture );
}

//disegno lo sfondo su schermo
void Level::draw()
{
    Game::mWindow.draw( mBackground );
}

//Catturo l'input della tastiera e cambio gli schermi visualizzati di conseguenza
void Level::getInput()
{
    sf::Event mEvent;
    while( Game::mWindow.pollEvent( mEvent ) )
    {
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Game::cLevel != Game::MENU_0 )
            Game::cLevel = Game::MENU_0;
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Game::cLevel == Game::MENU_0 )
            Game::isExiting = true;
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && Game::cLevel == Game::MENU_0 )
            Game::cLevel = Game::LEV_1;

        switch( mEvent.type )
        {
            case sf::Event::Closed:
                Game::isExiting = true;
                break;
            default:
                break;
        }
    }
}

void Level::update( std::string& newFileName)
{
    switch( Game::cAge )
    {
    case( Game::PAST ):
        if(Game::change)
        {
            newFileName += "_PAST.png";
            setBackground( newFileName );
            Game::change = false;
        }
        break;

    case( Game::FUTURE ):
        if(Game::change)
        {
            newFileName += "_FUTURE.png";
            setBackground( newFileName );
            Game::change = false;
        }
        break;

    case( Game::PRESENT ):
        if(Game::change)
        {
            newFileName += ".png";
            setBackground( newFileName );
            Game::change = false;
        }

    default:
        break;
    }
}



