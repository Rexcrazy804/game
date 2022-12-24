#include "Paddle.h"
#include "iostream"

Paddle::Paddle(int id, int winl, int winh, sf::Color color = sf::Color{0xe60052FF}) :
    player(id),
    length(20),
    height(100),
    speed(5),
    gap(10),
    winlength(winl),
    winheight(winh),
    box(sf::RectangleShape{sf::Vector2f(length, height)}),
    squarecolor(color)
{ boxinit(); }

void Paddle::boxinit() {
    std::cout << "bob" << std::endl;
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