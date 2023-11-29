#pragma once
#include "Planet.h"

sf::Vector2f Fg(sf::Vector2f F, float m) { return F / m; } // получаем вектор силы, возвращаем вектор ускорения

sf::Vector2f A(Planet a, Planet b) {
	sf::Vector2f dir = b.getPosition() - a.getPosition(); // dir - вектор, соединяющий планеты а и b
	float r = sqrt(dir.x * dir.x + dir.y * dir.y); // r - расстояние между планетами
	dir.x /= r; dir.y /= r;  // нормализуем вектор dir (делаем его длиной 1)
	sf::Vector2f acceleration = Fg(dir * ((a.getMass() * b.getMass()) / (r * r)), a.getMass()); // задаем вектор ускорения
	return acceleration;
}