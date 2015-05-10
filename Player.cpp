#include "Player.hpp"
#include "Game.hpp"

//Costruttore che inizializza tutti gli elementi di Player
Player::Player()
:   mIsMovingDown( false )
,   mIsMovingUp( false )
,   mIsMovingRight( false )
,   mIsMovingLeft( false )

,   mCollidedRight( false )
,   mCollidedLeft( false )
,   mCollidedDown( false )
,   mCollidedUp( false )
{
    mTexture.loadFromFile( "player.png" );
    mSprite.setTexture( mTexture );
    mSprite.setOrigin( mTexture.getSize().x/2, mTexture.getSize().y/2 );
    mSprite.setPosition( Game::SCREEN_WIDTH/2, 32 );
}

//Aggiorno la posizione di Player in base agli Input ricevuti
void Player::update()
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
    if( mIsMovingDown )
    {
        mSprite.move( 0.f, Game::mSpeed );
        mIsMovingDown = false;
    }
    if( mIsMovingUp )
    {
        mSprite.move( 0.f, -Game::mSpeed );
        mIsMovingUp = false;
    }
    if( mIsMovingRight )
    {
        mSprite.move( Game::mSpeed, 0.f );
        mIsMovingRight = false;
    }
    if( mIsMovingLeft )
    {
        mSprite.move( -Game::mSpeed, 0.f );
        mIsMovingLeft = false;
    }
}

//Catturo gli Input da tastiera e dall'ambiente di gioco
void Player::getInput()
{
    //Movement Input Detection
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
    {
        mIsMovingDown = true;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
    {
        mIsMovingUp = true;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
    {
        mIsMovingRight = true;
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
    {
        mIsMovingLeft = true;
    }

    //Age changing input detection
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Num1 )  )
    {
        Game::cAge = Game::PAST;
        Game::change = true;
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Num2 )  )
    {
        Game::cAge = Game::PRESENT;
        Game::change = true;
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Num3 )  )
    {
        Game::cAge = Game::FUTURE;
        Game::change = true;
    }

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

    if( mSprite.getPosition().x > Game::SCREEN_WIDTH
        || mSprite.getPosition().y > Game::SCREEN_HEIGHT
        || mSprite.getPosition().x < 0
        || mSprite.getPosition().y < 0 )
       mSprite.setPosition( Game::SCREEN_WIDTH/2, Game::SCREEN_HEIGHT/2 );
}

void Player::stopMovement()
{
    mCollidedRight = true;
    mCollidedLeft = true;
    mCollidedDown = true;
    mCollidedUp = true;
}
