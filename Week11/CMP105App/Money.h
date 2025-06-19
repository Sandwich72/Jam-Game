#pragma once
#include "Clickable.h"
class Money : public Clickable
{
public:
	Money();
	Money(sf::RenderWindow* nWindow,sf::Font* font);
	~Money();
	void update(float dt);
	void addMoney(int nCash);
	int getMoney();
protected:
	int cash;
};

