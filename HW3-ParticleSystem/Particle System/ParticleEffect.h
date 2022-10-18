// Created by Nathann Latimore

#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

#include "Particle.h"
#include "Random.h"

const int NUM_PARTICLES = 30;

class ParticleEffect {
public:
	ParticleEffect();
	ParticleEffect(sf::Vector2i mousePosition, sf::Time minLifeSpan, sf::Time maxLifeSpan, float minSize, float maxSize, float maxVelocity);
	void Update(sf::Time);
	void Render(sf::RenderWindow& window);
	~ParticleEffect();
private:
	Particle* particleArray;
	sf::Time prevElapsed;
};

#endif 