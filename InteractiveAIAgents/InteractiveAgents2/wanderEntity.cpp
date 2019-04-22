#include "wanderEntity.h"

wanderEntity::wanderEntity(float x, float y, float radius, InteractiveEntity *otherEntity)
{
	pirateEntity = otherEntity;

	posX = x;
	posY = y;

	rotation = -20;

	entitySprite.setOrigin(20, 20);
	entitySprite.setPosition(getPosition());
	entitySprite.setRotation(rotation);

	std::string filename = "Assets\\skeleton.png";
	texture.loadFromFile(filename);	
	entitySprite.setTexture(texture);

	wanderCircle.setRadius(radius);
	wanderCircle.setOrigin(wanderCircle.getGlobalBounds().width/2, wanderCircle.getGlobalBounds().height / 2);
	wanderCircle.setFillColor(sf::Color::Transparent);
	wanderCircle.setOutlineColor(sf::Color::Red);
	wanderCircle.setOutlineThickness(3);	

	velocity = sf::Vector2f(cos(rotation * 3.14 / 180), sin(rotation * 3.14 / 180));
	wanderCircle.setPosition(getPosition() + wanderDistance * velocity);

}


wanderEntity::~wanderEntity()
{
}

void wanderEntity::wander()
{
	sf::Time elapsed = internalClock.getElapsedTime();

	auto randomPoint = wanderCircle.getTransform().transformPoint(wanderCircle.getPoint(rand() * 31));
	float oldRotation = entitySprite.getRotation();

	float targetRot = atan2(randomPoint.y - entitySprite.getPosition().y, randomPoint.x - entitySprite.getPosition().x) * (180/3.14);

	float newRot = oldRotation + ((targetRot - oldRotation) * 1 * elapsed.asSeconds());

	sf::Vector2f velocity2 = sf::Vector2f(cos(entitySprite.getRotation() * 3.14 / 180), sin(entitySprite.getRotation() * 3.14 / 180));
	sf::Vector2f pos = entitySprite.getPosition() + (velocity2 * 50.0f) * elapsed.asSeconds();

	entitySprite.setPosition(pos);
	entitySprite.setRotation(targetRot);

	velocity = sf::Vector2f(cos(entitySprite.getRotation() * 3.14 / 180), sin(entitySprite.getRotation() * 3.14 / 180));
	wanderCircle.setPosition(entitySprite.getPosition() + wanderDistance * velocity);
	testCircle.setRadius(5);
	testCircle.setFillColor(sf::Color::Green);
	testCircle.setOrigin(testCircle.getGlobalBounds().width / 2, testCircle.getGlobalBounds().height / 2);
	testCircle.setPosition(randomPoint);

	//wanderTarget += sf::Vector2f(rand() % 3 + (-1) * wanderJitter, rand() % 3 + (-1) * wanderJitter);
	internalClock.restart();
}

void wanderEntity::seek()
{
}
