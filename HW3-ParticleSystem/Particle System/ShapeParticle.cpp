#include "ShapeParticle.h"

ShapeParticle::ShapeParticle() {
	
}

ShapeParticle::~ShapeParticle() {
	std::cout << "ShapeParticle deconstructor" << std::endl;
}

void ShapeParticle::Update(const sf::Time& deltaTime) {
	if (isAlive) {
		Particle::Update(deltaTime);
		
		// set the graphic's position
		shape->setPosition(position);
	}
}

const sf::Shape* ShapeParticle::GetShape() {
	return shape;
}