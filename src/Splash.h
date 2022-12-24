#pragma once
#include <stdio.h>
#include "Square.cpp"

class Splash {
    public:
        Splash(): splashes({}), count(0) {}

        void generate(int x, int y, int side, int length, int width);
        bool clone(int x, int y);
        void draw(sf::RenderWindow& window);
    private:
        std::vector<Square> splashes;
        int count;
};