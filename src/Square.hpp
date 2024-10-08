#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.hpp"

class Square {
public:
  Square(int, int, sf::Sound&);
  void move(Paddle&, Paddle&, bool = true);
  void draw(sf::RenderWindow&);
  bool offscr();
  int getposy();
  int getposx();
  int getside();
  int getspeedy();

private:
  void circinit();

  const int side, winlength, winheight;
  int speedx, speedy;
  sf::RectangleShape rect;
  const sf::Color rectcolor;
  sf::Sound &bounce;
};
