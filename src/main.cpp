#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.cpp"

int main() {
    // Display
    const int length = 1080, height = 768;
    const auto bgcolor = sf::Color{0x303030FF};
    sf::RenderWindow window(sf::VideoMode(length, height), "Pink Pong", sf::Style::Close);
    window.setFramerateLimit(165);
    
    // Display Icon Setting
    sf::Image icon;
    icon.loadFromFile("assets/icon.png");
    //write(icon);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Sound Effects
    sf::SoundBuffer buffer;
    buffer.loadFromFile("assets/bounce.wav");
    sf::Sound bounce;
    bounce.setBuffer(buffer);

    // Paddle one and two
    Paddle one = Paddle(0, length, height);
    Paddle two = Paddle(1, length, height);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        //if(mainSquare.box.getPosition().x <= 0) {
        //    mainSquare.speedx = -mainSquare.speedx;
        //    bounce.play();
        //} else if (mainSquare.box.getPosition().x >= length - mainSquare.side) {
        //    mainSquare.speedx = -mainSquare.speedx;
        //    bounce.play();
        //}
        //if(mainSquare.box.getPosition().y <= 0) {
        //    mainSquare.speedy = -mainSquare.speedy;
        //    bounce.play();
        //} else if (mainSquare.box.getPosition().y >= width - mainSquare.side) {
        //    mainSquare.speedy = -mainSquare.speedy;
        //    bounce.play();
        //}
        // Drawings
        window.clear(bgcolor);
        one.draw(window);
        two.draw(window);

        window.display();
    }

    return 0;
}