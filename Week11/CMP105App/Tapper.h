#pragma once
#include "framework/GameObject.h"
#include"Lane.h"
#include "Beer.h"
#include"Framework/Collision.h"
class Tapper : public GameObject
{
public: 
	Tapper();
	Tapper(std::vector <Lane*>* nLane, std::vector<Beer*>* nBeerVec, int* nMoney);
	~Tapper();

	virtual void pour();

	void handleInput(float dt);
	void update(float dt);
	void collisionResponse(GameObject* collider);

	//void addLanes(std::vector <Lane*>* nLane);
	
protected:
	sf::Texture sprite[3];
	std::vector <Lane*>* lane;
	std::vector<Beer*>* beerVec;
	bool isHeld;
	bool isPouring;
	bool isFull;
	sf::Clock timer;
	int currentLane;
	int* money;

};

