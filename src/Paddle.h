#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
    public:
        Paddle(int, int, int);
        void draw(sf::RenderWindow&);

        int getposx();
        int getposy();
        int getlength();
        int getheight();

    private:
        void boxcolor(sf::Color);
        void boxinit();
        void move();

        int player, length, height, speed, gap, winlength, winheight;
        sf::RectangleShape box;
        sf::Color squarecolor;
};