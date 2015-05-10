#ifndef NPC_HPP
#define NPC_HPP

#include "SFML/System/Time.hpp"
#include "GameObject.hpp"

class NPC : public GameObject
{
public:
    NPC();
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

    sf::Time mCounter;
};

#endif // NPC_HPP
