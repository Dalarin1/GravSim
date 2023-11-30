#include "Laws.h"
#include <iostream>
#include <thread>
#include <vector>




void move_bodies(std::vector<Planet>& celestials) {
    for (int i = 0; i < celestials.size(); i++) {
        celestials[i].acc = sf::Vector2f(0, 0); // Zero the acceleration of all celestial bodies
    }
    for (int i = 0; i < celestials.size(); i++) {
        for (int j = 0; j < celestials.size(); j++) {
            if (i != j) {
                // To the acceleration vector of the planet add the acceleration vector toward other celestial bodies
                celestials[i].acc += A(celestials[i], celestials[j]);
            }
            else continue;
        }
    }
}
void consolePlanet(std::vector<Planet>& celestials, sf::RenderWindow& window) {
    while (true) {
        std::string command;
        std::getline(std::cin, command);
        if (command == "add") {
            int radius;
            float red, green, blue, pos_x, pos_y, vel_x, vel_y, mass;
            std::cout << "radius: ";
            std::cin >> radius;
            std::cout << "color (red green blue): ";
            std::cin >> red >> green >> blue;
            std::cout << "position (pos.x pos.y): ";
            std::cin >> pos_x >> pos_y;
            std::cout << "velocity (vel_x vel_y): ";
            std::cin >> vel_x >> vel_y;
            std::cout << "mass: ";
            std::cin >> mass;

            sf::Color col = sf::Color::Color(red, green, blue);
            sf::Vector2f pos(pos_x, pos_y);
            sf::Vector2f vel(vel_x, vel_y);

            celestials.push_back(Planet(radius, col, pos, vel, mass));
        }
        if (command == "clear all") {
            celestials.clear();
            std::cout << "All planets has been deleted succesfully" << std::endl;
            continue;
        }
        if (command == "remove") {
            celestials.pop_back();
            std::cout << "latest added planet removed succesfully" << std::endl;
            continue;
        }
        if (command == "chfps") {
            int fps;
            std::cout<<"set fps to: ";
            std::cin >> fps;
            window.setFramerateLimit(fps);
            std::cout << "Now fps is " << fps << std::endl;
            continue;
        }
    }
}

int main()
{   

    setlocale(LC_ALL, "RUS");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Grafity", sf::Style::Default, settings); // Window declaration (everything is displayed in it)
    //window.setFramerateLimit(60); //uncomment to adjust fps
    std::vector<Planet> celestials;

    //celestials.push_back(Planet(2, sf::Color::Yellow, sf::Vector2f(1200, 650), sf::Vector2f(0.00, 0.0002), 20));
    //celestials.push_back(Planet(2, sf::Color::Green, sf::Vector2f(1200, 400), sf::Vector2f(-0.12, -0.00), 5));
    celestials.push_back(Planet(2, sf::Color::Blue, sf::Vector2f(600, 450), sf::Vector2f(0.00, 0.0002), 20));
    celestials.push_back(Planet(2, sf::Color::Green, sf::Vector2f(500, 450), sf::Vector2f(0.00, -0.15), 5));
    celestials.push_back(Planet(2, sf::Color::Yellow, sf::Vector2f(400, 450), sf::Vector2f(0.0, 0.43), 1));
    celestials.push_back(Planet(2, sf::Color::Red, sf::Vector2f(250, 450), sf::Vector2f(0.0, 0.26), 1));
    celestials.push_back(Planet(2, sf::Color(127, 127, 127), sf::Vector2f(250, 430), sf::Vector2f(0.0, -0.30), 0.01));
    std::cout << "Для создания собственных небесных тел воспользуйтесь командой add" << std::endl;

    std::thread th(consolePlanet, std::ref(celestials), std::ref(window));
    
    while (window.isOpen()) {
        
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // If event::Closed happens - close the window
            }
        }
        move_bodies(celestials);
        for (int i = 0; i < celestials.size(); i++) {
            celestials[i].move(); // Move the planet
            window.draw(celestials[i].shape_planet); // drawing the planet
        }
        window.display();
        
    }
    th.join();
    return 0;
}
