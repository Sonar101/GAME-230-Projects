#include "ShapeParticle.h"

ShapeParticle::ShapeParticle() {
	
}

ShapeParticle::~ShapeParticle() {
	
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