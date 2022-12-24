#pragma once
#include <SFML/Graphics.hpp>

class Square {
    public:
        Square(int x, int dx, int dy, sf::Color color);
        void boxinit(int x, int y);
        void draw(sf::RenderWindow& window);
        void boxcolor(sf::Color);

        int side, speedx, speedy;
        sf::RectangleShape box;
    private:

        sf::Color squarecolor;
        bool moves;
};