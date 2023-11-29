#pragma once
#include "Planet.h"

sf::Vector2f Fg(sf::Vector2f F, float m) { return F / m; } // �������� ������ ����, ���������� ������ ���������

sf::Vector2f A(Planet a, Planet b) {
	sf::Vector2f dir = b.getPosition() - a.getPosition(); // dir - ������, ����������� ������� � � b
	float r = sqrt(dir.x * dir.x + dir.y * dir.y); // r - ���������� ����� ���������
	dir.x /= r; dir.y /= r;  // ����������� ������ dir (������ ��� ������ 1)
	sf::Vector2f acceleration = Fg(dir * ((a.getMass() * b.getMass()) / (r * r)), a.getMass()); // ������ ������ ���������
	return acceleration;
}