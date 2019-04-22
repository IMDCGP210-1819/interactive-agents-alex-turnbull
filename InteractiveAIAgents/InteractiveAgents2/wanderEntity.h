#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "InteractiveEntity.h"

class InteractiveEntity;
class wanderEntity
{
public:
	wanderEntity(float x, float y, float radius, InteractiveEntity *otherEntity);
	~wanderEntity();

	void act();

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
	float distanceFromPirate;

private:
	double wanderRadius;
	float wanderDistance = 200.0f;
	double wanderJitter;
	sf::Vector2f wanderTarget;

	int windowLeftThreshold = 100;
	int windowRightThreshold = 1000;
	int windowTopThreshold = 100;
	int windowBottomThreshold = 700;

	int rotationAdjustment = 5;

	int checkThreshold = 150;
		
	sf::Time elapsed;
};

