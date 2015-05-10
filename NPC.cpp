#include "NPC.hpp"
#include "Game.hpp"
#include <time.h>
#include <stdlib.h>

//Costruttore che inizializza tutti gli elementi di NPC
NPC::NPC()
:   mIsMovingDown( false )
,   mIsMovingUp( false )
,   mIsMovingRight( false )
,   mIsMovingLeft( false )

,   mCollidedRight( false )
,   mCollidedLeft( false )
,   mCollidedDown( false )
,   mCollidedUp( false )

,   mCounter( sf::Time::Zero )
{
    mTexture.loadFromFile( "girlfriend.png" );
    mSprite.setTexture( mTexture );
    mSprite.setOrigin( mTexture.getSize().x/2, mTexture.getSize().y/2 );
    mSprite.setPosition( Game::SCREEN_WIDTH/3, Game::SCREEN_HEIGHT/2 );

    srand( time(0) );
}

//Aggiorno la posizione di NPC in base agli Input ricevuti
void NPC::update()
{
    //Collision Update
    //(Deve essere messo prima del 'Movement Update' per come è architettato)
    if( mCollidedRight )
    {
        mIsMovingRight = false;
        mCollidedRight = false;
    }
    if( mCollidedDown )
    {
        mIsMovingDown = false;
        mCollidedDown = false;
    }
    if( mCollidedLeft )
    {
        mIsMovingLeft = false;
        mCollidedLeft = false;
    }
    if( mCollidedUp )
    {
        mIsMovingUp = false;
        mCollidedUp = false;
    }

    //Movement Update
    if( mCounter <= sf::Time::Zero )
    {
        if( mIsMovingRight )
        {
            for( int i=0; i<3; i++)
                mSprite.move( Game::mSpeed, 0.f );
            mIsMovingRight = false;
            mCounter += sf::seconds( 20.f );
        }
        else if( mIsMovingLeft )
        {
            for( int i=0; i<7; i++)
                mSprite.move( -Game::mSpeed, 0.f );
            mIsMovingLeft = false;
            mCounter += sf::seconds( 20.f );
        }

        if( mIsMovingDown )
        {
            for( int i=0; i<3; i++)
                mSprite.move( 0.f, Game::mSpeed );
            mIsMovingDown = false;
            mCounter += sf::seconds( 30.f );
        }
        if( mIsMovingUp )
        {
            for( int i=0; i<3; i++)
                mSprite.move( 0.f, -Game::mSpeed );
            mIsMovingUp = false;
            mCounter += sf::seconds( 30.f );
        }

        mCounter += sf::seconds( 10.f );
    }
        mCounter -= sf::seconds( 1.f );

    //Age Update
    switch( Game::cAge )
    {
    case Game::PAST:
        mSprite.setScale( 0.7f, 0.6f );
        break;
    case Game::PRESENT:
        mSprite.setScale( 1.f, 1.f );
        break;
    case Game::FUTURE:
        mSprite.setScale( 1.3f, 1.5f );
        break;
    default:
        break;
    }

}

//Decide se muoversi e controlla la collisione con la cornice del livello
void NPC::getInput()
{
    //Movement Decision
    mIsMovingDown = ( rand() % 2 );
    mIsMovingUp = ( rand() % 2 );
    mIsMovingRight = ( rand() % 2 );
    mIsMovingLeft = ( rand() % 2 );

    //Boundary Collision Input Detection
    if( mSprite.getPosition().x >= Game::SCREEN_WIDTH - mTexture.getSize().x/2 )
    {
        mCollidedRight = true;
    }
    if( mSprite.getPosition().y >= Game::SCREEN_HEIGHT - mTexture.getSize().y/2  )
    {
        mCollidedDown = true;
    }
    if( mSprite.getPosition().x <= 0 + mTexture.getSize().x/2 )
    {
        mCollidedLeft = true;
    }
    if( mSprite.getPosition().y <= 0 + mTexture.getSize().y/2  )
    {
        mCollidedUp = true;
    }
}

void NPC::stopMovement()
{
    mCollidedRight = true;
    mCollidedLeft = true;
    mCollidedDown = true;
    mCollidedUp = true;
}
