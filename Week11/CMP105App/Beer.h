#pragma once
#include "framework/GameObject.h"
#include "framework/Animation.h".
#include"Money.h"
#include "Patron.h"
class Beer : public GameObject
{
public:
	Beer(int nLane, Money* nMoney);
	~Beer();

	bool getIsDrank();
	int getLane();
	void update(float dt);
	void collisionResponse(GameObject* collider);


protected:
	sf::Texture sprite;
	bool isDrank;
	Money* money;
	int lane;

};

