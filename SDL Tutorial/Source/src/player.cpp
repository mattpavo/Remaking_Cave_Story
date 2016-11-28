#include "player.h"
#include "graphics.h"

Player::Player() {}

Player::Player(Graphics &graphics, float x, float y) : 
	AnimatedSprite(graphics, "MyChar.png", 0, 0,
		16, 16, x, y, 100)
{
	graphics.loadImage("MyChar.png");

	this->setupAnimations();
	this->playAnimation("RunRight");
}

void Player::setupAnimations() {
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation) {}

void Player::update(float elapsedTime) {
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}