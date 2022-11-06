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
	void Update();
	void Render();
	void GetShape();
protected:
	sf::Shape* shape;
};

#endif 