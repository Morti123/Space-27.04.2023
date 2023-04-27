#pragma once
#include"settings.h"
#include<iostream>

class GameObj {
protected:
	GameObj(){
		std::cout << "GameObj construct" << std::endl;
	}
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	sf::Vector2f getPosition() { return sprite.getPosition(); }
	
	sf::Texture texture;
	sf::Sprite sprite;
};
