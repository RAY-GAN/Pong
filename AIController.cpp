#include "AIController.h"

using namespace sf;
using namespace gm;

AIController::AIController() {

	AIPaddle = nullptr;
}

AIController::AIController(Paddle* AIPaddle) {
	this->AIPaddle = AIPaddle;
}

void AIController::Sense(Vector2f& position) {

	if (AIPaddle->getPosition().y < position.y) {

		AIPaddle->setMovmentDirection(MovementDirection::Down);
	}

	else if (AIPaddle->getPosition().y > position.y) {

		AIPaddle->setMovmentDirection(MovementDirection::Up);
	}
}

void AIController::update(RenderWindow& window, float deltaTime) {

	AIPaddle->update(window, deltaTime);
}

AIController::~AIController() {

}
