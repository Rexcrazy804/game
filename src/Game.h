#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Square.h"

class Game {
    public:
        Game();
        void startMenu();
        void mainLoop();
        void endMenu();
    private:
        void init();
        int length, height;

        sf::Sound bounce, start, end;
        sf::RenderWindow window;
        Paddle one, two;
        Square ball;

};