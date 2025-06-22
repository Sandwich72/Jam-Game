#include "PassTimes.h"
#include<string>
PassTimes::PassTimes(sf::RenderWindow* nWindow, sf::Font* font, int type)
{
	window = nullptr;
	isMouseOver = false;

	for (size_t i = 0; i < 3; i++)
	{
		sprite[i].loadFromFile("gfx/PlaySheet.png", sf::IntRect(0, 0, 0, 0));
	}

	setTexture(&sprite[UP]);
	setSize({ 32,32 });
	setCollisionBox(0, 0, getSize().x, getSize().y);
	setCollider(true);
	setOrigin(getSize().x / 2, getSize().y / 2);

	switch (type)
	{
	case  BED:
		setPosition(200, 140);
		break;

	default:
		break;
	}

	std::string label[8] = { "sleep","read","game","cook", "bathe","poop","tv","work" };
	text.setString(label[type]);
	text.setPosition(getPosition().x-getSize().x, getPosition().y - getSize().y);
	text.setFont(*font);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);
	text.setCharacterSize(20);
}

PassTimes::~PassTimes()
{
	
}

void PassTimes::update(float dt)
{
	if(isMouseOver)
	{
		setFillColor(sf::Color(255, 255, 255, 128));
		text.setOutlineColor(sf::Color::Black);
		text.setFillColor(sf::Color::White);
	}
	else
	{
		setFillColor(sf::Color::Transparent);
		text.setOutlineColor(sf::Color::Transparent);
		text.setFillColor(sf::Color::Transparent);
	}
}
