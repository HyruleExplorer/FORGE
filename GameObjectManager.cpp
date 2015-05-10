#include "GameObjectManager.hpp"
#include "Game.hpp"
#include <iostream>

GameObjectManager::GameObjectManager()
{
    mBox_1.setPosition( 112, Game::SCREEN_HEIGHT + 15  );
    mBox_2.setPosition( 192, -15 );
    mNPC_1.setPosition( Game::SCREEN_WIDTH/3 - 80, Game::SCREEN_HEIGHT/2 - 32 );
    mPlayer_1.setPosition( Game::SCREEN_WIDTH/2 - 16, 32 );
    mPlayer_2.setPosition( mBox_2.getPosition().x, mBox_2.getPosition().y + 32 );
    mEnemy_1.setPosition( Game::SCREEN_WIDTH/3, Game::SCREEN_HEIGHT/2 );
    mEnemy_2.setPosition( mEnemy_1.getPosition().x - 128, mEnemy_1.getPosition().y );
}

GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::run()
{
    switch (Game::cLevel)
    {

    case Game::MENU_0:
        break;

    case Game::LEV_1:
        ignite( mBox_1 );
        ignite( mNPC_1 );
        ignite( mPlayer_1 );
        break;

    case Game::LEV_2:
        ignite( mBox_2 );
        ignite( mEnemy_1 );
        ignite( mEnemy_2 );
        ignite( mPlayer_2 );
        break;

    default:
        break;
    }
}

void GameObjectManager::ignite( GameObject& gameObject )
{
    gameObject.draw( Game::mWindow );
    gameObject.getInput();
}

//Aggiorno TUTTI gli elementi attivi presenti a schermo a seconda del livello.
//TODO: Spezzettarlo in più funzioni da mettere nelle definizioni degli oggetti di gioco.
void GameObjectManager::update()
{
    switch (Game::cLevel)
    {
        //=======================//
        //Update nel Menu
        //=======================//
        case Game::MENU_0:
            break;

        //=======================//
        //Update nel Livello_1
        //=======================//
        case Game::LEV_1:
            mPlayer_1.update();
            mNPC_1.update();
            mBox_1.update();
            //Collisione con Box_1
            if(  mPlayer_1.collidedWith( mBox_1.getSprite() )  )
            {
                std::cout<<"COLLISION WITH BOX_1 DETECTED\n";
                mPlayer_1.setPosition( mBox_1.getPosition().x, mBox_1.getPosition().y - 32 );
                Game::cLevel = Game::LEV_2;
            }
            //Collisione con NPC_1
            mPlayer_1.IAcollision( mNPC_1, 48 );
            break;

        //=======================//
        //Update nel Livello 2
        //=======================//
        case Game::LEV_2:
            mPlayer_2.update();
            mEnemy_1.update();
            mEnemy_2.update();
            mNPC_1.update();
            mBox_2.update();
            //Collisione con Box_2
            if( mPlayer_2.collidedWith( mBox_2.getSprite() ) )
            {
                std::cout<<"COLLISION WITH BOX_2 DETECTED\n";
                mPlayer_2.setPosition( mBox_2.getPosition().x, mBox_2.getPosition().y + 32 );
                mEnemy_1.setPosition( Game::SCREEN_WIDTH/3, Game::SCREEN_HEIGHT/2 );
                mEnemy_2.setPosition( mEnemy_1.getPosition().x - 128, mEnemy_1.getPosition().y );
                Game::cLevel = Game::LEV_1;
            }

            if( Game::cAge == Game::PRESENT )
                mEnemy_2.setColor( sf::Color().Transparent );
            if( Game::cAge != Game::PRESENT )
                mEnemy_2.setColor( sf::Color( 255,255,255,255 ) );

            //Collisione con gli Enemies
            mPlayer_2.IAcollision( mEnemy_1, 64 );
            if( Game::cAge != Game::PRESENT )
                mPlayer_2.IAcollision( mEnemy_2, 64 );

            //Collisione tra Enemies
            if( Game::cAge != Game::PRESENT )
            {
                mEnemy_2.IAcollision( mEnemy_1, 64 );
                mEnemy_1.IAcollision( mEnemy_2, 64 );
            }

            //IA nemica che segue il giocatore se quest'ultimo è troppo vicino
            mEnemy_1.IAstalker( mPlayer_2, 192 );
            if( Game::cAge != Game::PRESENT )
                mEnemy_2.IAstalker( mPlayer_2, 192 );
            break;

        default:
            break;
    }

}




