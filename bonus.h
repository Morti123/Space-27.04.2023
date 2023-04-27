#pragma once
#include "Game_Object.h"
#include "Player.h"
class Bonus : public GameObj {
public:
	enum BonusType { MEDKIT, SPEED_BOOST, MAX_BONUS_TYPE };
	Bonus(sf::Vector2f meteorPos,size_t bonustype);
	sf::FloatRect getHitBox();
	void update();
	void setDel();
	bool isToDel();
	void draw(sf::RenderWindow& window);
	bool offScreen();
	void act(Player& player);

private:
	BonusType type;
	sf::Clock timer;
	bool del = false;
};

Bonus::Bonus(sf::Vector2f meteorPos,size_t bonusType) {
	type = (BonusType)bonusType;
	switch (type) {
	case MEDKIT:
		this->type = type;
		texture.loadFromFile(MEDKIT_FILE_NAME);
		break;

	case  SPEED_BOOST:
		this->type = type;
		texture.loadFromFile(SPEED_BOOST_FILE_NAME);
		break;
	}
	sprite.setTexture(texture);
	sprite.setPosition(meteorPos);
	timer.restart();
}

void Bonus::update() {
	int now = timer.getElapsedTime().asMilliseconds();
	if (now > 5000) {
		del = true;
	}
}

void Bonus::draw(sf::RenderWindow& window) { window.draw(sprite); }

sf::FloatRect Bonus::getHitBox() { return sprite.getGlobalBounds(); }

bool Bonus::offScreen() {
	if (sprite.getPosition().y > WINDOW_HEIGHT) return true;
	return false;
}
bool Bonus::isToDel() { return del; }

void Bonus::setDel() { del = true; }

void Bonus::act(Player& player) {
	switch (type) {
	case MEDKIT:
		player.HP_UP(50);
		break;
	case SPEED_BOOST:
		player.Speed_Boost();
		break;
	}
}
