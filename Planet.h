#pragma once
#include <SFML/Graphics.hpp>

// class Planet - �����, ����������� �������� ����
class Planet {
public:
sf::CircleShape shape_planet; // ������ sfml, ������ ��� �� � ����� ������������
	sf::Color color; // ���� �������
	sf::Vector2f pos; // ��������� ���������� �������
	sf::Vector2f vel; // ������ ��������. �������� ����� ������� (�,�) - �������� �� �x � �������� �� �y ��������������
	sf::Vector2f acc; // ������ ���������. �� ��������� ����� (0,0). �������� ���-��, ��� ������ ��������
	float mass; // ����� �������

	Planet(); // ����������� �� ���������
	Planet(float _rad,sf::Color _col, sf::Vector2f _pos, sf::Vector2f _vel, float mass); // �������� ����������

	void setAcceleration(sf::Vector2f new_accel) { acc = new_accel; } 
	void setPosition(sf::Vector2f new_position) {pos = new_position;}
	void setVelocity(sf::Vector2f new_velocity) {vel = new_velocity;}
	void move() {
		vel += acc; // � ������� �������� ���������� ������ ���������
		pos += vel; // � ����������� ���������� ������ ��������
		shape_planet.move(vel); // ������� ������������ ������� �� ������
	}	
	sf::Color getColor() { return color; }
	sf::Vector2f getPosition() { return pos; }
	sf::Vector2f getAccelerations() { return acc; }
	sf::Vector2f getVelocity() { return vel; }
	float getRadius() { return shape_planet.getRadius(); }
	float getMass() { return mass; }

	bool operator!=(Planet const& other) { return color != other.color || pos != other.pos || mass != other.mass; } // ����������� ���� ������
	
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
	// _rad - ������ ����
	// _col - ����
	// _pos - ���������� ��������� ����
	// _vel - ������ �������� ����
	// _mas - ����� ����
	shape_planet.setRadius(_rad);
	shape_planet.setPosition(_pos);
	shape_planet.setFillColor(_col);
	pos = _pos;
	vel = _vel;
	acc = sf::Vector2f(0, 0);
	mass = _mass;
}
