#pragma once
#include "Framework/GameObject.h"
#include"Patron.h"
#include"Beer.h"
class Lane : public GameObject
{
public:
	Lane();
	Lane(int pos, std::vector<Patron*>* nOnScreen, std::vector<Beer*>* nBeerVec, int* nPatSpawned, int* nDay);
	//Lane(int pos, std::vector<Patron*>* nOnScreen, std::vector<Beer*>* nBeerVec, int* nMaxPat, int* nPatSpawned);
	//Lane(int pos, std::vector<Patron*>* nOnScreen, std::vector<Beer*>* nBeerVec, int*nMaxPat);
	//Lane(std::vector<Patron*>* nOnScreen, std::vector<Beer*>* nBeerVec);
	~Lane();
	sf::IntRect getEndBar();
	void newWave();
	void spawn();
	void update(float dt);

protected:
	int* patSpawned;
	int maxPat[14] = { 5,8,6,3,10,15,30,8, 12, 6, 12, 20, 35, 90 };
	int* day;
	bool canSpawn;
	int laneNum;
	int spawnChance;
	sf::Texture sprite;
	std::vector <Patron*>* patOnScreen;
	std::vector<Beer*>* beerVec;
	sf::Clock spawnTimer;
	sf::IntRect endBar;
};

