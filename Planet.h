#pragma once
#include <SFML/Graphics.hpp>

// class Planet - класс, описывающий небесное тело
class Planet {
public:
sf::CircleShape shape_planet; // объект sfml, именно его мы и будем отрисовывать
	sf::Color color; // цвет планеты
	sf::Vector2f pos; // начальные координаты планеты
	sf::Vector2f vel; // вектор скорости. Задается двумя числами (х,у) - скорость по оx и скорость по оy соответственно
	sf::Vector2f acc; // вектор ускорения. По умолчанию равен (0,0). Задается так-же, как вектор скорости
	float mass; // масса планеты

	Planet(); // конструктор по умолчанию
	Planet(float _rad,sf::Color _col, sf::Vector2f _pos, sf::Vector2f _vel, float mass); // основной коструктор

	void setAcceleration(sf::Vector2f new_accel) { acc = new_accel; } 
	void setPosition(sf::Vector2f new_position) {pos = new_position;}
	void setVelocity(sf::Vector2f new_velocity) {vel = new_velocity;}
	void move() {
		vel += acc; // к вектору скорости прибавляем вектор ускорения
		pos += vel; // к координатам прибавляем вектор скорости
		shape_planet.move(vel); // двигаем отображаемую планету на экране
	}	
	sf::Color getColor() { return color; }
	sf::Vector2f getPosition() { return pos; }
	sf::Vector2f getAccelerations() { return acc; }
	sf::Vector2f getVelocity() { return vel; }
	float getRadius() { return shape_planet.getRadius(); }
	float getMass() { return mass; }

	bool operator!=(Planet const& other) { return color != other.color || pos != other.pos || mass != other.mass; } // неравенство двух планет
	
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
	// _rad - радиус тела
	// _col - цвет
	// _pos - координаты небесного тела
	// _vel - вектор скорости тела
	// _mas - масса тела
	shape_planet.setRadius(_rad);
	shape_planet.setPosition(_pos);
	shape_planet.setFillColor(_col);
	pos = _pos;
	vel = _vel;
	acc = sf::Vector2f(0, 0);
	mass = _mass;
}
