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

#include "Particle.h";
#include "CircleParticle.h"
#include "Random.h";

const int NUM_PARTICLES = 30;

class ParticleEffect {
public:
	ParticleEffect();
	virtual void CreateParticles(int numParticles, const sf::Vector2i& mousePosition);
	virtual void CreateParticle(int index, const sf::Vector2i& mousePosition) = 0;
	virtual void Update(const sf::Time&);
	void Render(sf::RenderWindow& window);
	~ParticleEffect();
protected:
	Particle** particleArray;
	sf::Time prevElapsed;
	int arraySize;
};

#endif 