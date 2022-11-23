#include "PlayerController.h"

using namespace sf;
using namespace gm;

PlayerController::PlayerController() {

	PlayerPaddle = nullptr;
}

PlayerController::PlayerController(Paddle* PlayerPaddle) {

	this->PlayerPaddle = PlayerPaddle;

}

void PlayerController::HandleInput(Event event) {

	if (event.type == Event::KeyPressed) {
		if (event.key.code == Keyboard::Up) {
			PlayerPaddle->setMovmentDirection(MovementDirection::Up);
		}
		else if (event.key.code == Keyboard::Down) {
			PlayerPaddle->setMovmentDirection(MovementDirection::Down);
		}
	}

	if (event.type == Event::KeyReleased) {
		if (event.key.code == Keyboard::Up && PlayerPaddle->getMovementDirection() == MovementDirection::Up) {
			PlayerPaddle->setMovmentDirection(MovementDirection::None);
		}
		if (event.key.code == Keyboard::Down && PlayerPaddle->getMovementDirection() == MovementDirection::Down) {
			PlayerPaddle->setMovmentDirection(MovementDirection::None);
		}
	}


}

void PlayerController::update(sf::RenderWindow& window, float deltaTime) {

	PlayerPaddle->update(window, deltaTime);

}

PlayerController::~PlayerController() {

}