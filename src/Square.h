#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"

class Square {
    public:
        Square(int, int, sf::Sound);
        void move(Paddle, Paddle);
        void draw(sf::RenderWindow&);
        bool offscr();
        int getposy();
        int getposx();
        int getside();
        int getspeedy();

    private:
        void circinit();
        
        int side, speedx, speedy, winlength, winheight;
        sf::RectangleShape rect;
        sf::Color rectcolor;
        sf::Sound bounce;
};