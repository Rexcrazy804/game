#include "Square.hpp"

Square::Square(int wl, int wh, sf::Sound aud):
  side(20),
  speedx(4),
  speedy(speedx),

  winlength(wl),
  winheight(wh),

  rect(sf::RectangleShape{sf::Vector2f(side, side)}),
  rectcolor(sf::Color{0xe60052FF}),

  bounce(aud)
{ circinit(); }

void Square::circinit() {
  rect.setFillColor(rectcolor);
  rect.setPosition(winlength/2.0 - side/2.0, winheight/2.0 - side/2.0);
}

// This function feals with the square's movement and directional changes as it colides with the player's paddles.
void Square::move(Paddle p1, Paddle p2) {
  // The paddles come into play here
  int x = rect.getPosition().x;
  int y = rect.getPosition().y;

  // Paddle Sides
  if (x == p1.getposx() + p1.getlength()) {
    // SIDES
    if ( (p1.getposy() <= y && y <= p1.getposy() + p1.getheight()) || (p1.getposy() <= y + side && y + side <= p1.getposy() + p1.getheight())) {
      speedx = -speedx;
      bounce.play();
    }
  } else if (x + side == p2.getposx()) {
    if ( (p2.getposy() <= y && y <= p2.getposy() + p2.getheight()) || (p2.getposy() <= y + side && y + side <= p2.getposy() + p2.getheight())) {
      speedx = -speedx;
      bounce.play();
    }
  }
  // Paddle top and bottom
  if (x < p1.getposx() + p1.getlength() && x + side > p1.getposx()) {
    if (y + side == p1.getposy() or y == p1.getposy() + p1.getheight()) {
      speedy = -speedy;
      bounce.play();
    }
  } else if (x < p2.getposx() + p2.getlength() && x + side > p2.getposx()) {
    if (y + side == p2.getposy() or y == p2.getposy() + p2.getheight()) {
      speedy = -speedy;
      bounce.play();
    }
  }

  // EXTRA WALL FOR START SCREEN
  if(x < 0 || x > winlength - side) {
    speedx = -speedx;
    bounce.play();
  }
  // Top and Bottom
  if(y <= 0 || y >= winheight - side) {
    speedy = -speedy;
    bounce.play();
  }
  rect.move(speedx, speedy);  
}

bool Square::offscr() {
  int x = rect.getPosition().x;
  return (x < 0 || x + side > winlength);
}

void Square::draw(sf::RenderWindow& window) { window.draw(rect); }

int Square::getposy() { return rect.getPosition().y; }
int Square::getposx() { return rect.getPosition().x; }
int Square::getside() { return side; }
int Square::getspeedy() { return speedy; }
