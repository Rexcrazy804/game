#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <ctime>
#include "Paddle.hpp"
#include "Square.hpp"

using namespace sf;

enum GameState {
  StartScreen,
  GameScreen,
  EndScreen,
};

int main() {
  // Display
  const int length = 1080, height = 600;
  const Color bgcolor = Color{0x303030FF};
  const VideoMode desktop = sf::VideoMode::getDesktopMode();

  RenderWindow window(VideoMode(length, height), "Pink Pong", Style::Close);
  window.setFramerateLimit(165);
  window.setPosition(Vector2i(desktop.width/2 - length/2, desktop.height/2 - height/2));

  // Display Icon Setting
  Image icon;
  icon.loadFromFile("assets/icon.png");
  window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

  // FONT
  Font notosans;
  notosans.loadFromFile("assets/sansjp.otf");
  //START GAME
  Text start;
  start.setFont(notosans);
  start.setString(L"遊びましょう");
  start.setCharacterSize(50);
  start.setFillColor(Color{0xe60052FF});
  start.setLetterSpacing(2);
  int gamex = start.getLocalBounds().width, gamey = start.getLocalBounds().height;
  start.setPosition(length/2.0 - gamex/2.0, height/2.0 - gamey/2.0);
  // END GAME
  Text gameover;
  gameover.setFont(notosans);
  gameover.setString(L"あなたが死んでいる");
  gameover.setCharacterSize(50);
  gameover.setFillColor(Color{0xe60052FF});
  gameover.setLetterSpacing(2);
  gamex = gameover.getLocalBounds().width;
  gamey = gameover.getLocalBounds().height;
  gameover.setPosition(length/2.0 - gamex/2.0, height/2.0 - gamey/2.0);

  // Sound Effects
  SoundBuffer buffer;
  buffer.loadFromFile("assets/bounce.wav");
  Sound bounce;
  bounce.setBuffer(buffer);
  // Start Effect
  SoundBuffer starter;
  starter.loadFromFile("assets/start.wav");
  Sound begin;
  begin.setBuffer(starter);
  //End Effect
  SoundBuffer ender;
  ender.loadFromFile("assets/end.wav");
  Sound over;
  over.setBuffer(ender);

  // Paddle one and two
  Paddle one = Paddle(0, length, height);
  Paddle two = Paddle(1, length, height);

  // Square
  Square ball = Square(length, height, bounce);

  // inits
  GameState currentState = GameState::StartScreen;
  Clock clock;
  const int MOUSE_DELAY = 8;
  int mouselockbuffer = MOUSE_DELAY;

  while (true) {
    float delta = clock.restart().asSeconds();

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
        exit(0);
      }
    }

    window.clear(bgcolor);
    switch (currentState) {
      case StartScreen:
        ball.move(one, two, delta, false);
        ball.draw(window);
        window.draw(start);

        if (Mouse::isButtonPressed(Mouse::Left)) {
          if (mouselockbuffer >= MOUSE_DELAY) {
            currentState = GameScreen;
            begin.play();
          } else { mouselockbuffer++; }
        }
        break;
      case GameScreen:
        one.move(delta);
        one.draw(window);

        //two.aimove(
        //  ball.getposy() + ball.getside() / 2,
        //  ball.getposx() + ball.getside(),
        //  ball.getspeedy()
        //);
        two.move(delta);
        two.draw(window);

        ball.move(one, two, delta);
        ball.draw(window);

        if (ball.offscr()) { 
          currentState = EndScreen; 
          over.play();
        }
        break;
      case EndScreen:
        window.draw(gameover);
        one.draw(window);
        two.draw(window);
        ball.draw(window);
        if (Mouse::isButtonPressed(Mouse::Left)) {
          ball.circinit();
          mouselockbuffer = 0;
          currentState = StartScreen;
        }
        break;
    }
    window.display();
  }

  return 0;
}
