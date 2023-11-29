#include "Laws.h"

int main()
{
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 6;
    sf::RenderWindow window(sf::VideoMode(2400, 1300), "Grafity", sf::Style::Default, settings); // Window declaration (everything is displayed in it)
    //window.setFramerateLimit(60); //uncomment to adjust fps

    // Next is the announcement of celestial bodies
    Planet Sun(2, sf::Color::Yellow, sf::Vector2f(1200, 650), sf::Vector2f(0.00, 0.0002), 20);
    Planet Earth(2, sf::Color::Green, sf::Vector2f(1200, 400), sf::Vector2f(-0.12, -0.00),5);
    Planet a = Planet(2, sf::Color::Blue, sf::Vector2f(1200, 650), sf::Vector2f(0.00, 0.0002), 20);
    Planet d = Planet(2, sf::Color::Green, sf::Vector2f(1100, 650), sf::Vector2f(0.00, -0.15), 5);
    Planet o = Planet(2, sf::Color::Yellow, sf::Vector2f(1000, 650), sf::Vector2f(0.0, 0.43), 1);
    Planet b = Planet(2, sf::Color::Red, sf::Vector2f(850, 650), sf::Vector2f(0.0, 0.26), 1);
    Planet c = Planet(2, sf::Color(127, 127, 127), sf::Vector2f(850, 630), sf::Vector2f(0.0, -0.30), 0.01);
    Planet Moon(2, sf::Color::Cyan, sf::Vector2f(710, 460), sf::Vector2f(1,0), 20);

    Planet planets[5]{ a,d, o,b,c}; // Create an array containing the selected planets
    while (window.isOpen()) {


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { 
                window.close(); // If event::Closed happens - close the window
            }
        }
        for (int i = 0; i < 5; i++) {
            planets[i].acc = sf::Vector2f(0, 0); // Zero the acceleration of all celestial bodies
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i != j) {
                    // To the acceleration vector of the planet add the acceleration vector toward other celestial bodies
                    planets[i].acc += A(planets[i], planets[j]);
                }
                else continue;
            }
        }
        for (int i = 0; i < 5; i++) {
            planets[i].move(); // Move the planet
            window.draw(planets[i].shape_planet); // drawing the planet
        }
        window.display();
    }
    return 0;
}
