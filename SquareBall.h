#ifndef SQUAREBALL_H
#define SQUAREBALL_H

#include "GameObject.h"

namespace gm {
    class SquareBall :
        public GameObject
    {
    private:
        sf::RectangleShape body;
        sf::Vector2f velocity;

    public:
        SquareBall();

        SquareBall(const sf::Vector2f& position, const sf::Vector2f& size);

        virtual void update(sf::RenderWindow& window, float deltaTime);

        virtual void render(sf::RenderWindow& window, float deltaTime);

        virtual sf::Vector2f& getPosition();

        virtual void setPosition(const sf::Vector2f& position);

        virtual void move(const sf::Vector2f& velocity) override;

        const sf::Vector2f& getVelocity() const;

        void setVelocity(const sf::Vector2f& velocity);

        void Bounce();

        const sf::Color& getFillColor() const;

        void setFillColor(const sf::Color& color);

        virtual ~SquareBall();

    };
}

#endif


