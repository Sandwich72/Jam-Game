#include "MotivationBar.h"

MotivationBar::MotivationBar()
{
	sprite[0].loadFromFile("gfx/MotBar.png", sf::IntRect(0, 0, 128, 16));
	sprite[1].loadFromFile("gfx/MotBar.png", sf::IntRect(0, 16, 128, 16));
	setTexture(&sprite[0]);
	setSize({ 128, 32 });
	bar.setTexture(&sprite[1]);
	bar.setSize(getSize());
	motMax = 32;
	motivation = motMax;
}

MotivationBar::~MotivationBar()
{
}

void MotivationBar::setMot(int nMot)
{
	motivation -= nMot;
	bar.setSize({128.f * (motivation / motMax), 16});
}



