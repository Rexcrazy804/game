#include "Splash.h"

void Splash::generate(int x, int y, int length, int width, int side = 100) {
    if (clone(x, y)) { 
        splashes.push_back(Square(side));
        count += 1;
    } else return;
    splashes.back().boxinit(x, y);
    splashes.back().boxcolor(sf::Color{0x878787FF});
}

void Splash::draw(sf::RenderWindow& window) {
    for (Square splash : splashes) {
        window.draw(splash.box);
    }
}

bool Splash::clone(int x, int y) {
    for (Square splash : splashes)
        if (splash.box.getPosition().x == x && splash.box.getPosition().y == y) return false;
    return true;
}