#include "Lane.h"

#include<iostream>
Lane::Lane()
{
	sprite.loadFromFile("gfx/bar.png");
	setSize({ 128, 512 });
	patOnScreen = nullptr;
	setTexture(&sprite);
}

Lane::Lane(int pos,std::vector<Patron*>* nOnScreen, std::vector<Beer*>* nBeerVec, int* nPatSpawned, int* nDay)
{
	sprite.loadFromFile("gfx/bar.png");
	setTexture(&sprite);
	setSize({ 512, 64 });
	setCollisionBox(0, 0, 32, 64);
	setPosition(100, 100 * (pos + 1));
	endBar = sf::IntRect(getPosition().x + getSize().x - 32, getPosition().y, 32, 32);


	patOnScreen = nOnScreen;
	beerVec = nBeerVec;
	canSpawn = true;
	laneNum = pos;
	patSpawned = nPatSpawned;
	spawnChance = 2;
	day = nDay;

}

Lane::~Lane()
{
}

sf::IntRect Lane::getEndBar()
{
	return endBar;
}

void Lane::newWave()
{
	patSpawned = 0;
	spawnChance+=*day;
}

void Lane::spawn()
{
	if (!(*patSpawned == maxPat[*day]))
	{
		if (patOnScreen->size() < maxPat[*day]/2)
		{
			if (rand() % 1000 < spawnChance)
			{
				*patSpawned = *patSpawned+1;
				std::cout << *patSpawned<<std::endl;
				patOnScreen->push_back(new Patron(this, laneNum));
				spawnTimer.restart();
			}
		}
	}
}

void Lane::update(float dt)
{
	if (spawnTimer.getElapsedTime().asSeconds() > .5)
	{
		spawn();
	}



}


