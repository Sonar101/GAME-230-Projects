#ifndef SHAPE_PARTICLE_H
#define SHAPE_PARTICLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

#include "Particle.h"

class ShapeParticle : public Particle {
public:
	ShapeParticle();
	~ShapeParticle();
	virtual void Update(const sf::Time& deltaTime);
	virtual void Render(sf::RenderWindow& window) = 0;
	const sf::Shape* GetShape();
protected:
	sf::Shape* shape;
};

#endif 