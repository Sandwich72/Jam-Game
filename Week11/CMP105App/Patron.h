#pragma once
#include"Framework/GameObject.h"
#include "Framework/Collision.h"
class Patron : public GameObject
{
public:
	Patron();
	Patron(GameObject* nParent,int nLane);
	~Patron();
	void update(float dt);
	bool getSatisfied();
	int getLane();
	virtual void collisionResponse(GameObject* collider);
protected:
	sf::Texture sprite;
	GameObject* parent;
	bool satisfied;
	float moveSpeed;
	int lane;
};

