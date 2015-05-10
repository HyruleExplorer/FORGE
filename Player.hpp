#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"

class Player : public GameObject
{
public:
    Player();
    void update();
    void getInput();
    void stopMovement();

private:
    bool mIsMovingDown;
    bool mIsMovingUp;
    bool mIsMovingRight;
    bool mIsMovingLeft;

    bool mCollidedRight;
    bool mCollidedLeft;
    bool mCollidedDown;
    bool mCollidedUp;
};


#endif // PLAYER_HPP
