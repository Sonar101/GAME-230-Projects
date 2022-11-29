// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), 
paddle1(Vector2f(20, GameHeight/2 - PaddleHeight / 2), Vector2f(PaddleWidth,PaddleHeight)), 
paddle2(Vector2f(GameWidth-PaddleWidth-20, GameHeight/2 - PaddleHeight / 2), Vector2f(PaddleWidth, PaddleHeight)),
ball(Vector2f(GameWidth/2, GameHeight/2), Vector2f(BallSize, BallSize)) {
	
	// Set our fps to 60
	window.setFramerateLimit(60);

	// set up pause time
	pauseTimeRemaining = PauseDuration;

	// Set up UI
	score1 = 0;
	score2 = 0;
	gameOver = false;
	uiManager.SetUIPosition(
		sf::Vector2f(25,25), 
		sf::Vector2f(window.getSize().x - 75, 25), 
		sf::Vector2f(window.getSize().x / 2 - 160, window.getSize().y / 2 - 120)
	);

	uiManager.SetMessageText("GET READY");
	uiManager.SetIsDisplayingMessage(true);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	while (window.isOpen())
	{
		// Every frame we...
		// Keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		// Handle keyboard input to move paddle 1
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up) {
				paddle1.setMovmentDirection(MovementDirection::Up);
			}else if (event.key.code == Keyboard::Down) {
				paddle1.setMovmentDirection(MovementDirection::Down);
			}
		}

		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::Up && paddle1.getMovementDirection() == MovementDirection::Up) {
				paddle1.setMovmentDirection(MovementDirection::None);
			}
			if (event.key.code == Keyboard::Down && paddle1.getMovementDirection() == MovementDirection::Down) {
				paddle1.setMovmentDirection(MovementDirection::None);
			}
		}

		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Space) {
				// set up pause time
				pauseTimeRemaining = PauseDuration;

				// Set up UI
				score1 = 0;
				score2 = 0;
				uiManager.SetScore1(score1);
				uiManager.SetScore2(score2);
				gameOver = false;

				resetObjects();

				uiManager.SetMessageText("GET READY");
				uiManager.SetIsDisplayingMessage(true);
			}
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	pauseTimeRemaining-= deltaTime;
	
	if (pauseTimeRemaining <= 0 && !gameOver) {
		uiManager.SetIsDisplayingMessage(false);
		// Update our boxes (i.e., move them based on the block's specified movement direction)
		paddle1.update(window, deltaTime);
		enemyAI.Sense(ball);
		enemyAI.Update(paddle2, PaddleHeight);
		paddle2.update(window, deltaTime);
		ball.update(window, deltaTime);

		// If box 1 and 2 have collided then turn 1 blue and 2 red
		if (paddle2.collide(paddle1.getCollider())) {
			paddle1.setFillColor(Color::Blue);
			paddle2.setFillColor(Color::Red);
		}

		// If paddle 1 collides with the ball(while the ball is moving left)
		if (paddle1.collide(ball.getCollider()) && ball.getBallDirection() == BallDirection::Left) {
			ball.knockBack(PaddleHeight, paddle1.getPosition().y);
		}

		// If paddle 2 collides with the ball(while the ball is moving right)
		if (paddle2.collide(ball.getCollider()) && ball.getBallDirection() == BallDirection::Right) {
			ball.knockBack(PaddleHeight, paddle2.getPosition().y);
		}

		// If ball collides with the top or bottom wall
		if (ball.getPosition().y <= 0 && ball.getVelocity().y < 0) {
			ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
		} else if (ball.getPosition().y >= window.getSize().y - BallSize && ball.getVelocity().y > 0) {
			ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
		}

		// If ball collides with left wall, score for player 2 and reset
		if (ball.getPosition().x <= 0) {
			score2++;
			uiManager.SetScore2(score2);
			if (score2 >= 5) {
				uiManager.SetMessageText("Player 2 WINS\nSpace to Restart");
				uiManager.SetIsDisplayingMessage(true);
				gameOver = true;
			} else {
				uiManager.SetMessageText("Player 2 Scored");
				uiManager.SetIsDisplayingMessage(true);
				startRound();
			}
		}

		// If ball collides with right wall, score for player 1 and reset
		if (ball.getPosition().x >= window.getSize().x - BallSize) {
			score1++;
			uiManager.SetScore1(score1);
			if (score1 >= 5) {
				uiManager.SetMessageText("Player 1 WINS\nSpace to Restart");
				uiManager.SetIsDisplayingMessage(true);
				gameOver = true;
			} else {
				uiManager.SetMessageText("Player 1 Scored");
				uiManager.SetIsDisplayingMessage(true);
				startRound();
			}
		}
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Draw our boxes
	paddle1.render(window, deltaTime);
	paddle2.render(window, deltaTime);
	ball.render(window, deltaTime);

	// Draw our UI
	uiManager.Render(window, deltaTime);

	// Display the window buffer for this frame
	window.display();
}

void Game::startRound() {
	resetObjects();
	pauseTimeRemaining = PauseDuration;
}

void Game::resetObjects() {
	paddle1.setPosition(Vector2f(20, GameHeight / 2 - PaddleHeight / 2));
	paddle2.setPosition(Vector2f(GameWidth - PaddleWidth - 20, GameHeight / 2 - PaddleHeight / 2));
	ball.setPosition(Vector2f(GameWidth / 2, GameHeight / 2));
	ball.setVelocity(Vector2f(-MinBallSpeedPerSecond, 0));
	ball.setBallDirection(Left);
	ball.setTotalKnocks(0);
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}