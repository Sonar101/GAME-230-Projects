// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* Our Includes */
#include "Paddle.h"
#include "Ball.h"
#include "UIManager.h"
#include "AIController.h"
#include "SoundManager.h"
#include "Random.h"

// math includes and defines
#define _USE_MATH_DEFINES
#include <math.h>

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	const int GameWidth = 800;
	const int GameHeight = 600;
	const int PauseDuration = 2; // seconds
	const int MaxLaunchAngle = M_PI / 3; // 60 degrees in radians

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		// The game window
		sf::RenderWindow window;
		// For tracking/maintaining delta time
		sf::Clock clock;
		float deltaTime;
		float ballReloadTimeRemaining;
		// Our game objects
		Paddle paddle;
		Ball ball;
		// Game State Variables
		int lives;
		int score;
		bool gameOver;
		bool waitingToReloadBall;
		// UI Text things
		UIManager uiManager;
		//AIController enemyAI;
		// Sound things
		SoundManager audio;
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		// Helpers
		void startRound();
		// Destructor
		~Game();
	};
}

#endif