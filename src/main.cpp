#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.cpp"
#include "Square.cpp"

int main() {
    // Display
    const int length = 1080, height = 768;
    const auto bgcolor = sf::Color{0x303030FF};
    sf::RenderWindow window(sf::VideoMode(length, height), "Pink Pong", sf::Style::Close);
    window.setFramerateLimit(165);
    
    // Display Icon Setting
    sf::Image icon;
    icon.loadFromFile("assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // FONT
    sf::Font notosans;
    notosans.loadFromFile("assets/sansjp.otf");
    //START GAME
    sf::Text start;
    start.setFont(notosans);
    start.setString(L"遊びましょう");
    start.setCharacterSize(50);
    start.setFillColor(sf::Color{0xe60052FF});
    start.setLetterSpacing(2);
    int gamex = start.getLocalBounds().width, gamey = start.getLocalBounds().height;
    start.setPosition(length/2 - gamex/2, height/2 - gamey/2);
    // END GAME
    sf::Text gameover;
    gameover.setFont(notosans);
    gameover.setString(L"あなたが死んでいる");
    gameover.setCharacterSize(50);
    gameover.setFillColor(sf::Color{0xe60052FF});
    gameover.setLetterSpacing(2);
    gamex = gameover.getLocalBounds().width;
    gamey = gameover.getLocalBounds().height;
    gameover.setPosition(length/2 - gamex/2, height/2 - gamey/2);

    // Sound Effects
    sf::SoundBuffer buffer;
    buffer.loadFromFile("assets/bounce.wav");
    sf::Sound bounce;
    bounce.setBuffer(buffer);
    // Start Effect
    sf::SoundBuffer starter;
    starter.loadFromFile("assets/start.wav");
    sf::Sound begin;
    begin.setBuffer(starter);

    //End Effect
    sf::SoundBuffer ender;
    ender.loadFromFile("assets/end.wav");
    sf::Sound over;
    over.setBuffer(ender);

    // Paddle one and two
    Paddle one = Paddle(0, length, height);
    Paddle two = Paddle(1, length, height);

    // Square
    Square ball = Square(length, height, bounce);

    // Simple Start Screen
    while (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }
        }
        window.clear(bgcolor);
        ball.move(one, two);
        ball.draw(window);
        window.draw(start);
        window.display();
    }
    begin.play();

    // Main loop
    while (!ball.offscr()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }
        }

        window.clear(bgcolor);
        one.draw(window);
        two.draw(window);
        //two.draw(window, false);
        //two.aimove(ball.getposy() + ball.getside() / 2, ball.getposx() + ball.getside(), ball.getspeedy());
        ball.move(one, two);
        ball.draw(window);

        window.display();
    }

    // Drawing End screen Text
    window.draw(gameover);
    window.display();
    over.play();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    return 0;
}