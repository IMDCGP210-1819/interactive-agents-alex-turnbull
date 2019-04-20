#include "wanderEntity.h"



wanderEntity::wanderEntity(float x, float y, float radius)
{
	posX = x;
	posY = y;

	entitySprite.setOrigin(20, 20);
	entitySprite.setPosition(getPosition());

	std::string filename = "Assets\\skeleton.png";
	texture.loadFromFile(filename);	
	entitySprite.setTexture(texture);

	wanderCircle.setRadius(radius);
	wanderCircle.setOrigin(wanderCircle.getGlobalBounds().width/2, wanderCircle.getGlobalBounds().height / 2);
	wanderCircle.setPosition(getPosition());
	wanderCircle.setFillColor(sf::Color::Red);
}


wanderEntity::~wanderEntity()
{
}

void wanderEntity::wander()
{
	wanderTarget += sf::Vector2f(rand() % 3 + (-1) * wanderJitter, rand() % 3 + (-1) * wanderJitter);
}
