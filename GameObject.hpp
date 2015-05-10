#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "SFML/Graphics.hpp"

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    void draw( sf::RenderWindow& mWindow );
    const sf::Sprite& getSprite();
    const sf::Vector2f getPosition();
    void setPosition( float x, float y );
    void setColor( const sf::Color& mColor );
    bool collidedWith( const sf::Sprite& sprite );
    void IAcollision( GameObject& mGameObject_2, int SafeZone );
    void IAstalker( GameObject& mGameObject_2, int distance );

    virtual void update();
    virtual void stopMovement();
    virtual void getInput();
    virtual void moveTowards( const sf::Sprite& sprite );

    sf::Texture mTexture;
    sf::Sprite mSprite;
};

#endif // GAME_OBJECT_HPP
