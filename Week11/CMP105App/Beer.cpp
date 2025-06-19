#include "Beer.h"
#include<iostream>
Beer::Beer(int* nMoney)
{
	sprite.loadFromFile("gfx/Beer.png", sf::IntRect(384, 0, 64, 64));
	setTexture(&sprite);
	setSize({ 64, 64 });
	setCollisionBox(0, 0, 32, 32);
	setScale(.5, .5);
	isDrank = false;
	money = nMoney;
}

Beer::~Beer()
{
}

bool Beer::getIsDrank()
{
	return isDrank;
}

void Beer::update(float dt)
{
	move(dt * 100,0);

}

void Beer::collisionResponse(GameObject* collider)
{
	std::cout << "BALLS\n";
	money += 5;
	isDrank = true;

}
