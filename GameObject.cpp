#include "SFML/Graphics.hpp"
#include "GameObject.hpp"
#include "Game.hpp"
#include <iostream>

//Costruttore standard di un oggetto di gioco
GameObject::GameObject()
{
    mTexture.loadFromFile( "visiblegameobject.png" );
    mSprite.setTexture( mTexture );
    mSprite.setPosition( Game::SCREEN_WIDTH /2, Game::SCREEN_HEIGHT/2 );
}

GameObject::~GameObject(){}

//Disegna l'oggetto di gioco a schermo
void GameObject::draw( sf::RenderWindow& mWindow )
{
    mWindow.draw( mSprite );
}

//Ritorna la Sprite dell'Oggetti di Gioco
const sf::Sprite& GameObject::getSprite()
{
    return mSprite;
}

//Ritorna la posizione dell'Oggetto di Gioco
const sf::Vector2f GameObject::getPosition()
{
    return mSprite.getPosition();
}

//Imposta la posizione dell'Oggetto di Gioco ad x,y
void GameObject::setPosition( float x, float y )
{
    mSprite.setPosition( x, y );
}

void GameObject::setColor( const sf::Color& mColor )
{
    mSprite.setColor( mColor );
}

bool GameObject::collidedWith( const sf::Sprite& sprite )
{
    if (   mSprite.getGlobalBounds().intersects( sprite.getGlobalBounds() )   )
        return true;
    else
        return false;
}

void GameObject::IAcollision( GameObject& mGameObject_2, int mSafeZone )
{

    if( collidedWith( mGameObject_2.getSprite() )  )
    {
        std::cout<<"COLLISION DETECTED\n";
        stopMovement();
        mGameObject_2.stopMovement();

        if( mSprite.getPosition().y <= mGameObject_2.getPosition().y )
        {
            mSprite.setPosition( mSprite.getPosition().x, mGameObject_2.getPosition().y - mSafeZone );
        }
        else if( mSprite.getPosition().y > mGameObject_2.getPosition().y )
        {
            mSprite.setPosition( mSprite.getPosition().x, mGameObject_2.getPosition().y + mSafeZone );
        }

        if( mSprite.getPosition().x <= mGameObject_2.getPosition().x )
        {
            mSprite.setPosition( mGameObject_2.getPosition().x - mSafeZone, mSprite.getPosition().y );
        }

        else if( mSprite.getPosition().x > mGameObject_2.getPosition().x )
        {
            mSprite.setPosition( mGameObject_2.getPosition().x + mSafeZone, mSprite.getPosition().y );
        }
    }
}

void GameObject::IAstalker( GameObject& mGameObject_2, int distance )
{
    if(  abs( (int)mSprite.getPosition().x - (int)mGameObject_2.getPosition().x ) < distance
        && abs( (int)mSprite.getPosition().y - (int)mGameObject_2.getPosition().y ) < distance  )
    {
        moveTowards( mGameObject_2.getSprite() );
        std::cout<<"STALKER ENGAGED!\n";
    }
}

void GameObject::update(){}
void GameObject::stopMovement(){}
void GameObject::getInput(){}
void GameObject::moveTowards( const sf::Sprite& sprite ){}
