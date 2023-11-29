#pragma once
#include "Planet.h"

sf::Vector2f Fg(sf::Vector2f F, float m) { return F / m; } // get the force vector, return the acceleration vector

sf::Vector2f A(Planet a, Planet b) {
	sf::Vector2f dir = b.getPosition() - a.getPosition(); // dir - vector connecting planets a and b
	float r = sqrt(dir.x * dir.x + dir.y * dir.y); // r is the distance between the planets
	dir.x /= r; dir.y /= r;  // normalize vector dir (make it with length 1)
	sf::Vector2f acceleration = Fg(dir * ((a.getMass() * b.getMass()) / (r * r)), a.getMass()); // set the acceleration vector
	return acceleration;
}
