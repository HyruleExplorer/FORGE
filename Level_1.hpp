#ifndef LEVEL_1_HPP
#define LEVEL_1_HPP

#include "Level.hpp"
#include "Player.hpp"
#include "Box.hpp"
#include "NPC.hpp"

class Level_1 : public Level
{
public:
    Level_1();
    void draw();
    void setColor( sf::Color& mColor );
    void getInput();

private:
    Box mBox_1;
    Player mPlayer_1;
    NPC mNPC_1;
};

#endif // LEVEL_1_HPP
