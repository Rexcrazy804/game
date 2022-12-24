#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Splash.cpp"

int main() {
    // Display
    const int length = 1080, width = 768;
    const auto bgcolor = sf::Color{0x303030FF};
    sf::RenderWindow window(sf::VideoMode(length, width), "The Life of a Square", sf::Style::Close);
    window.setFramerateLimit(165);
    
    // Display Icon Setting
    sf::Image icon;
    icon.loadFromFile("assets/icon.png");
    //write(icon);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    // View setting
    sf::View myview(sf::FloatRect(0, 0, length+220, width+220));
    myview.setCenter(length/2, width/2);
    window.setView(myview);

    // Sound Effects
    sf::SoundBuffer buffer;
    buffer.loadFromFile("assets/bounce.wav");
    sf::Sound bounce;
    bounce.setBuffer(buffer);

    // Square
    Square mainSquare = Square(100, 2, 2);
    mainSquare.boxinit(length/2 - mainSquare.side/2, width/2 - mainSquare.side/2);

    // Splash
    Splash splashbox = Splash();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        if(mainSquare.box.getPosition().x <= 0) {
            mainSquare.speedx = -mainSquare.speedx;
            bounce.play();
            splashbox.generate(mainSquare.box.getPosition().x - mainSquare.side, mainSquare.box.getPosition().y, length, width);
        } else if (mainSquare.box.getPosition().x >= length - mainSquare.side) {
            mainSquare.speedx = -mainSquare.speedx;
            bounce.play();
            splashbox.generate(mainSquare.box.getPosition().x + mainSquare.side, mainSquare.box.getPosition().y, length, width);
        }
        if(mainSquare.box.getPosition().y <= 0) {
            mainSquare.speedy = -mainSquare.speedy;
            bounce.play();
            splashbox.generate(mainSquare.box.getPosition().x, mainSquare.box.getPosition().y - mainSquare.side, length, width);
        } else if (mainSquare.box.getPosition().y >= width - mainSquare.side) {
            mainSquare.speedy = -mainSquare.speedy;
            bounce.play();
            splashbox.generate(mainSquare.box.getPosition().x, mainSquare.box.getPosition().y + mainSquare.side, length, width);
        }
        // Drawings
        window.clear(bgcolor);
        mainSquare.draw(window);
        splashbox.draw(window);

        window.display();
    }

    return 0;
}