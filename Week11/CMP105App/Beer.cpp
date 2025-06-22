#include "Beer.h"
#include<iostream>
Beer::Beer(int nLane, Money* nMoney)
{
	sprite.loadFromFile("gfx/Beer.png", sf::IntRect(384, 0, 64, 64));
	setTexture(&sprite);
	setSize({ 64, 64 });
	setCollisionBox(0, 0, 32, 32);
	setScale(.5, .5);
	isDrank = false;
	money = nMoney;
	lane = nLane;
}

Beer::~Beer()
{
}

bool Beer::getIsDrank()
{
	return isDrank;
}

int Beer::getLane()
{
	return lane;
}

void Beer::update(float dt)
{
	move(dt * 100,0);

}

void Beer::collisionResponse(GameObject* collider)
{
	if (dynamic_cast<Patron*> (collider))
	{
		money->addMoney(5);
		
	}
	else
	{
		money->addMoney(-2);
	}
	isDrank = true;
}
