#pragma once
#include "Framework/GameObject.h"
#include"Patron.h"
#include"Beer.h"
class Lane : public GameObject
{
public:
	Lane();
	Lane(std::vector<Patron*>* nOnScreen, std::vector<Beer*>* nBeerVec);
	~Lane();
	void update(float dt);
protected:
	sf::Texture sprite;
	std::vector <Patron*>* patOnScreen;
	std::vector<Beer*>* beerVec;
	sf::Clock spawnTimer;
};

