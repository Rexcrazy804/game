#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.hpp"

class Square {
public:
  Square(int, int, sf::Sound&);
  void move(Paddle&, Paddle&, float, bool = true);
  void draw(sf::RenderWindow&);
  void circinit();

  bool offscr();
  int getposy();
  int getposx();
  int getside();
  int getspeedy();

private:
  const int side, winlength, winheight;
  const sf::Color rectcolor;

  sf::Sound &bounce;
  sf::RectangleShape rect;
  int speedx, speedy;
};
