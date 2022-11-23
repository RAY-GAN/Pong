#ifndef AICONTROLLER_H
#define AICONTROLEER_H

#include "Paddle.h"

namespace gm {
	class AIController
	{
	public:
		Paddle* AIPaddle;

		AIController();

		AIController(Paddle* AIPaddle);

		void Sense(sf::Vector2f& position);

		void update(sf::RenderWindow& window, float deltaTime);

		~AIController();

	};
}

#endif

