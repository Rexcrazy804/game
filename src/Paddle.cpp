#include "Paddle.h"

Paddle::Paddle(int id, int winl, int winh) :
    player(id),
    length(20),
    height(100),
    speed(3),
    gap(10),
    winlength(winl),
    winheight(winh),
    box(sf::RectangleShape{sf::Vector2f(length, height)}),
    squarecolor(sf::Color{0xe60052FF})
{ boxinit(); }

void Paddle::boxinit() {
    if (player == 0)
        box.setPosition(gap, winheight/2 - height/2);
    else if (player == 1)
        box.setPosition(winlength - length - gap, winheight/2 - height/2);
    boxcolor(squarecolor);
}
void Paddle::boxcolor(sf::Color clr) {
    box.setFillColor(clr);
}

void Paddle::draw(sf::RenderWindow& window) {
    move();
    window.draw(box);
}

void Paddle::move() {
    if (player == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && box.getPosition().y > 0 + gap) {
            box.move(0, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && box.getPosition().y < winheight - height - gap) {
            box.move(0, speed);
        }
    } else if (player == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && box.getPosition().y > 0 + gap) {
            box.move(0, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && box.getPosition().y < winheight - height - gap) {
            box.move(0, speed);
        }
    }
}

int Paddle::getposx() { return box.getPosition().x; }
int Paddle::getposy() { return box.getPosition().y; }
int Paddle::getlength() { return length; }
int Paddle::getheight() { return height; }