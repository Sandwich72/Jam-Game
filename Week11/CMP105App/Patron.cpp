#include "Patron.h"



Patron::Patron()
{
	sprite.loadFromFile("gfx/Patron.png");
	setTexture(&sprite);
	setSize({ 128,128 });
	setScale(.6, .6);
	parent = nullptr;
}

Patron::Patron(GameObject* nParent)
{
	sprite.loadFromFile("gfx/Patron.png");
	setTexture(&sprite);
	setSize({ 128,128 });
	setScale(.6, .6);
	setCollisionBox(0, 0, 32, 64);
	satisfied = false;
	parent = nParent;
	moveSpeed = 50;
	setPosition(nParent->getPosition().x + nParent->getSize().x, nParent->getPosition().y /*+ (nParent->getLocalBounds().height / 10)*/);
}

Patron::~Patron()
{
}

void Patron::update(float dt)
{
	move(dt * -1*moveSpeed,0);
	if (Collision::checkBoundingBox(this, parent))
	{

		satisfied=true;
	}


}

bool Patron::getSatisfied()
{
	return satisfied;
}

void Patron::collisionResponse(GameObject* collider)
{
	satisfied = true;
}
