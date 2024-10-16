#include "Paddle.hpp"
#include "math.h"

Paddle::Paddle(int id, int winl, int winh) :
  player(id),
  length(20),
  height(100),
  speed(525),
  gap(10),
  winlength(winl),
  winheight(winh),
  squarecolor(sf::Color{0xe60052FF}),
  box(sf::RectangleShape{sf::Vector2f(length, height)})
{ boxinit(); }

void Paddle::boxinit() {
  if (player == 0)
    box.setPosition(gap, winheight/2.0 - height/2.0);
  else if (player == 1)
    box.setPosition(winlength - length - gap, winheight/2.0 - height/2.0);
  boxcolor(squarecolor);
}

void Paddle::boxcolor(sf::Color clr) {
  box.setFillColor(clr);
}

void Paddle::draw(sf::RenderWindow& window) {
  window.draw(box);
}

// Code for Computer assisted second player, pseudo ai.
void Paddle::aimove(int by, int bx, int sp) {
  int py = getposy() + height/2;
  int expect = by + speed*(winlength-gap - bx)%20;
  if (py - expect != 0) {
    box.move(0, (py > expect)? -speed : speed);
  }
}


// Input and movement
void Paddle::move(float delta) {
  if (player == 0) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && box.getPosition().y > 0 + gap) {
      box.move(0, -speed * delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && box.getPosition().y < winheight - height - gap) {
      box.move(0, speed * delta);
    }
  } else if (player == 1) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && box.getPosition().y > 0 + gap) {
      box.move(0, -speed * delta);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && box.getPosition().y < winheight - height - gap) {
      box.move(0, speed * delta);
    }
  }
}

float Paddle::getposx() { return box.getPosition().x; }
float Paddle::getposy() { return box.getPosition().y; }
int Paddle::getlength() { return length; }
int Paddle::getheight() { return height; }
int Paddle::getspeed() { return speed; }
