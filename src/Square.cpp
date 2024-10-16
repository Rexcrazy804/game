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
  float x = rect.getPosition().x;
  float y = rect.getPosition().y;

  /*std::cout << x << " " << y << std::endl;*/

  const int PIXEL_OFFSET = 1;
  const float SIDE_FRACTION = ((float) side) / 2.5;

  if (collidewithpaddle) {
    if (x <= p1.getposx() + (float) p1.getlength() && x >= (p1.getposx() + (float) p1.getlength()) - SIDE_FRACTION ) {
      // p1.y <= y <= p1.y + p1.height
      // or
      // p1.y <= y + side <= p1.y + p1.height
      if (
        (y >= p1.getposy() && y <= p1.getposy() + (float) p1.getheight())
        ||
        (y + (float) side >= p1.getposy() && y + (float) side <= p1.getposy() + (float)p1.getheight())
      ) {
        x = p1.getposx() + p1.getlength() + PIXEL_OFFSET;
        rect.setPosition(x, y);
        speedx = -speedx;
        bounce.play();
      }
      /*if (y <= p1.getposy() + p1.getheight() && y + side >= p1.getposy()) {}     */
    }
    if (x + (float) side >= p2.getposx() && x + (float) side <= p2.getposx() + SIDE_FRACTION) {
      if (
        (y >= p2.getposy() && y <= p2.getposy() + (float) p2.getheight())
        ||
        (y + (float) side >= p2.getposy() && y + (float) side <= p2.getposy() + (float)p2.getheight())
      ) {
        x = p2.getposx() - side - PIXEL_OFFSET;
        rect.setPosition(x, y);
        speedx = -speedx;
        bounce.play();
      }     
      /*if (y <= p2.getposy() + (float) p2.getheight() && y + side >= p2.getposy()) {*/
    }

    // top
    if (y + (float) side >= p1.getposy() && y + (float) side <= p1.getposy() + SIDE_FRACTION) {
      if (
        (x >= p1.getposx() && x <= p1.getposx() + (float)p1.getlength())
        ||
        (x + (float)side >= p1.getposx() && x + (float)side <= p1.getposx() + (float)p1.getlength())
      ) {
        y = p1.getposy() - PIXEL_OFFSET - side;
        rect.setPosition(x, y);
        speedy = -speedy;
        bounce.play();
      }
    }
    if (y + (float) side >= p2.getposy() && y + (float) side <= p2.getposy() + SIDE_FRACTION) {
      if (
        (x >= p2.getposx() && x <= p2.getposx() + (float)p2.getlength())
        ||
        (x + (float)side >= p2.getposx() && x + (float)side <= p2.getposx() + (float)p2.getlength())
      ) {
        y = p2.getposy() - PIXEL_OFFSET - (float) side;
        rect.setPosition(x, y);
        speedy = -speedy;
        bounce.play();
      }
    }
    // bottom
    if (y <= p1.getposy() + (float) p1.getheight() && y >= p1.getposy() + (float) p1.getheight() - SIDE_FRACTION) {
      if (
        (x >= p1.getposx() && x <= p1.getposx() + (float)p1.getlength())
        ||
        (x + (float)side >= p1.getposx() && x + (float)side <= p1.getposx() + (float)p1.getlength())
      ) {
        y = p1.getposy() + p2.getheight() + PIXEL_OFFSET;
        rect.setPosition(x, y);
        speedy = -speedy;
        bounce.play();
      }
    }
    if (y <= p2.getposy() + (float) p2.getheight() && y >= p2.getposy() + (float) p2.getheight() - SIDE_FRACTION) {
      if (
        (x >= p2.getposx() && x <= p2.getposx() + (float)p2.getlength())
        ||
        (x + (float)side >= p2.getposx() && x + (float)side <= p2.getposx() + (float)p2.getlength())
      ) {
        y = p2.getposy() + p2.getheight() + PIXEL_OFFSET;
        rect.setPosition(x, y);
        speedy = -speedy;
        bounce.play();
      }
    }
  } else {
    // EXTRA WALLS FOR START SCREEN
    if(x < 0 || x + side > winlength) {
      speedx = -speedx;
      x = (x > ((float) winlength)/2)? winlength - side : 0;
      rect.setPosition(x, y);
      bounce.play();
    }
  }

  // top and bottom walls
  if(y < 0 || y + side > winheight) {
    speedy = -speedy;
    y = (y > ((float)winheight)/2)? winheight - side : 0;
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
