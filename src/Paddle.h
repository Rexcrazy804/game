#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
    public:
        Paddle(int, int, int, sf::Color);
        void draw(sf::RenderWindow&);

    private:
        void boxcolor(sf::Color);
        void boxinit();
        void move();

        int player, length, height, speed, gap, winlength, winheight;
        sf::RectangleShape box;
        sf::Color squarecolor;
};