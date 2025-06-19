#pragma once
#include "framework/GameObject.h"
#include "framework/Animation.h"
class Beer : public GameObject
{
public:
	Beer(int* nMoney);
	~Beer();

	bool getIsDrank();
	void update(float dt);
	void collisionResponse(GameObject* collider);


protected:
	sf::Texture sprite;
	bool isDrank;
	int* money;

};

