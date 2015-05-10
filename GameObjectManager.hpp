#ifndef GAME_OBJECT_MANAGER_HPP
#define GAME_OBJECT_MANAGER_HPP

#include "GameObject.hpp"
#include "Player.hpp"
#include "NPC.hpp"
#include "Enemy.hpp"
#include "Box.hpp"

class GameObjectManager
{
public:
    GameObjectManager();
    ~GameObjectManager();
    void run();
    void ignite( GameObject& gameObject );
    void update();

private:
    Player mPlayer_1, mPlayer_2;
    NPC mNPC_1;
    Enemy mEnemy_1, mEnemy_2;
    Box mBox_1, mBox_2;
};

#endif // GAME_OBJECT_MANAGER_HPP
