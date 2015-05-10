#include "Enemy.hpp"
#include "Game.hpp"
#include <time.h>
#include <stdlib.h>

//Costruttore che inizializza tutti gli elementi di Enemy
Enemy::Enemy()
:   mRect( 0,0,32,64 )
,   mRect2( 0,0,64,64 )
,   mRect3( 0,0,128,128 )
,   mIsMovingDown( false )
,   mIsMovingUp( false )
,   mIsMovingRight( false )
,   mIsMovingLeft( false )

,   mCollidedRight( false )
,   mCollidedLeft( false )
,   mCollidedDown( false )
,   mCollidedUp( false )

,   mCounter( sf::Time::Zero )
{
    mTexture.loadFromFile( "devil_soldier.png" );
    mTexture2.loadFromFile( "gargoyle.png" );
    mTexture3.loadFromFile( "devil_master.png" );

    mSprite.setTexture( mTexture );
    mSprite.setTextureRect( mRect );
    mSprite.setOrigin( mTexture.getSize().x/2, mTexture.getSize().y/2 );
    mSprite.setPosition( Game::SCREEN_WIDTH/3, Game::SCREEN_HEIGHT/2 );

    srand( time(0) );
}

//Aggiorno la posizione di Enemy in base agli Input ricevuti
void Enemy::update()
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
            mSprite.move( Game::mSpeed, 0.f );
            mIsMovingRight = false;
            mCounter += sf::seconds( 30.f );
        }
        if( mIsMovingLeft )
        {
            mSprite.move( -Game::mSpeed, 0.f );
            mIsMovingLeft = false;
            mCounter += sf::seconds( 30.f );
        }
        else if( mIsMovingDown )
        {
            mSprite.move( 0.f, Game::mSpeed );
            mIsMovingDown = false;
            mCounter += sf::seconds( 20.f );
        }
        else if( mIsMovingUp )
        {
            mSprite.move( 0.f, -Game::mSpeed );
            mIsMovingUp = false;
            mCounter += sf::seconds( 20.f );
        }
        else
            mCounter += sf::seconds( 30.f );
    }
    mCounter -= sf::seconds( 1.f );

    //Age Update
    switch( Game::cAge )
    {
    case Game::PAST:
        mSprite.setTexture( mTexture2 );
        mSprite.setTextureRect( mRect2 );
        mSprite.setOrigin( mTexture2.getSize().x/2, mTexture2.getSize().y/2 );
        break;
    case Game::PRESENT:
        mSprite.setTexture( mTexture3 );
        mSprite.setTextureRect( mRect3 );
        mSprite.setOrigin( mTexture3.getSize().x/2, mTexture3.getSize().y/2 );
        break;
    case Game::FUTURE:
        mSprite.setTexture( mTexture );
        mSprite.setTextureRect( mRect );
        mSprite.setOrigin( mTexture.getSize().x/2, mTexture.getSize().y/2 );
        break;
    default:
        break;
    }
}

//Decide se muoversi e controlla la collisione con la cornice del livello
void Enemy::getInput()
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
         mSprite.move( -Game::mSpeed, 0 );
    }
    if( mSprite.getPosition().y >= Game::SCREEN_HEIGHT - mTexture.getSize().y/2  )
    {
        mCollidedDown = true;
        mSprite.move( 0, -Game::mSpeed );
    }
    if( mSprite.getPosition().x <= 0 + mTexture.getSize().x/2 )
    {
        mCollidedLeft = true;
        mSprite.move( Game::mSpeed, 0 );
    }
    if( mSprite.getPosition().y <= 0 + mTexture.getSize().y/2  )
    {
        mCollidedUp = true;
        mSprite.move( 0, Game::mSpeed );
    }
}

void Enemy::stopMovement()
{
    mCollidedRight = true;
    mCollidedLeft = true;
    mCollidedDown = true;
    mCollidedUp = true;
}

void Enemy::moveTowards( const sf::Sprite& sprite )
{
    mSprite.move( ( sprite.getPosition().x - mSprite.getPosition().x )/150
                , ( sprite.getPosition().y - mSprite.getPosition().y )/150 );
}
