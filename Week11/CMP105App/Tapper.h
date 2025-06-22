#pragma once
#include "framework/GameObject.h"
#include"Lane.h"
#include "Beer.h"
#include"Framework/Collision.h"
#include"Money.h"
#include "framework/Animation.h"

class Tapper : public GameObject
{
public: 
	Tapper();
	Tapper(std::vector <Lane*>* nLane, std::vector<Beer*>* nBeerVec, Money* nMoney);
	~Tapper();

	virtual void pour();

	void handleInput(float dt);
	void update(float dt);
	void collisionResponse(GameObject* collider);
	sf::RectangleShape getBeer();

	//void addLanes(std::vector <Lane*>* nLane);
	
protected:
	sf::Texture sprite[3];
	std::vector <Lane*>* lane;
	std::vector<Beer*>* beerVec;
	float pourSpeed;
	bool isHeld;
	bool isPouring;
	bool isFull;
	sf::Clock timer;
	sf::Clock pourTimer;
	int currentLane;
	Money* money;
	sf::RectangleShape beer;
	sf::Texture beerSprite;
	Animation beerAnim;
};

