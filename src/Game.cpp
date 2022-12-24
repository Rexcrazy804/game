#include "Game.h"

Game::Game():
    length(1080),
    height(768),
    one(Paddle(0, length, height)),
    two(Paddle(1, length, height)),
    ball(Square(length, height, bounce))
{ init(); }

void Game::init() {
    // Bounce
    sf::SoundBuffer b;
    b.loadFromFile("assets/bounce.wav");
    bounce.setBuffer(b);

    // Start
    sf::SoundBuffer s;
    s.loadFromFile("assets/bounce.wav");
    start.setBuffer(s);

    // End
    sf::SoundBuffer e;
    e.loadFromFile("assets/bounce.wav");
    end.setBuffer(e);
}