#include <iostream>
#include "Level_1.hpp"
#include "Game.hpp"

Level_1::Level_1()
{
    /*switch( Game::cAge )
    {
    case( Game::PAST ):
        setBackground( "level_1_PAST.png" );
        break;
    case( Game::FUTURE ):
        setBackground( "level_1_FUTURE.png" );
        break;
    default:*/
        mFileName = "level_1.png";
        mTexture.loadFromFile( mFileName );
        mBackground.setTexture( mTexture );
     //   break;
    //}
}

//Disegno lo sfondo e tutti gli elementi all'interno del Livello 1
void Level_1::draw()
{
    Game::mWindow.draw( mBackground );
}

//Carico la texture dello sfondo
void Level_1::setColor( sf::Color& mColor )
{
    mBackground.setColor( mColor );
}

//Catturo l'input da tastiera e cambio il livello visualizzato a schermo di conseguenza
void Level_1::getInput()
{
    sf::Event mEvent;
    while( Game::mWindow.pollEvent( mEvent ) )
    {
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
        {
            Game::cLevel = Game::MENU_0;
        }
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Return) )
        {
            Game::cLevel = Game::LEV_2;
        }
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

