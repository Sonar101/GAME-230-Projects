#include "CircleParticle.h"

CircleParticle::CircleParticle() {
	// unsure if need to call base class constructor
	shape = new sf::CircleShape();
}

CircleParticle::~CircleParticle() {
	delete shape;
}

void CircleParticle::Update(const sf::Time& deltaTime) {
	ShapeParticle::Update(deltaTime);
}

void CircleParticle::Render(sf::RenderWindow& window) {
	if (isAlive) {
		window.draw(*shape);
	}
}

float CircleParticle::GetRadius() {
	return dynamic_cast<sf::CircleShape*>(shape)->getRadius();
}

void CircleParticle::SetRadius(float value) {
	dynamic_cast<sf::CircleShape*>(shape)->setRadius(value);
}