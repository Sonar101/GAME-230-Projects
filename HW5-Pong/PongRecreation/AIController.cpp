#include "AIController.h"

using namespace sf;
using namespace gm;

AIController::AIController() : sensedBallPos(sf::Vector2f(0,0)) {

}

void AIController::Sense(const gm::Ball& ball) {
	sensedBallPos = ball.getPosition();
}

void AIController::Update(gm::Paddle& enemyPaddle, float paddleHeight) {
	float distY = (enemyPaddle.getPosition().y + paddleHeight/2) - sensedBallPos.y;
	float distYRatio = distY / maxTrackDistanceY;
	if (distYRatio > 1) {
		distYRatio = 1;
	} else if (distYRatio < -1) {
		distYRatio = -1;
	}

	if (distYRatio > 0) {
		enemyPaddle.setMovmentDirection(MovementDirection::Up);
	} else {
		enemyPaddle.setMovmentDirection(MovementDirection::Down);
	}

	enemyPaddle.setVerticalVelocity(PlayerMovementSpeedPerSecond * abs(distYRatio));
}

AIController::~AIController() {

}