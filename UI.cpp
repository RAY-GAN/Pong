#include "UI.h"


using namespace sf;
using namespace gm;
using namespace std;

UI::UI() {

	PlayerScore = 0;
	AIScore = 0;

	font.loadFromFile("arial.ttf");
	

	PSdisplay.setString(to_string(PlayerScore));
	ASdisplay.setString(to_string(AIScore));
	Victory.setString("Game Over");
	PSdisplay.setFont(font);
	ASdisplay.setFont(font);
	Victory.setFont(font);
	PSdisplay.setPosition(Vector2f(20.f, 100.f));
	ASdisplay.setPosition(Vector2f(580.f, 100.f));
	Victory.setPosition(Vector2f(300.f, 400.f));

}


int UI::getPlayerScore() const {

	return PlayerScore;

}

void UI::setPlayerScore(int score) {

	PlayerScore = score;
}

int UI::getAIScore() const {

	return AIScore;

}

void UI::setAIScore(int score) {

	AIScore = score;
}

void UI::update(sf::RenderWindow& window, float deltaTime) {

	PSdisplay.setString(to_string(PlayerScore));
	ASdisplay.setString(to_string(AIScore));
}

void UI::render(sf::RenderWindow& window, float deltaTime) {

	window.draw(PSdisplay);
	window.draw(ASdisplay);
	if (GameOver()) {
		window.draw(Victory);
	}
}

bool UI::GameOver() const {
	return (PlayerScore == WinScore) || (AIScore == WinScore);
}

UI::~UI() {

}