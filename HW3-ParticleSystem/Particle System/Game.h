#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <string>
#include <iostream>

/* SFML Includes */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

/* STL Includes */
#include <iostream>

/* File Includes */
#include "ParticleEffect.h"
#include "SnowEffect.h"

namespace gm {
	class Game {
	private:
		sf::Clock clock;
		ParticleEffect* particleEffect;
	public:
		/* prototypes */
		Game();
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		~Game();
	};
}

#endif