#include "FireworkEffect.h"

FireworkEffect::FireworkEffect() {
	arraySize = 1;
	particleArray = new Particle * [arraySize];
	CreateParticle(0, sf::Vector2i(0, 0));
	particleArray[0]->SetLifespan(sf::seconds(-1));
	particleArray[0]->SetLifespanRemaining(sf::seconds(-1));
}

FireworkEffect::~FireworkEffect() {
	for (int i = 0; i < arraySize; i++) {
		delete (dynamic_cast<ShapeParticle*>(particleArray[i]))->GetShape();
		delete dynamic_cast<ShapeParticle*>(particleArray[i]);
	}

	delete[] particleArray;
}

void FireworkEffect::CreateParticles(int numParticles, const sf::Vector2i& mousePosition) {
	for (int i = 0; i < arraySize; i++) {
		delete (dynamic_cast<ShapeParticle*>(particleArray[i]))->GetShape();
	}
	ParticleEffect::CreateParticles(numParticles, mousePosition);
}

void FireworkEffect::CreateParticle(int index, const sf::Vector2i& mousePosition) {
	particleArray[index] = new ColorParticle();

	// Randomization calculation
	float lifeSpanCalc = Random::Range(0.1f, 3.0f);
	float sizeCalc = Random::Range(1.0f, 25.0f);
	float velocityXCalc = Random::Range(-500, 500);
	float velocityYCalc = Random::Range(-500, 500);
	int rColorCalc = Random::Range(0, 255);
	int gColorCalc = Random::Range(0, 255);
	int bColorCalc = Random::Range(0, 255);

	// set random vars of particles
	dynamic_cast<ColorParticle*>(particleArray[index])->SetLifespan(sf::seconds(lifeSpanCalc));
	dynamic_cast<ColorParticle*>(particleArray[index])->SetLifespanRemaining(sf::seconds(lifeSpanCalc));
	dynamic_cast<ColorParticle*>(particleArray[index])->SetPosition(sf::Vector2f(mousePosition));
	dynamic_cast<ColorParticle*>(particleArray[index])->SetVecolity(sf::Vector2f(velocityXCalc, velocityYCalc));
	dynamic_cast<ColorParticle*>(particleArray[index])->SetRect(sizeCalc);
	dynamic_cast<ColorParticle*>(particleArray[index])->SetColor(sf::Color(rColorCalc, gColorCalc, bColorCalc));
}