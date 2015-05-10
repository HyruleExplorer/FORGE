#ifndef LEVEL_2_HPP
#define LEVEL_2_HPP

#include "Level.hpp"
#include "Player.hpp"
#include "Box.hpp"
#include "Enemy.hpp"

class Level_2 : public Level
{
public:
    Level_2();
    void draw();
    void setColor( sf::Color& mColor );
    void getInput();

private:
    Player mPlayer_1;
    Box mBox_2;
    Enemy mEnemy_1;
    Enemy mEnemy_2;
};

#endif // LEVEL_2_HPP
