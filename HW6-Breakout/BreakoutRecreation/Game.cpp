// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), 
paddle(Vector2f(20, GameHeight - PaddleHeight * 2), Vector2f(PaddleWidth,PaddleHeight)),
ball(Vector2f(GameWidth / 2, GameHeight / 2), Vector2f(BallSize, BallSize))
{
	// Set our fps to 60
	window.setFramerateLimit(60);

	// set up pause time
	ballReloadTimeRemaining = PauseDuration;

	// Set up game state
	lives = 2;
	score = 0;
	currLevel = 1;
	gameOver = false;
	waitingToReloadBall = false;

	// set up level
	blocks = new Block*[NumBlockColumns];
	for (int col = 0; col < NumBlockColumns; col++) {
		blocks[col] = new Block[NumBlockRows];
	}
	for (int col = 0; col < NumBlockColumns; col++) {
		for (int row = 0; row < NumBlockRows; row++) {
			blocks[col][row].setPosition(sf::Vector2f(BLOCKSIZE.x * col, BLOCKSIZE.y * row));
		}
	}
	generateLevel("level1.txt");

	// Set up UI
	uiManager.SetUIPosition(
		sf::Vector2f(15, GameHeight - 120), 
		sf::Vector2f(GameWidth - 125, GameHeight - 120),
		sf::Vector2f(GameWidth/2 - 120,GameHeight/2 - 40)
	);
	
	uiManager.SetLivesText(lives);
	uiManager.SetScoreText(score);
	uiManager.SetBackgroundText("LEVEL 1");

	// Position game objects
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

	for (int col = 0; col < NumBlockColumns; col++) {
		for (int row = 0; row < NumBlockRows; row++) {
			delete &blocks[col][row];
		}
	}
	delete [] blocks; 
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

		if (event.type == sf::Event::MouseButtonPressed) {
			ball.setLaunched(true);
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	ballReloadTimeRemaining -= deltaTime;
	
	if (waitingToReloadBall) {
		if (ballReloadTimeRemaining <= 0) {
			ball.setLaunched(false);
			waitingToReloadBall = false;
			uiManager.SetLivesText(lives);
		}
	}
	
	// Update our paddle (i.e., move it based on the block's specified movement direction)
	paddle.update(window, deltaTime);
	ball.update(window, deltaTime);
	
	if (ball.getLaunched() == false) {
		ball.setPosition(sf::Vector2f(paddle.getPosition().x + PaddleWidth / 2 + BallSize, paddle.getPosition().y - BallSize));
	} else {
		
		// --- check for level win condition
		int numBlocksRemaining = 0;
		for (int col = 0; col < NumBlockColumns; col++) {
			for (int row = 0; row < NumBlockRows; row++) {
				if(blocks[col][row].getIsAlive()) {
					numBlocksRemaining++;
				}
			}
		}
		if (numBlocksRemaining <= 0) {
			// Set up next level
			ball.setVelocity(sf::Vector2f(0, 1));
			ball.setLaunched(false);
			ball.setSpeedTick(ball.getSpeedTick() + 1);
			generateLevel("level1.txt");
			currLevel++;
			uiManager.SetBackgroundText("Level " + std::to_string(currLevel));
		}
		
		
		// --- Acounting for different collisions
		
		// If paddle collides with the ball(while the ball is moving down)
		if (paddle.collide(ball.getCollider()) && ball.getVelocity().y > 0) {
			ball.knockBack(PaddleWidth, paddle.getPosition().x);
			audio.PlaySFX(paddleHit);
		}

		// If ball collides with any blocks
		for (int col = 0; col < NumBlockColumns; col++) {
			for (int row = 0; row < NumBlockRows; row++) {
				if (blocks[col][row].getIsAlive()) {
					if (blocks[col][row].collide(ball.getCollider())) {
						audio.PlaySFX(paddleHit);
						score+= blocks[col][row].TakeDamage();
						uiManager.SetScoreText(score);
						KnockSide knockDir = CalcKnockSide(ball.getPosition(), blocks[col][row].getPosition());
						if (knockDir == Vertical) {
							ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
						}
					}
				}
			}
		}

		// If ball collides with left, right, or top walls
		if (ball.getPosition().x <= 0 && ball.getVelocity().x < 0) {
			ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
			audio.PlaySFX(wallHit);
		}
		else if (ball.getPosition().x >= window.getSize().x - BallSize && ball.getVelocity().x > 0) {
			ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
			audio.PlaySFX(wallHit);
		}
		else if (ball.getPosition().y <= 0 && ball.getVelocity().y < 0) {
			ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
			audio.PlaySFX(wallHit);
		}

		// if ball collides with bottom wall (lose life and reset)
		if (ball.getPosition().y >= window.getSize().y - BallSize && ball.getVelocity().y > 0 && !waitingToReloadBall && !gameOver) {
			if (lives > 0) {
				lives--;
				audio.PlaySFX(loseLife);
				waitingToReloadBall = true;
				ballReloadTimeRemaining = PauseDuration;
			} else {
				audio.PlaySFX(loseLife);
				uiManager.SetBackgroundText("GAME OVER");
				uiManager.SetBackgroundFontColor(sf::Color(110,0,0));
				gameOver = true;
			}
		}
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Draw our UI
	uiManager.Render(window, deltaTime);

	// Draw our game objects
	paddle.render(window, deltaTime);
	ball.render(window, deltaTime);
	for (int col = 0; col < NumBlockColumns; col++) {
		for (int row = 0; row < NumBlockRows; row++) {
			blocks[col][row].render(window, deltaTime);
		}
	}

	// Display the window buffer for this frame
	window.display();
}

void Game::startRound() {
	
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}

// Helper functions
const KnockSide& Game::CalcKnockSide(const sf::Vector2f& ballPos, const sf::Vector2f& blockPos) {
	sf::Vector2f ballCenterPos = sf::Vector2f(ballPos.x + BallSize/2, ballPos.y + BallSize / 2);
	sf::Vector2f blockCenterPos = sf::Vector2f(blockPos.x + BLOCKSIZE.x / 2, blockPos.y + BLOCKSIZE.y / 2);

	float xDifference = abs(blockCenterPos.x - ballCenterPos.x);

	KnockSide side;
	
	if (xDifference < BLOCKSIZE.x - 2) {
		side = Vertical;
	}
	else {
		side = Horizontal;
	}

	return side;
}

void Game::generateLevel(const std::string& textfileName) {
	std::ifstream inputLevelFile;
	inputLevelFile.open(textfileName, std::ios::out);
	if (!inputLevelFile.is_open())
	{
		// can't open file, so give an error message
		std::cout << "ERROR - Could not find file to load" << std::endl;
	}
	else
	{
		// --- read input

		std::string currLine;
		// for every line in the text file...
		int row = 0;
		while (getline(inputLevelFile, currLine))
		{
			std::string currWord = "";
			int currCharNum = 0;
			char currChar = currLine[currCharNum];
			int column = 0;
			while (currCharNum < currLine.length()) {
				// ...loop through the line and build the numbers out of single characters
				if (currChar == ' ')
				{
					if (stoi(currWord) == 0)
					{
						// select the texture associated with the correct number
						blocks[column][row].setIsAlive(false);
					}
					else if (stoi(currWord) == 1)
					{
						// -1 should be an empty texture
						blocks[column][row].setIsAlive(true);
						blocks[column][row].setUpBlock(weak);
					} else {
						blocks[column][row].setIsAlive(true);
						blocks[column][row].setUpBlock(strong);
					}

					column++;
					currWord = "";
				}
				else if (currChar != '\n')
				{
					currWord = currWord + currChar;
				}
				currCharNum++;
				currChar = currLine[currCharNum];
			}
			row++;
		}

		inputLevelFile.close();
	}
}