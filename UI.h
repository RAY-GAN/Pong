
#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <sstream>

namespace gm {

	const int WinScore = 3;

	class UI
	{
	private:
		int PlayerScore;
		int AIScore;
		sf::Font font;
		sf::Text PSdisplay;
		sf::Text ASdisplay;
		sf::Text Victory;

	public:

		UI();

		int getPlayerScore() const;

		void setPlayerScore(int score);

		int getAIScore() const;

		void setAIScore(int score);

		void update(sf::RenderWindow& window, float deltaTime);

		void render(sf::RenderWindow& window, float deltaTime);

		bool GameOver() const;

		~UI();


	};
}

#endif


