#include "Game.hpp"

int main()
{
    Game mGame;
    mGame.run();
    return EXIT_SUCCESS;
}

/*TEST CODE:
int main()
{
    sf::RenderWindow mWindow(sf::VideoMode( 800, 600 ), "It Works!" );
    sf::CircleShape mShape;
    mShape.setRadius( 40.f );
    mShape.setPosition( 100, 100 );
    mShape.setFillColor( sf::Color::Green );
    sf::Event mEvent;
    while(true)
    {
        mWindow.clear();
        mWindow.draw( mShape );
        mWindow.display();
        while( mWindow.pollEvent(mEvent) )
        {
            if( mEvent.type == sf::Event::Closed )
                return 0;
        }
    }
} */



