#pragma once
#include <SFML/Graphics.hpp>

class wanderEntity
{
public:
	wanderEntity(float x, float y, float radius);
	~wanderEntity();

	void wander();

	float moveSpeed = 1;

	float posX;
	float posY;
	sf::Vector2f getPosition() { return sf::Vector2f(posX, posY); }

	sf::Sprite entitySprite;
	sf::Texture texture;
	sf::Sprite GetSprite() { return entitySprite; }

	sf::CircleShape wanderCircle;

private:
	double wanderRadius;
	double wanderDistance;
	double wanderJitter;
	sf::Vector2f wanderTarget;
};

