#pragma once
#include"Clickable.h"
class PassTimes : public Clickable
{
public:


	PassTimes(sf::RenderWindow* nWindow, sf::Font* font, int type);
	~PassTimes();

	void update(float dt);
private:
	enum  Stuff
	{
		BED,
		BOOK,
		GAME,
		COOK,
		BATH,
		POOP,
		TV,
		WORK,

	};
};

