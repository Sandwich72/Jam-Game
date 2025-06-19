#include "Lane.h"


Lane::Lane()
{
	sprite.loadFromFile("gfx/bar.png");
	setSize({ 128, 512 });
	patOnScreen = nullptr;
	setTexture(&sprite);
}

Lane::Lane(std::vector<Patron*>* nOnScreen, std::vector<Beer*>* nBeerVec)
{
	sprite.loadFromFile("gfx/bar.png");
	setTexture(&sprite);
	setSize({ 512, 64 });
	patOnScreen = nOnScreen;
	beerVec = nBeerVec;
	setCollisionBox(0, 0, 32, 64);
}

Lane::~Lane()
{
}

void Lane::update(float dt)
{
	if (spawnTimer.getElapsedTime().asSeconds() > .5)
	{
		if (patOnScreen->size() < 10)
		{
			if(rand()%1000<2)
			{
				patOnScreen->push_back(new Patron(this));
				spawnTimer.restart();
			}
		}
	}



}
