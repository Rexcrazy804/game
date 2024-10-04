#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
    public:
        Paddle(int, int, int);
        void draw(sf::RenderWindow&, bool = true);
        void aimove(int, int, int);

        int getposx();
        int getposy();
        int getlength();
        int getheight();
        int getspeed();

    private:
        void boxcolor(sf::Color);
        void boxinit();
        void move();

        int player, length, height, speed, gap, winlength, winheight;
        sf::Color squarecolor;
        sf::RectangleShape box;
};
