#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "SFML/Graphics.hpp"

class Level
{
public:
    Level();
    virtual ~Level(){}
    virtual void setColor( sf::Color& mColor );
    virtual void setBackground( std::string& newFileName );
    virtual void draw();
    virtual void getInput();
    virtual void update( std::string& newFileName );

    std::string mFileName;
    sf::Texture mTexture;
    sf::Sprite mBackground;
};


#endif // LEVEL_HPP
