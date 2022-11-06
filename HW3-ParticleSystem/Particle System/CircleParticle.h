#ifndef CIRCLE_PARTICLE_H
#define CIRCLE_PARTICLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

#include "ShapeParticle.h"

class CircleParticle : public ShapeParticle {
public:
	CircleParticle();
	~CircleParticle();
	void Update();
	void Render();

	// --- Getters
	float GetRadius();

	// --- Setters
	void SetRadius(float value);
private:

};

#endif 