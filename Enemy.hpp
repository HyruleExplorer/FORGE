#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "SFML/System/Time.hpp"
#include "GameObject.hpp"

class Enemy : public GameObject
{
public:
    Enemy();
    void update();
    void getInput();
    void stopMovement();
    void moveTowards( const sf::Sprite& sprite );

private:
    sf::Texture mTexture2, mTexture3;
    sf::IntRect mRect, mRect2, mRect3;
    bool mIsMovingDown;
    bool mIsMovingUp;
    bool mIsMovingRight;
    bool mIsMovingLeft;

    bool mCollidedRight;
    bool mCollidedLeft;
    bool mCollidedDown;
    bool mCollidedUp;

    sf::Time mCounter;
};


#endif // ENEMY_HPP
