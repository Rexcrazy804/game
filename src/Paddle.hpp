#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
public:
  Paddle(int, int, int);
  void draw(sf::RenderWindow&);
  void move(float);
  void aimove(int, int, int);
  void init();

  float getposx();
  float getposy();
  int getlength();
  int getheight();
  int getspeed();

private:
  void boxcolor(sf::Color);

  const int player, length, height, speed, gap, winlength, winheight;
  sf::Color squarecolor;
  sf::RectangleShape box;
};
