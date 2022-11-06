#include "CircleParticle.h"

CircleParticle::CircleParticle() {
	shape = new sf::CircleShape();
}

CircleParticle::~CircleParticle() {
	delete shape;
}

void CircleParticle::Update() {
	
}

void CircleParticle::Render() {

}

float CircleParticle::GetRadius() {
	return 0.0;
}

void CircleParticle::SetRadius(float value) {

}