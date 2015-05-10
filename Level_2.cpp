#include "Level_2.hpp"
#include "Game.hpp"
#include <iostream>

Level_2::Level_2()
{
    /*switch( Game::cAge )
    {
    case( Game::PAST ):
        setBackground( "level_2_PAST.png" );
        break;
    case( Game::FUTURE ):
        setBackground( "level_2_FUTURE.png" );
        break;
    default:*/
        mFileName = "level_2.png";
        mTexture.loadFromFile( mFileName );
        mBackground.setTexture( mTexture );
    //    break;
    //}
}

//Disegno lo sfondo
void Level_2::draw()
{
    Game::mWindow.draw( mBackground );
}

//Carico la texture dello sfondo
void Level_2::setColor( sf::Color& mColor )
{
    mBackground.setColor( mColor );
}

//Catturo l'input da tastiera e cambio il livello visualizzato a schermo di conseguenza
void Level_2::getInput()
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
            Game::cLevel = Game::LEV_1;
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





