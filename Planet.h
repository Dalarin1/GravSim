#pragma once
#include <SFML/Graphics.hpp>

// class Planet - a class describing a celestial body
class Planet {
public:
sf::CircleShape shape_planet; // sfml object, that's what we'll render
	sf::Color color; // planetary color
	sf::Vector2f pos; // planetary initial coordinates
	sf::Vector2f vel; // velocity vector. It is defined by two numbers (x,y) - velocity along ox and velocity along oy, respectively
	sf::Vector2f acc; // acceleration vector. Default value is (0,0). Set in the same way as the velocity vector
	float mass; // mass of the celestial body

	Planet(); // default constructor
	Planet(float _rad,sf::Color _col, sf::Vector2f _pos, sf::Vector2f _vel, float mass); // îñíîâíîé êîñòðóêòîð

	void setAcceleration(sf::Vector2f new_accel) { acc = new_accel; } 
	void setPosition(sf::Vector2f new_position) {pos = new_position;}
	void setVelocity(sf::Vector2f new_velocity) {vel = new_velocity;}
	void move() {
		vel += acc; // to the velocity vector add the acceleration vector
		pos += vel; // add the velocity vector to the coordinates
		shape_planet.move(vel); // move the displayed planet on the screen
	}	
	sf::Color getColor() { return color; }
	sf::Vector2f getPosition() { return pos; }
	sf::Vector2f getAccelerations() { return acc; }
	sf::Vector2f getVelocity() { return vel; }
	float getRadius() { return shape_planet.getRadius(); }
	float getMass() { return mass; }

	bool operator!=(Planet const& other) { return color != other.color || pos != other.pos || mass != other.mass; }
	
};
Planet::Planet() {
	shape_planet = sf::CircleShape(0);
	color = sf::Color::Black;
	pos = sf::Vector2f(0, 0);
	vel = sf::Vector2f(0, 0);
	acc = sf::Vector2f(0, 0);
	mass = 0.0;
}
Planet::Planet(float _rad,sf::Color _col, sf::Vector2f _pos, sf::Vector2f _vel, float _mass) {
	// _rad - body radius
	// _col - color
	// _pos - coordinates of the celestial body
	// _vel - velocity vector of the body
	// _mas - body mass
	shape_planet.setRadius(_rad);
	shape_planet.setPosition(_pos);
	shape_planet.setFillColor(_col);
	pos = _pos;
	vel = _vel;
	acc = sf::Vector2f(0, 0);
	mass = _mass;
}
