// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"


// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), PlayerPaddle(Vector2f(20, 300), Vector2f(50, 50)), AIPaddle(Vector2f(580, 300), Vector2f(50, 50)), Ball(Vector2f(300, 300), Vector2f(30, 30)), GameUI(), GameSounds() {
	// Set our fps to 60
	Player = PlayerController(&PlayerPaddle);
	AI = AIController(&AIPaddle);
	window.setFramerateLimit(60);
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

		Player.HandleInput(event);

		//sapce to reset the game
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Space) {

				reset();

				if (GameUI.GameOver()) {
					GameUI.setAIScore(0);
					GameUI.setPlayerScore(0);

				}

			}
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {

	//get movedirection for AI Paddle

	AI.Sense(Ball.getPosition());


	// Update our paddles 
	Player.update(window, deltaTime);
	AI.update(window, deltaTime);
	Ball.update(window, deltaTime);
	

	// detect collision
	if (PlayerPaddle.collide(Vector2f(Mouse::getPosition(window)))) {
		PlayerPaddle.setFillColor(Color::Green);
	}
	else {
		PlayerPaddle.setFillColor(Color::White);
	}

	// If the mouse has entered box 2 then color it green
	if (AIPaddle.collide(Vector2f(Mouse::getPosition(window)))) {
		AIPaddle.setFillColor(Color::Green);
	}
	else {
		AIPaddle.setFillColor(Color::White);
	}

	if (Ball.collide(Vector2f(Mouse::getPosition(window)))) {
		Ball.setFillColor(Color::Green);
	}
	else {
		Ball.setFillColor(Color::White);
	}


	// Bounce if ball hits the paddles
	if (PlayerPaddle.collide(Ball.getCollider())) {
		Ball.setFillColor(Color::Blue);
		Ball.Bounce();
		GameSounds.sfxBuffer.loadFromFile("paddle_bounce.wav");
		GameSounds.PlaySFX();
	}
	else if (AIPaddle.collide(Ball.getCollider())) {
		Ball.setFillColor(Color::Blue);
		Ball.Bounce();
		GameSounds.sfxBuffer.loadFromFile("paddle_bounce.wav");
		GameSounds.PlaySFX();
	}

	//score update

	if (Ball.getPosition().x > GameWidth) {
		GameUI.setPlayerScore(GameUI.getPlayerScore() + 1);
		GameSounds.sfxBuffer.loadFromFile("score.wav");
		GameSounds.PlaySFX();
		reset();
	}
	else if (Ball.getPosition().x < 0) {
		GameUI.setAIScore(GameUI.getAIScore() + 1);
		GameSounds.sfxBuffer.loadFromFile("score.wav");
		GameSounds.PlaySFX();
		reset();
	}

	GameUI.update(window, deltaTime);

	//Wall bounce sound effect

	if (Ball.getPosition().y >= GameHeight) {
		GameSounds.sfxBuffer.loadFromFile("wall_bounce.wav");
		GameSounds.PlaySFX();
	}
	else if (Ball.getPosition().y <= 0) {
		GameSounds.sfxBuffer.loadFromFile("wall_bounce.wav");
		GameSounds.PlaySFX();
	}

	//game over sound effect
	if (GameUI.GameOver()) {
		GameSounds.sfxBuffer.loadFromFile("victory.wav");
		GameSounds.PlaySFX();
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Draw our paddles and ball
	PlayerPaddle.render(window, deltaTime);
	AIPaddle.render(window, deltaTime);
	Ball.render(window, deltaTime);
	GameUI.render(window, deltaTime);
	// Display the window buffer for this frame
	window.display();
}

//reset the game
void Game::reset() {

	PlayerPaddle.setPosition(Vector2f(20, 300));
	AIPaddle.setPosition(Vector2f(580, 300));
	Ball.setPosition(Vector2f(300,300));

	float n;
	int r;
	r = rand();
	if (r % 2 == 0) {
		n = 1;
	}
	else {
		n = -1;
	}

	Ball.setVelocity(Vector2f(float(rand() % (5 - 2 + 1) + 2) * n, float(rand() % (5 - 2 + 1) + 2)) * n);

	if (GameUI.GameOver()) {
		Ball.setVelocity(Vector2f(0, 0));

	}
}


// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}