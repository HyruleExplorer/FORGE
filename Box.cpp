#include "Box.hpp"
#include "Game.hpp"

Box::Box()
{
    mTexture.loadFromFile( "box.png" );
    mSprite.setTexture( mTexture );
    mSprite.setOrigin( mTexture.getSize().x/2, mTexture.getSize().y/2 );
    mSprite.setPosition( 112, Game::SCREEN_HEIGHT + 15  );

    //TODO: Set the 4th argument to '0' to make the Box transparent
    mSprite.setColor( sf::Color( 255,0,0, 255 ) );
}
