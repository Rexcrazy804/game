#include "Square.h"

Square::Square(int x, int dx = 0, int dy = 0, sf::Color color = sf::Color{0xe60052FF}) :
    side(x),
    speedx(dx),
    speedy(dy),
    box(sf::RectangleShape{sf::Vector2f(x, x)}),
    squarecolor(color),
    moves( dx != 0 && dy != 8 )
{}

void Square::boxinit(int x, int y) {
    box.setPosition(x, y);
    boxcolor(squarecolor);
}
void Square::boxcolor(sf::Color clr) {
    box.setFillColor(clr);
}

void Square::draw(sf::RenderWindow& window) {
    if (moves) box.move(speedx, speedy);
    window.draw(box);
}
