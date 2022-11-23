#include "SquareBall.h"

#include <random>

using namespace sf;
using namespace gm;
using namespace std;

SquareBall::SquareBall() {

}

SquareBall::SquareBall(const sf::Vector2f& position, const sf::Vector2f& size) : GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
	
	float n;
	int r;
	r = rand();
	if (r % 2 == 0) {
		n = 1;
	}
	else {
		n = -1;
	}

	setVelocity(Vector2f(float(rand() % (5 - 2 + 1) + 2) * n, float(rand() % (5 - 2 + 1) + 2))* n);
}

void SquareBall::update(sf::RenderWindow& window, float deltaTime) {

	move(velocity);

	float vertical = getVelocity().y;
	float horizontal = getVelocity().x;

	if (getPosition().y < 0) {

		setPosition(Vector2f(getPosition().x, 0));
		setVelocity(Vector2f(horizontal, -vertical));
	}

	else if (getPosition().y > 640) {
		setPosition(Vector2f(getPosition().x, 640));
		setVelocity(Vector2f(horizontal, -vertical));
	}

}

void SquareBall::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

Vector2f& SquareBall::getPosition() {
	return position;
}

void SquareBall::setPosition(const sf::Vector2f& position) {
	GameObject::setPosition(position);
	body.setPosition(position);
}

void SquareBall::move(const sf::Vector2f& velocity) {
	GameObject::move(velocity);
	body.setPosition(position);
}

const Vector2f& SquareBall::getVelocity() const {
	return velocity;
}

void SquareBall::setVelocity(const sf::Vector2f& velocity) {
	this->velocity = velocity;
}

void SquareBall::Bounce() {

	float x = getVelocity().x;
	float y = getVelocity().y;
	float add;

	if (x < 0) {
		add = 1.f;
	}
	else if (x > 0) {
		add = -1.f;
	}

	setVelocity(Vector2f(-x + add, y));
}

const Color& SquareBall::getFillColor() const {
	return body.getFillColor();
}

void SquareBall::setFillColor(const Color& color) {
	body.setFillColor(color);
}

SquareBall::~SquareBall() {

}