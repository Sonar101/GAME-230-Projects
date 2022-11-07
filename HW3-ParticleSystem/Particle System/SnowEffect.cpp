#include "SnowEffect.h"

SnowEffect::SnowEffect() {
	arraySize = 1;
	particleArray = new Particle*[arraySize];
	CreateParticle(0, sf::Vector2i(0,0));
	particleArray[0]->SetLifespan(sf::seconds(-1));
	particleArray[0]->SetLifespanRemaining(sf::seconds(-1));
}

SnowEffect::~SnowEffect() {
	for (int i = 0; i < arraySize; i++) {
		delete (dynamic_cast<ShapeParticle*>(particleArray[i]))->GetShape();
		delete dynamic_cast<ShapeParticle*>(particleArray[i]);
	}
	
	delete[] particleArray;
}

void SnowEffect::CreateParticles(int numParticles, const sf::Vector2i& mousePosition) {
	for (int i = 0; i < arraySize; i++) {
		delete (dynamic_cast<ShapeParticle*>(particleArray[i]))->GetShape();
	}
	ParticleEffect::CreateParticles(numParticles, mousePosition);
}

void SnowEffect::CreateParticle(int index, const sf::Vector2i& mousePosition) {
	particleArray[index] = new CircleParticle();

	// Randomization calculation
	float lifeSpanCalc = Random::Range(0.1f, 10.0);
	float sizeCalc = Random::Range(1.0f, 5.0f);
	float velocityYCalc = Random::Range(1, 200);
	float snowLineOffset = Random::Range(-200, 200);

	// set random vars of particles
	dynamic_cast<CircleParticle*>(particleArray[index])->SetLifespan(sf::seconds(lifeSpanCalc));
	dynamic_cast<CircleParticle*>(particleArray[index])->SetLifespanRemaining(sf::seconds(lifeSpanCalc));
	dynamic_cast<CircleParticle*>(particleArray[index])->SetPosition(sf::Vector2f(mousePosition.x + snowLineOffset, mousePosition.y));
	dynamic_cast<CircleParticle*>(particleArray[index])->SetVecolity(sf::Vector2f(0, velocityYCalc));
	dynamic_cast<CircleParticle*>(particleArray[index])->SetRadius(sizeCalc);
}