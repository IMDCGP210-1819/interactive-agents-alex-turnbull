#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

class InteractiveEntity;
class wanderEntity
{
public:
	wanderEntity(float x, float y, float radius, InteractiveEntity *otherEntity);
	~wanderEntity();

	void wander();
	void seek();

	float moveSpeed = 1;

	float posX;
	float posY;
	sf::Vector2f getPosition() { return sf::Vector2f(posX, posY); }

	float rotation;

	sf::Sprite entitySprite;
	sf::Texture texture;
	sf::Sprite GetSprite() { return entitySprite; }

	sf::CircleShape wanderCircle;
	sf::CircleShape testCircle;

	sf::Clock internalClock;

	sf::Vector2f velocity;

	InteractiveEntity *pirateEntity;

private:
	double wanderRadius;
	float wanderDistance = 100.0f;
	double wanderJitter;
	sf::Vector2f wanderTarget;
};

