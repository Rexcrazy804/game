#include "Square.hpp"
#include <iostream>

Square::Square(int wl, int wh, sf::Sound &aud):
  side(20),
  speedx(525),
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

// This function deals with the square's movement and directional changes as it colides with the player's paddles.
void Square::move(Paddle &p1, Paddle &p2, float delta, bool collidewithpaddle) {
  // The paddles come into play here
  int x = rect.getPosition().x;
  int y = rect.getPosition().y;

  /*std::cout << x << " " << y << std::endl;*/

  const int PIXEL_OFFSET = 1;

  if (collidewithpaddle) {
    // Paddle Sides
    if (x <= p1.getposx() + p1.getlength()) {
      if (y <= p1.getposy() + p1.getheight() && y + side >= p1.getposy()) {
        x = p1.getposx() + p1.getlength() + PIXEL_OFFSET;
        rect.setPosition(x, y);
        speedx = -speedx;
        bounce.play();
      }     
    }
    if (x + side >= p2.getposx()) {
      if (y <= p2.getposy() + p2.getheight() && y + side >= p2.getposy()) {
        x = p2.getposx() - side - PIXEL_OFFSET;
        rect.setPosition(x, y);
        speedx = -speedx;
        bounce.play();
      }     
    }
  }

  // EXTRA WALLS FOR START SCREEN
  if(x < 0 || x + side > winlength) {
    speedx = -speedx;
    x = (x > winlength/2)? winlength - side : 0;
    rect.setPosition(x, y);
    bounce.play();
  }
  if(y < 0 || y + side > winheight) {
    speedy = -speedy;
    y = (y > winheight/2)? winheight - side : 0;
    rect.setPosition(x, y);
    bounce.play();
  }

  rect.move(speedx * delta, speedy * delta);  
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
