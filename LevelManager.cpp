#include "Game.hpp"
#include "LevelManager.hpp"
//#include <iostream>
//#include <map>
//#include <cassert>

//Costruttore del Manager dei Livelli
LevelManager::LevelManager()
: mAgeColor( 255, 255, 255, 255 )
, filename("main_menu")
{
    mMenu.setColor( mAgeColor );
    level_1.setColor( mAgeColor );
    level_2.setColor( mAgeColor );
}

LevelManager::~LevelManager()
{
    //Game::discoveredLevels.clear();
    //assert( Game::discoveredLevels.empty() );

    //if( Game::discoveredLevels.empty() )
    //    std::cout<<"\nTutti gli elementi eliminati da discoveredElements.\n";
}

//Funzione principale di LevelManager. Crea e gestisce i vari livelli quando vengono chiamati dal gioco
void LevelManager::run()
{
    switch (Game::cLevel)
    {
    case Game::MENU_0:
        filename = "main_menu";
        ignite( mMenu );
        update( mMenu );
        /*name = "MENU_0";
        result = Game::discoveredLevels.find( name );
        if( result == Game::discoveredLevels.end() )
        {
            Game::discoveredLevels.insert( std::pair<std::string,Main_Menu>(name,mMenu) );
            std::cout<<"\nInserito mMenu in discoveredLevels\n";
        }*/
        break;

    case Game::LEV_1:
        filename = "level_1";
        ignite( level_1 );
        update( level_2 );
        Game::change = true;
        update( level_1 );
        /*name = "Level_1";
        result = Game::discoveredLevels.find( name );
        if( result == Game::discoveredLevels.end() )
        {
          Game::discoveredLevels.insert( std::pair<std::string,Level_1>(name,level_1) );
          std::cout<<"\nInserito level_1 in discoveredLevels\n";
        }*/
        break;

    case Game::LEV_2:
        filename = "level_2";
        ignite( level_2 );
        update( level_1 );
        Game::change = true;
        update( level_2 );
        /*name = "Level_2";
        result = Game::discoveredLevels.find( name );
        if( result == Game::discoveredLevels.end() )
        {
            Game::discoveredLevels.insert( std::pair<std::string,Level_2>(name,level_2) );
            std::cout<<"\nInserito level_2 in discoveredLevels\n";
        }*/
        break;

    default:
        break;
    }
}

//Disegno ciascun livello e ne catturo gli input.
void LevelManager::ignite( Level& level )
{
    level.draw();
    level.getInput();
}

//Aggiorno lo sfondo dei livelli in base a Game::cAge
void LevelManager::update( Level& level )
{
    switch( Game::cAge )
    {
        case Game::PAST:
            mAgeColor = sf::Color( 220, 180, 50, 255 );
            break;

        case Game::PRESENT:
            mAgeColor = sf::Color( 255, 255, 255, 255 );
            break;

        case Game::FUTURE:
            mAgeColor = sf::Color( 150, 100, 255, 255 );
            break;

        default:
            break;
    }
    level.draw();
    level.setColor( mAgeColor );
    level.update( filename );

}







